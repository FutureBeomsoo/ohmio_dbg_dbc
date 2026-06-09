#pragma once

//! Location in 2D (in m units)
typedef struct
{
	double x;			//!< X component of location (eastward) 
	double y;			//!< Y component of location (northward)
	double h;			//!< heading of the way point (radians). counter clockwise, positive X axis is 0
} WAyPointForMirror;



//! Calculate the mirroring
//
//! see https://hmitechnologies.atlassian.net/wiki/spaces/AI/pages/2681307157/Mirroring+for+transition+between+virtual+and+GPS+coordinates
//! Call this function once, then call MirrorPoint() repeatedly
//! to get the mirrored track.
//! All parameters are in m and sec.
//! @param[in] before - the location just before the 'jump' in location
//! @param[in] after - the location just after the 'jump' in location
void CreateMirror(const WAyPointForMirror* before, const WAyPointForMirror* after);

//! Get the mirrored location for a way point
//
//! see https://hmitechnologies.atlassian.net/wiki/spaces/AI/pages/2681307157/Mirroring+for+transition+between+virtual+and+GPS+coordinates
//! Call CreateMirror() first to set up the parameters of the mirroring
//! @param[in] waypoint - the location to mirror (should be after the jump)
//! @param[in] mirrored - the mirrored location (the virtual location if we didn't have a jump)
void MirrorPoint(const WAyPointForMirror* waypoint, WAyPointForMirror* mirrored);

