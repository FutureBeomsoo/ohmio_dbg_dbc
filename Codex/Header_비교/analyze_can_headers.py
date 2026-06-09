#!/usr/bin/env python3
from __future__ import annotations

import difflib
import hashlib
import itertools
import re
from datetime import datetime
from pathlib import Path


BASE = Path(__file__).resolve().parents[2]
OUT = BASE / "Codex" / "Header_비교"

ROOTS = [
    ("OhmioLibraries", BASE / "OhmioLibraries" / "include" / "canbus"),
    ("OhmioLibraries_36", BASE / "OhmioLibraries_36" / "include" / "canbus"),
    ("Ohmio_lib_include", BASE / "OhmioLibraries_36" / "Ohmio_lib_include" / "include" / "canbus"),
    ("OhmioLibraries_BK", BASE / "OhmioLibraries_BK" / "include" / "canbus"),
]

FILES = [
    "additionalDbcCan.h",
    "dbc_CAN_peripheral.h",
    "dbc_CAN.h",
    "Security_CAN.h",
    "dbc_MsgID_main.h",
    "dbc_MsgID_peripheral.h",
    "dbc_MsgID_security.h",
    "ConversionHelper.h",
]

MSG_RE = re.compile(r"//\s*message\s+ID\s+(0x[0-9A-Fa-f]+|\d+)\s+(.+?)\s*$")
INCLUDE_RE = re.compile(r"^\s*#\s*include\s+(.+?)\s*$")
DEFINE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)\s*(.*?)\s*(?://.*)?$")
ENUM_START_RE = re.compile(r"^\s*(typedef\s+)?enum(?:\s+([A-Za-z_]\w*))?\b")
STRUCT_START_RE = re.compile(r"^\s*typedef\s+struct\b")
STRUCT_END_RE = re.compile(r"^\s*}\s*([A-Za-z_]\w*_t)\s*;\s*$")
BITFIELD_RE = re.compile(
    r"^\s*([A-Za-z_]\w*)\s+([A-Za-z_]\w*)\s*:\s*(\d+)\s*;\s*(?://\s*(.*?))?\s*$"
)
BUF_RE = re.compile(r"uint8_t\s+buf\s*\[\s*(\d+)\s*\]")
MEMBER_RE = re.compile(
    r"^\s*((?:u?int(?:8|16|32|64)_t)|double|float|bool)\s+([A-Za-z_]\w*)\s*(?:\[[^\]]+\])?\s*;\s*(?://.*)?$"
)
FUNC_RE = re.compile(
    r"^\s*((?:(?:inline|static|extern)\s+)*[A-Za-z_]\w*(?:\s*\*)?)\s+([A-Za-z_]\w*)\s*\(([^()]*)\)\s*(;|\{)?\s*$"
)


def sha(text: str) -> str:
    return hashlib.sha256(text.encode("utf-8", errors="replace")).hexdigest()


def normalize_text(text: str) -> str:
    return re.sub(r"\s+", " ", text).strip()


def strip_line_comment(line: str) -> tuple[str, str]:
    if "//" in line:
        before, after = line.split("//", 1)
        return before, after.strip()
    return line, ""


def parse_int(value: str):
    value = value.strip().rstrip(",")
    try:
        return int(value, 0)
    except ValueError:
        return value


def fmt_value(value) -> str:
    if isinstance(value, int):
        if value >= 10:
            return f"0x{value:X}"
        return str(value)
    return str(value)


def md_escape(value) -> str:
    text = "" if value is None else str(value)
    return text.replace("|", "\\|").replace("\n", " ")


def is_reserved(name: str) -> bool:
    lower = name.lower()
    return lower.startswith("reserved") or lower.startswith("unused")


def field_range(field: dict) -> str:
    if field["start"] == field["end"]:
        return f"bit{field['start']}"
    return f"bits{field['start']}-{field['end']}"


def field_sig(field: dict, include_comment: bool = False) -> tuple:
    sig = (field["type"], field["start"], field["end"], field["width"])
    if include_comment:
        sig += (field.get("comment", ""),)
    return sig


def fields_overlap(a: dict, b: dict) -> bool:
    return max(a["start"], b["start"]) <= min(a["end"], b["end"])


def overlap_range(a: dict, b: dict) -> str:
    start = max(a["start"], b["start"])
    end = min(a["end"], b["end"])
    if start == end:
        return f"bit{start}"
    return f"bits{start}-{end}"


def format_field(field: dict) -> str:
    comment = f", // {field['comment']}" if field.get("comment") else ""
    return f"{field_range(field)} {field['type']} {field['name']}:{field['width']}{comment}"


def parse_enum(lines: list[str], start: int) -> tuple[int, dict]:
    first = lines[start]
    m = ENUM_START_RE.match(first)
    enum_tag = m.group(2) if m else ""
    block: list[tuple[int, str]] = []
    depth = 0
    seen_open = False
    end = start
    for j in range(start, len(lines)):
        line = lines[j]
        if "{" in line:
            seen_open = True
        if seen_open:
            depth += line.count("{")
            depth -= line.count("}")
            block.append((j + 1, line))
            if seen_open and depth <= 0 and "}" in line:
                end = j
                break

    close_line = lines[end]
    close_name = ""
    close_match = re.search(r"}\s*([A-Za-z_]\w*)?\s*;", close_line)
    if close_match:
        close_name = close_match.group(1) or ""
    enum_name = enum_tag or close_name or f"anonymous_enum_line_{start + 1}"

    entries = {}
    current = -1
    in_block_comment = False
    for lineno, raw in block:
        line = raw
        if "/*" in line:
            in_block_comment = True
            line = line.split("/*", 1)[0]
        if in_block_comment:
            if "*/" in raw:
                in_block_comment = False
            if not line.strip():
                continue
        code, comment = strip_line_comment(line)
        code = code.strip()
        if not code or code in ("{", "};") or code.startswith("typedef") or code.startswith("enum"):
            continue
        code = code.rstrip(",")
        m_entry = re.match(r"^([A-Za-z_]\w*)\s*(?:=\s*(.+?))?$", code)
        if not m_entry:
            continue
        name = m_entry.group(1)
        raw_value = m_entry.group(2)
        explicit = raw_value is not None
        if explicit:
            value = parse_int(raw_value)
            current = value if isinstance(value, int) else current
        else:
            current = current + 1 if isinstance(current, int) else current
            value = current
        entries[name] = {
            "name": name,
            "value": value,
            "explicit": explicit,
            "comment": comment,
            "line": lineno,
        }

    return end, {"name": enum_name, "line": start + 1, "entries": entries}


def parse_struct(lines: list[str], start: int, pending_msgs: list[dict]) -> tuple[int, dict]:
    block: list[tuple[int, str]] = []
    end = start
    for j in range(start, len(lines)):
        block.append((j + 1, lines[j]))
        if STRUCT_END_RE.match(lines[j]):
            end = j
            break

    struct_name = "unknown_struct"
    m_end = STRUCT_END_RE.match(lines[end])
    if m_end:
        struct_name = m_end.group(1)

    buf_size = None
    fields = []
    physical_members = []
    bit_pos = 0
    raw_done = False
    for lineno, line in block:
        m_buf = BUF_RE.search(line)
        if m_buf:
            buf_size = int(m_buf.group(1))
        m_field = BITFIELD_RE.match(line)
        if m_field:
            field_type, name, width_text, comment = m_field.groups()
            width = int(width_text)
            fields.append(
                {
                    "type": field_type,
                    "name": name,
                    "width": width,
                    "start": bit_pos,
                    "end": bit_pos + width - 1,
                    "comment": comment or "",
                    "line": lineno,
                    "reserved": is_reserved(name),
                }
            )
            bit_pos += width
        if re.search(r"}\s*raw\s*;", line):
            raw_done = True
            continue
        if raw_done:
            m_member = MEMBER_RE.match(line)
            if m_member:
                member_type, member_name = m_member.groups()
                physical_members.append(
                    {"type": member_type, "name": member_name, "line": lineno}
                )

    return end, {
        "name": struct_name,
        "line": start + 1,
        "message_ids": list(pending_msgs),
        "buf_size": buf_size,
        "fields": fields,
        "physical_members": physical_members,
        "total_bits": bit_pos,
    }


def parse_function(lines: list[str], start: int) -> tuple[int, dict] | None:
    line = lines[start]
    stripped = line.strip()
    if not stripped or stripped.startswith(("#", "//")):
        return None
    m = FUNC_RE.match(line)
    if not m:
        return None
    ret_type, name, params, terminator = m.groups()
    if name in {"if", "for", "while", "switch", "return", "assert"}:
        return None

    kind = "prototype"
    end = start
    body_hash = ""
    if terminator == ";":
        kind = "prototype"
    else:
        brace_line = start
        if terminator != "{":
            brace_line = start + 1
            while brace_line < len(lines) and not lines[brace_line].strip():
                brace_line += 1
        if brace_line < len(lines) and "{" in lines[brace_line]:
            kind = "definition"
            depth = 0
            for j in range(start, len(lines)):
                depth += lines[j].count("{")
                depth -= lines[j].count("}")
                if j >= brace_line and depth == 0:
                    end = j
                    break
            body = "\n".join(lines[start : end + 1])
            body_hash = sha(normalize_text(body))
        else:
            return None

    storage = " ".join(x for x in ["inline" if "inline" in ret_type.split() else "", "static" if "static" in ret_type.split() else "", "extern" if "extern" in ret_type.split() else ""] if x)
    clean_ret = " ".join(x for x in ret_type.split() if x not in {"inline", "static", "extern"})
    params_norm = normalize_text(params)
    return end, {
        "name": name,
        "line": start + 1,
        "return": clean_ret,
        "storage": storage,
        "params": params_norm,
        "kind": kind,
        "body_hash": body_hash,
        "signature": f"{clean_ret} {name}({params_norm})",
    }


def parse_header(path: Path) -> dict:
    text = path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    data = {
        "path": path,
        "exists": True,
        "text": text,
        "line_count": len(lines),
        "sha": sha(text),
        "norm_sha": sha(normalize_text(text)),
        "includes": [],
        "macros": {},
        "enums": {},
        "can_ids": {},
        "structs": {},
        "functions": {},
        "parse_warnings": [],
    }
    pending_msgs: list[dict] = []
    pending_stale = False

    i = 0
    while i < len(lines):
        line = lines[i]
        m_msg = MSG_RE.search(line)
        if m_msg:
            if pending_stale:
                pending_msgs = []
            value = parse_int(m_msg.group(1))
            pending_msgs.append(
                {
                    "id_text": m_msg.group(1),
                    "id": value,
                    "name": m_msg.group(2).strip(),
                    "line": i + 1,
                }
            )
            pending_stale = False
            i += 1
            continue

        m_include = INCLUDE_RE.match(line)
        if m_include:
            data["includes"].append({"value": m_include.group(1).strip(), "line": i + 1})
            pending_stale = True
            i += 1
            continue

        m_define = DEFINE_RE.match(line)
        if m_define:
            name, value = m_define.groups()
            data["macros"][name] = {"value": normalize_text(value), "line": i + 1}
            pending_stale = True
            i += 1
            continue

        if ENUM_START_RE.match(line):
            end, enum = parse_enum(lines, i)
            data["enums"][enum["name"]] = enum
            for entry in enum["entries"].values():
                if entry["name"].startswith("CAN_ID_"):
                    data["can_ids"][entry["name"]] = {
                        **entry,
                        "enum": enum["name"],
                    }
            i = end + 1
            continue

        if STRUCT_START_RE.match(line):
            end, struct = parse_struct(lines, i, pending_msgs)
            data["structs"][struct["name"]] = struct
            pending_msgs = []
            pending_stale = True
            i = end + 1
            continue

        parsed_func = parse_function(lines, i)
        if parsed_func:
            end, func = parsed_func
            data["functions"][func["name"]] = func
            pending_stale = True
            i = end + 1
            continue

        if line.strip() and not line.strip().startswith("//"):
            pending_stale = True
        i += 1

    return data


def missing_header(path: Path) -> dict:
    return {
        "path": path,
        "exists": False,
        "text": "",
        "line_count": 0,
        "sha": "",
        "norm_sha": "",
        "includes": [],
        "macros": {},
        "enums": {},
        "can_ids": {},
        "structs": {},
        "functions": {},
        "parse_warnings": [f"missing file: {path}"],
    }


def list_diff(a_items, b_items):
    a_set = set(a_items)
    b_set = set(b_items)
    return sorted(a_set - b_set), sorted(b_set - a_set), sorted(a_set & b_set)


def table(headers: list[str], rows: list[list[str]], empty: str = "없음") -> list[str]:
    if not rows:
        return [empty]
    out = [
        "| " + " | ".join(headers) + " |",
        "| " + " | ".join(["---"] * len(headers)) + " |",
    ]
    for row in rows:
        out.append("| " + " | ".join(md_escape(cell) for cell in row) + " |")
    return out


def compare_fields(a: dict, b: dict, label_a: str, label_b: str) -> tuple[list[str], dict]:
    rows_changed = []
    rows_only_a = []
    rows_only_b = []
    rows_reserved = []
    rows_conflict = []

    fields_a = {f["name"]: f for f in a["fields"]}
    fields_b = {f["name"]: f for f in b["fields"]}
    only_a, only_b, common = list_diff(fields_a, fields_b)

    for name in common:
        fa = fields_a[name]
        fb = fields_b[name]
        if field_sig(fa, include_comment=True) != field_sig(fb, include_comment=True):
            rows_changed.append(
                [
                    name,
                    format_field(fa),
                    format_field(fb),
                    "bit/type/unit 변경",
                ]
            )

    for name in only_a:
        fa = fields_a[name]
        overlaps = [fb for fb in b["fields"] if fields_overlap(fa, fb)]
        overlap_text = ", ".join(format_field(x) for x in overlaps) or "-"
        rows_only_a.append([name, format_field(fa), overlap_text])
    for name in only_b:
        fb = fields_b[name]
        overlaps = [fa for fa in a["fields"] if fields_overlap(fa, fb)]
        overlap_text = ", ".join(format_field(x) for x in overlaps) or "-"
        rows_only_b.append([name, format_field(fb), overlap_text])

    seen_pairs = set()
    for fa in a["fields"]:
        for fb in b["fields"]:
            if not fields_overlap(fa, fb):
                continue
            if fa["name"] == fb["name"] and field_sig(fa) == field_sig(fb):
                continue
            key = (fa["name"], fa["start"], fa["end"], fb["name"], fb["start"], fb["end"])
            if key in seen_pairs:
                continue
            seen_pairs.add(key)
            if fa["reserved"] != fb["reserved"]:
                rows_reserved.append(
                    [
                        overlap_range(fa, fb),
                        format_field(fa),
                        format_field(fb),
                        f"Reserved 대체 후보: {label_a if fa['reserved'] else label_b} reserved",
                    ]
                )
            elif not fa["reserved"] and not fb["reserved"]:
                rows_conflict.append(
                    [
                        overlap_range(fa, fb),
                        format_field(fa),
                        format_field(fb),
                        "동일 bit 영역의 non-reserved 정의 불일치",
                    ]
                )

    lines = []
    stats = {
        "changed": len(rows_changed),
        "only_a": len(rows_only_a),
        "only_b": len(rows_only_b),
        "reserved": len(rows_reserved),
        "conflict": len(rows_conflict),
    }
    if rows_changed:
        lines.append("동일 Signal 이름의 정의 변경:")
        lines.extend(table(["Signal", label_a, label_b, "판정"], rows_changed))
    if rows_only_a:
        lines.append(f"{label_a}에만 있는 Signal:")
        lines.extend(table(["Signal", "정의", f"{label_b} 겹침 영역"], rows_only_a))
    if rows_only_b:
        lines.append(f"{label_b}에만 있는 Signal:")
        lines.extend(table(["Signal", "정의", f"{label_a} 겹침 영역"], rows_only_b))
    if rows_reserved:
        lines.append("Reserved 대체 후보:")
        lines.extend(table(["범위", label_a, label_b, "판정"], rows_reserved))
    if rows_conflict:
        lines.append("비트 범위 충돌:")
        lines.extend(table(["겹침", label_a, label_b, "판정"], rows_conflict))
    return lines, stats


def compare_structs(a_data: dict, b_data: dict, label_a: str, label_b: str) -> tuple[list[str], dict, list[str]]:
    structs_a = a_data["structs"]
    structs_b = b_data["structs"]
    only_a, only_b, common = list_diff(structs_a, structs_b)
    lines = []
    checks = []
    stats = {
        "added": len(only_b),
        "removed": len(only_a),
        "changed": 0,
        "field_conflicts": 0,
        "reserved_candidates": 0,
        "field_one_side": 0,
    }

    lines.append("### Struct/Message 비교")
    if only_a:
        lines.append(f"{label_a}에만 있는 struct:")
        lines.extend(table(["Struct", "message ID", "bit 수"], [[name, msg_list(structs_a[name]), str(structs_a[name]["total_bits"])] for name in only_a]))
    if only_b:
        lines.append(f"{label_b}에만 있는 struct:")
        lines.extend(table(["Struct", "message ID", "bit 수"], [[name, msg_list(structs_b[name]), str(structs_b[name]["total_bits"])] for name in only_b]))
    if not only_a and not only_b:
        lines.append("양쪽 struct 목록은 동일합니다.")

    changed_sections = []
    changed_struct_count = 0
    for name in common:
        sa = structs_a[name]
        sb = structs_b[name]
        local = []
        local_stats = {"changed": 0, "conflict": 0, "reserved": 0, "one_side": 0}
        if sa["buf_size"] != sb["buf_size"]:
            local.append(f"- raw buffer 크기 변경: {label_a}={sa['buf_size']}, {label_b}={sb['buf_size']}")
            local_stats["changed"] += 1
        if ids_key(sa) != ids_key(sb):
            local.append(f"- message ID 주석 변경: {label_a}={msg_list(sa)}, {label_b}={msg_list(sb)}")
            local_stats["changed"] += 1
        if sa["total_bits"] != sb["total_bits"]:
            local.append(f"- Signal 총 bit 수 변경: {label_a}={sa['total_bits']}, {label_b}={sb['total_bits']}")
            local_stats["changed"] += 1

        field_lines, field_stats = compare_fields(sa, sb, label_a, label_b)
        if field_lines:
            local.extend(field_lines)
            local_stats["changed"] += field_stats["changed"]
            local_stats["conflict"] += field_stats["conflict"]
            local_stats["reserved"] += field_stats["reserved"]
            local_stats["one_side"] += field_stats["only_a"] + field_stats["only_b"]

        members_a = {m["name"]: m for m in sa["physical_members"]}
        members_b = {m["name"]: m for m in sb["physical_members"]}
        mem_only_a, mem_only_b, mem_common = list_diff(members_a, members_b)
        mem_changed = [
            name2
            for name2 in mem_common
            if members_a[name2]["type"] != members_b[name2]["type"]
        ]
        if mem_only_a or mem_only_b or mem_changed:
            local.append("물리/편의 member 차이:")
            rows = []
            for name2 in mem_only_a:
                rows.append([name2, f"{members_a[name2]['type']} {name2}", "-"])
            for name2 in mem_only_b:
                rows.append([name2, "-", f"{members_b[name2]['type']} {name2}"])
            for name2 in mem_changed:
                rows.append([name2, members_a[name2]["type"], members_b[name2]["type"]])
            local.extend(table(["member", label_a, label_b], rows))
            local_stats["changed"] += len(rows)

        if local:
            changed_struct_count += 1
            stats["changed"] += 1
            stats["field_conflicts"] += local_stats["conflict"]
            stats["reserved_candidates"] += local_stats["reserved"]
            stats["field_one_side"] += local_stats["one_side"]
            changed_sections.append(f"#### {name}")
            changed_sections.extend(local)
            if local_stats["conflict"]:
                checks.append(f"{name}: non-reserved bit 범위 충돌 {local_stats['conflict']}건")
            if local_stats["reserved"]:
                checks.append(f"{name}: Reserved 대체 후보 {local_stats['reserved']}건")

    if changed_sections:
        lines.append(f"변경된 공통 struct: {changed_struct_count}개")
        lines.extend(changed_sections)
    else:
        lines.append("공통 struct의 Signal layout 차이는 없습니다.")
    return lines, stats, checks


def msg_list(struct: dict) -> str:
    if not struct.get("message_ids"):
        return "-"
    return ", ".join(f"{fmt_value(m['id'])} {m['name']}" for m in struct["message_ids"])


def ids_key(struct: dict) -> tuple:
    return tuple((m["id"], m["name"]) for m in struct.get("message_ids", []))


def compare_can_ids(a_data: dict, b_data: dict, label_a: str, label_b: str) -> tuple[list[str], dict, list[str]]:
    ids_a = a_data["can_ids"]
    ids_b = b_data["can_ids"]
    only_a, only_b, common = list_diff(ids_a, ids_b)
    value_to_names_a = {}
    value_to_names_b = {}
    for name, item in ids_a.items():
        value_to_names_a.setdefault(item["value"], []).append(name)
    for name, item in ids_b.items():
        value_to_names_b.setdefault(item["value"], []).append(name)

    changed_value = []
    changed_comment = []
    for name in common:
        if ids_a[name]["value"] != ids_b[name]["value"]:
            changed_value.append([name, fmt_value(ids_a[name]["value"]), fmt_value(ids_b[name]["value"])])
        elif normalize_text(ids_a[name].get("comment", "")) != normalize_text(ids_b[name].get("comment", "")):
            changed_comment.append([name, fmt_value(ids_a[name]["value"]), ids_a[name].get("comment", ""), ids_b[name].get("comment", "")])

    value_conflicts = []
    for value in sorted(set(value_to_names_a) & set(value_to_names_b), key=lambda x: (isinstance(x, str), x)):
        names_a = sorted(value_to_names_a[value])
        names_b = sorted(value_to_names_b[value])
        if names_a != names_b:
            value_conflicts.append([fmt_value(value), ", ".join(names_a), ", ".join(names_b)])

    lines = ["### CAN ID enum 비교"]
    stats = {
        "only_a": len(only_a),
        "only_b": len(only_b),
        "changed_value": len(changed_value),
        "changed_comment": len(changed_comment),
        "value_conflicts": len(value_conflicts),
    }
    checks = []
    if not ids_a and not ids_b:
        lines.append("CAN_ID enum 항목이 없습니다.")
        return lines, stats, checks
    if only_a:
        lines.append(f"{label_a}에만 있는 CAN_ID:")
        lines.extend(table(["Name", "Value", "Comment"], [[name, fmt_value(ids_a[name]["value"]), ids_a[name].get("comment", "")] for name in only_a]))
    if only_b:
        lines.append(f"{label_b}에만 있는 CAN_ID:")
        lines.extend(table(["Name", "Value", "Comment"], [[name, fmt_value(ids_b[name]["value"]), ids_b[name].get("comment", "")] for name in only_b]))
    if changed_value:
        lines.append("동일 CAN_ID 이름의 값 변경:")
        lines.extend(table(["Name", label_a, label_b], changed_value))
        checks.extend(f"{row[0]} 값 변경: {row[1]} -> {row[2]}" for row in changed_value)
    if value_conflicts:
        lines.append("동일 numeric ID의 symbolic name 불일치:")
        lines.extend(table(["Value", label_a, label_b], value_conflicts))
        checks.extend(f"{row[0]} symbolic name 불일치" for row in value_conflicts)
    if changed_comment:
        lines.append("동일 CAN_ID 이름/값의 주석 정의 변경:")
        lines.extend(table(["Name", "Value", label_a, label_b], changed_comment))
    if not (only_a or only_b or changed_value or changed_comment or value_conflicts):
        lines.append("CAN_ID enum 항목 차이는 없습니다.")
    return lines, stats, checks


def compare_enums(a_data: dict, b_data: dict, label_a: str, label_b: str) -> tuple[list[str], dict, list[str]]:
    enums_a = {k: v for k, v in a_data["enums"].items() if not mostly_can_ids(v)}
    enums_b = {k: v for k, v in b_data["enums"].items() if not mostly_can_ids(v)}
    only_a, only_b, common = list_diff(enums_a, enums_b)
    lines = ["### 일반 enum 비교"]
    stats = {"only_a": len(only_a), "only_b": len(only_b), "changed": 0, "value_changed": 0}
    checks = []
    if only_a:
        lines.append(f"{label_a}에만 있는 enum:")
        lines.extend(table(["Enum", "entry 수"], [[name, str(len(enums_a[name]["entries"]))] for name in only_a]))
    if only_b:
        lines.append(f"{label_b}에만 있는 enum:")
        lines.extend(table(["Enum", "entry 수"], [[name, str(len(enums_b[name]["entries"]))] for name in only_b]))

    sections = []
    for name in common:
        ea = enums_a[name]["entries"]
        eb = enums_b[name]["entries"]
        only_entries_a, only_entries_b, common_entries = list_diff(ea, eb)
        value_changed = [
            [entry, fmt_value(ea[entry]["value"]), fmt_value(eb[entry]["value"])]
            for entry in common_entries
            if ea[entry]["value"] != eb[entry]["value"]
        ]
        if only_entries_a or only_entries_b or value_changed:
            stats["changed"] += 1
            stats["value_changed"] += len(value_changed)
            sections.append(f"#### {name}")
            if only_entries_a:
                sections.append(f"{label_a}에만 있는 entry:")
                sections.extend(table(["Entry", "Value"], [[entry, fmt_value(ea[entry]["value"])] for entry in only_entries_a]))
            if only_entries_b:
                sections.append(f"{label_b}에만 있는 entry:")
                sections.extend(table(["Entry", "Value"], [[entry, fmt_value(eb[entry]["value"])] for entry in only_entries_b]))
            if value_changed:
                sections.append("동일 entry 이름의 값 변경:")
                sections.extend(table(["Entry", label_a, label_b], value_changed))
                checks.extend(f"{name}.{row[0]} 값 변경: {row[1]} -> {row[2]}" for row in value_changed)
    if sections:
        lines.extend(sections)
    elif not (only_a or only_b):
        lines.append("일반 enum 차이는 없습니다.")
    return lines, stats, checks


def mostly_can_ids(enum: dict) -> bool:
    entries = list(enum["entries"])
    if not entries:
        return False
    can_count = sum(1 for name in entries if name.startswith("CAN_ID_"))
    return can_count >= max(1, len(entries) // 2)


def compare_macros_includes(a_data: dict, b_data: dict, label_a: str, label_b: str) -> tuple[list[str], dict, list[str]]:
    lines = ["### 전처리/Include 비교"]
    checks = []
    inc_a = [x["value"] for x in a_data["includes"]]
    inc_b = [x["value"] for x in b_data["includes"]]
    inc_only_a, inc_only_b, _ = list_diff(inc_a, inc_b)
    macro_a = a_data["macros"]
    macro_b = b_data["macros"]
    macro_only_a, macro_only_b, macro_common = list_diff(macro_a, macro_b)
    macro_changed = [
        [name, macro_a[name]["value"], macro_b[name]["value"]]
        for name in macro_common
        if macro_a[name]["value"] != macro_b[name]["value"]
    ]
    stats = {
        "inc_only_a": len(inc_only_a),
        "inc_only_b": len(inc_only_b),
        "macro_only_a": len(macro_only_a),
        "macro_only_b": len(macro_only_b),
        "macro_changed": len(macro_changed),
    }
    if inc_only_a or inc_only_b:
        lines.append("Include 차이:")
        rows = [[x, label_a, ""] for x in inc_only_a] + [[x, "", label_b] for x in inc_only_b]
        lines.extend(table(["Include", label_a, label_b], rows))
    if macro_only_a:
        lines.append(f"{label_a}에만 있는 macro:")
        lines.extend(table(["Macro", "Value"], [[name, macro_a[name]["value"]] for name in macro_only_a]))
    if macro_only_b:
        lines.append(f"{label_b}에만 있는 macro:")
        lines.extend(table(["Macro", "Value"], [[name, macro_b[name]["value"]] for name in macro_only_b]))
    if macro_changed:
        lines.append("Macro 값 변경:")
        lines.extend(table(["Macro", label_a, label_b], macro_changed))
        for row in macro_changed:
            if "VERSION" in row[0]:
                checks.append(f"{row[0]} 버전 값 변경: {row[1]} -> {row[2]}")
    if not (inc_only_a or inc_only_b or macro_only_a or macro_only_b or macro_changed):
        lines.append("include/macro 차이는 없습니다.")
    return lines, stats, checks


def compare_functions(a_data: dict, b_data: dict, label_a: str, label_b: str) -> tuple[list[str], dict, list[str]]:
    funcs_a = a_data["functions"]
    funcs_b = b_data["functions"]
    only_a, only_b, common = list_diff(funcs_a, funcs_b)
    signature_changed = []
    kind_changed = []
    body_changed = []
    for name in common:
        fa = funcs_a[name]
        fb = funcs_b[name]
        if (fa["return"], fa["params"]) != (fb["return"], fb["params"]):
            signature_changed.append([name, fa["signature"], fb["signature"]])
        elif (fa["storage"], fa["kind"]) != (fb["storage"], fb["kind"]):
            kind_changed.append([name, f"{fa['storage']} {fa['kind']}".strip(), f"{fb['storage']} {fb['kind']}".strip()])
        elif fa["kind"] == "definition" and fb["kind"] == "definition" and fa["body_hash"] != fb["body_hash"]:
            body_changed.append([name, "definition body hash 변경", "definition body hash 변경"])

    lines = ["### 함수 선언/정의 비교"]
    stats = {
        "only_a": len(only_a),
        "only_b": len(only_b),
        "signature_changed": len(signature_changed),
        "kind_changed": len(kind_changed),
        "body_changed": len(body_changed),
    }
    checks = []
    if only_a:
        lines.append(f"{label_a}에만 있는 함수:")
        lines.extend(table(["Function", "Kind", "Signature"], [[name, funcs_a[name]["kind"], funcs_a[name]["signature"]] for name in only_a]))
    if only_b:
        lines.append(f"{label_b}에만 있는 함수:")
        lines.extend(table(["Function", "Kind", "Signature"], [[name, funcs_b[name]["kind"], funcs_b[name]["signature"]] for name in only_b]))
    if signature_changed:
        lines.append("동일 함수 이름의 signature 변경:")
        lines.extend(table(["Function", label_a, label_b], signature_changed))
        checks.extend(f"{row[0]} signature 변경" for row in signature_changed)
    if kind_changed:
        lines.append("함수 선언/정의 형태 변경:")
        lines.extend(table(["Function", label_a, label_b], kind_changed))
    if body_changed:
        lines.append("동일 inline/static 함수 body 변경:")
        lines.extend(table(["Function", label_a, label_b], body_changed))
        checks.extend(f"{row[0]} 함수 body 변경" for row in body_changed)
    if not (only_a or only_b or signature_changed or kind_changed or body_changed):
        lines.append("함수 선언/정의 차이는 없습니다.")
    return lines, stats, checks


def diff_summary(a_text: str, b_text: str) -> tuple[int, int, list[str]]:
    diff = list(difflib.unified_diff(a_text.splitlines(), b_text.splitlines(), lineterm=""))
    added = sum(1 for line in diff if line.startswith("+") and not line.startswith("+++"))
    removed = sum(1 for line in diff if line.startswith("-") and not line.startswith("---"))
    hunks = [line for line in diff if line.startswith("@@")]
    return added, removed, hunks


def compare_one(label_a: str, a_data: dict, label_b: str, b_data: dict, filename: str) -> tuple[str, dict, list[str]]:
    exact_same = a_data["exists"] and b_data["exists"] and a_data["sha"] == b_data["sha"]
    normalized_same = a_data["exists"] and b_data["exists"] and a_data["norm_sha"] == b_data["norm_sha"]
    added, removed, hunks = diff_summary(a_data["text"], b_data["text"])

    lines = [
        f"# {filename} 비교 분석",
        "",
        f"- 비교 A: `{label_a}` - `{rel(a_data['path'])}`",
        f"- 비교 B: `{label_b}` - `{rel(b_data['path'])}`",
        f"- 파일 동일 여부: {'동일' if exact_same else '다름'}",
        f"- 공백 정규화 후 동일 여부: {'동일' if normalized_same else '다름'}",
        "",
        "## 요약",
    ]
    summary_rows = [
        ["Line", str(a_data["line_count"]), str(b_data["line_count"])],
        ["SHA256", a_data["sha"][:12] if a_data["sha"] else "-", b_data["sha"][:12] if b_data["sha"] else "-"],
        ["Struct", str(len(a_data["structs"])), str(len(b_data["structs"]))],
        ["Enum", str(len(a_data["enums"])), str(len(b_data["enums"]))],
        ["CAN_ID", str(len(a_data["can_ids"])), str(len(b_data["can_ids"]))],
        ["Function", str(len(a_data["functions"])), str(len(b_data["functions"]))],
        ["Unified diff", f"-{removed}", f"+{added}"],
    ]
    lines.extend(table(["항목", label_a, label_b], summary_rows))
    if hunks:
        lines.append("")
        lines.append("Diff hunk 위치:")
        for hunk in hunks[:40]:
            lines.append(f"- `{hunk}`")
        if len(hunks) > 40:
            lines.append(f"- ... 추가 {len(hunks) - 40}개 hunk")
    else:
        lines.append("")
        lines.append("Diff hunk 없음.")

    aggregate_stats = {
        "exact_same": exact_same,
        "normalized_same": normalized_same,
        "added_lines": added,
        "removed_lines": removed,
        "check_count": 0,
        "hard_conflicts": 0,
        "reserved_candidates": 0,
        "one_side": 0,
    }
    checks = []

    sections = [
        compare_macros_includes(a_data, b_data, label_a, label_b),
        compare_can_ids(a_data, b_data, label_a, label_b),
        compare_enums(a_data, b_data, label_a, label_b),
        compare_structs(a_data, b_data, label_a, label_b),
        compare_functions(a_data, b_data, label_a, label_b),
    ]
    for section_lines, section_stats, section_checks in sections:
        lines.append("")
        lines.extend(section_lines)
        checks.extend(section_checks)
        aggregate_stats["check_count"] += len(section_checks)
        aggregate_stats["hard_conflicts"] += section_stats.get("changed_value", 0)
        aggregate_stats["hard_conflicts"] += section_stats.get("value_conflicts", 0)
        aggregate_stats["hard_conflicts"] += section_stats.get("value_changed", 0)
        aggregate_stats["hard_conflicts"] += section_stats.get("field_conflicts", 0)
        aggregate_stats["hard_conflicts"] += section_stats.get("signature_changed", 0)
        aggregate_stats["hard_conflicts"] += section_stats.get("body_changed", 0)
        aggregate_stats["reserved_candidates"] += section_stats.get("reserved_candidates", 0)
        aggregate_stats["one_side"] += section_stats.get("only_a", 0) + section_stats.get("only_b", 0)
        aggregate_stats["one_side"] += section_stats.get("added", 0) + section_stats.get("removed", 0)
        aggregate_stats["one_side"] += section_stats.get("field_one_side", 0)

    if checks:
        lines.append("")
        lines.append("## 사용자 점검 후보")
        for item in checks:
            lines.append(f"- {item}")

    return "\n".join(lines).rstrip() + "\n", aggregate_stats, checks


def rel(path: Path) -> str:
    try:
        return str(path.relative_to(BASE))
    except ValueError:
        return str(path)


def write_static_docs(all_stats: list[dict], all_checks: list[dict], parse_warnings: list[str]):
    plan = """# Header_비교 예정 작업계획

## 작업 범위
- 원본 폴더: `OhmioLibraries`, `OhmioLibraries_36`, `OhmioLibraries_36/Ohmio_lib_include`, `OhmioLibraries_BK`
- 대상 파일: `additionalDbcCan.h`, `dbc_CAN_peripheral.h`, `dbc_CAN.h`, `Security_CAN.h`, `dbc_MsgID_main.h`, `dbc_MsgID_peripheral.h`, `dbc_MsgID_security.h`, `ConversionHelper.h`
- 산출물 위치: `Codex/Header_비교`

## 분석 방법
- 원본 헤더는 읽기 전용으로 유지한다.
- 4개 소스 루트의 6개 조합을 상호 비교한다.
- 파일 동일성, include/macro, CAN ID enum, 일반 enum, typedef struct Signal bit field, 함수 선언/정의를 비교한다.
- Reserved/unused 필드는 dummy bit field로 분류하고, 상대 파일의 non-reserved Signal과 겹치면 대체 후보로 별도 기록한다.

## 진행 근거
- 사용자가 `1. file 비교 분석 수행`을 명시하여 본 계획에 따라 분석을 진행했다.
"""
    (OUT / "Header_비교_예정_작업계획.md").write_text(plan, encoding="utf-8")

    summary_rows = []
    for item in all_stats:
        summary_rows.append(
            [
                item["pair"],
                item["file"],
                "동일" if item["exact_same"] else "다름",
                str(item["removed_lines"]),
                str(item["added_lines"]),
                str(item["hard_conflicts"]),
                str(item["reserved_candidates"]),
                str(item["one_side"]),
            ]
        )
    content = [
        "# Header_비교 작업내용",
        "",
        "## 전체 비교 요약",
    ]
    content.extend(
        table(
            ["비교 쌍", "파일", "동일", "삭제 line", "추가 line", "충돌", "Reserved 대체", "한쪽 전용 항목"],
            summary_rows,
        )
    )
    content.append("")
    content.append("## 주요 관찰")
    identical_36 = [
        item
        for item in all_stats
        if item["pair"] == "OhmioLibraries_36_Ohmio_lib_include" and item["exact_same"]
    ]
    content.append(f"- `OhmioLibraries_36`와 `Ohmio_lib_include`의 대상 8개 헤더는 {len(identical_36)}/8개가 byte 단위로 동일하다.")
    bk_diffs = [item for item in all_stats if "OhmioLibraries_BK" in item["pair"] and not item["exact_same"]]
    content.append(f"- `OhmioLibraries_BK`가 포함된 비교에서 차이가 있는 파일은 {len(bk_diffs)}건이다.")
    current_36_diffs = [item for item in all_stats if item["pair"] == "OhmioLibraries_OhmioLibraries_36" and not item["exact_same"]]
    content.append(f"- `OhmioLibraries`와 `OhmioLibraries_36` 간 차이가 있는 파일은 {len(current_36_diffs)}건이다.")
    (OUT / "Header_비교_작업내용.md").write_text("\n".join(content).rstrip() + "\n", encoding="utf-8")

    check_lines = ["# Header_비교 점검 필요사항", ""]
    if all_checks:
        check_lines.append("통합 단계에서 사용자 확인 또는 의사결정이 필요한 후보입니다.")
        check_rows = [[x["pair"], x["file"], x["item"]] for x in all_checks]
        check_lines.extend(table(["비교 쌍", "파일", "점검 항목"], check_rows))
    else:
        check_lines.append("사용자 점검 필요사항이 발견되지 않았습니다.")
    (OUT / "Header_비교_점검_필요사항.md").write_text("\n".join(check_lines).rstrip() + "\n", encoding="utf-8")

    error_lines = ["# Header_비교 오류사항", ""]
    if parse_warnings:
        error_lines.append("분석 중 경고:")
        for warning in parse_warnings:
            error_lines.append(f"- {warning}")
    else:
        error_lines.append("분석 실행 오류는 발견되지 않았습니다.")
    error_lines.append("")
    error_lines.append("참고: C 전처리기와 컴파일러를 실행하지 않고 header 텍스트를 구조적으로 파싱했다.")
    (OUT / "Header_비교_오류사항.md").write_text("\n".join(error_lines).rstrip() + "\n", encoding="utf-8")

    log_lines = [
        "# Header_비교 작업기록",
        "",
        f"- 생성 시각: {datetime.now().astimezone().isoformat(timespec='seconds')}",
        "- `Codex/can_headerfile_commnad.txt`의 1번 작업 지시를 확인했다.",
        "- 원본 4개 폴더에서 대상 8개 header 파일 존재 여부를 확인했다.",
        "- 구조 비교 스크립트 `Codex/Header_비교/analyze_can_headers.py`를 작성했다.",
        "- 6개 폴더 쌍 x 8개 파일 = 48개 분석 markdown을 생성했다.",
        "- 집계 문서 `Header_비교_작업내용.md`, `Header_비교_오류사항.md`, `Header_비교_점검_필요사항.md`를 생성했다.",
    ]
    (OUT / "Header_비교_작업기록.md").write_text("\n".join(log_lines).rstrip() + "\n", encoding="utf-8")


def main() -> int:
    OUT.mkdir(parents=True, exist_ok=True)
    parsed = {}
    parse_warnings = []
    for label, root in ROOTS:
        parsed[label] = {}
        for filename in FILES:
            path = root / filename
            if path.exists():
                data = parse_header(path)
            else:
                data = missing_header(path)
            parsed[label][filename] = data
            for warning in data["parse_warnings"]:
                parse_warnings.append(f"{label}/{filename}: {warning}")

    all_stats = []
    all_checks = []
    for (label_a, _), (label_b, _) in itertools.combinations(ROOTS, 2):
        pair = f"{label_a}_{label_b}"
        pair_dir = OUT / f"{pair}_분석"
        pair_dir.mkdir(parents=True, exist_ok=True)
        for filename in FILES:
            report, stats, checks = compare_one(
                label_a,
                parsed[label_a][filename],
                label_b,
                parsed[label_b][filename],
                filename,
            )
            stem = Path(filename).stem
            (pair_dir / f"{stem}_분석내용.md").write_text(report, encoding="utf-8")
            all_stats.append({"pair": pair, "file": filename, **stats})
            for item in checks:
                all_checks.append({"pair": pair, "file": filename, "item": item})

    write_static_docs(all_stats, all_checks, parse_warnings)
    print(f"generated {len(all_stats)} reports in {OUT}")
    print(f"check items: {len(all_checks)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
