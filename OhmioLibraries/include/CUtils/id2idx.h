#pragma once

#include "hash_table.h"

#define ID2IDX_NONE -1

typedef struct
{
   hash_table_t * t;
   int * indices_vector;
} id2idx_t;

void id2idx_reset(id2idx_t * const map);
void add_id(id2idx_t * const map, int id);
int get_id(const id2idx_t * const map, int idx);
int get_index(const id2idx_t * const map, int id);
int get_size(const id2idx_t * const map);
void id2idx_reset_iter(id2idx_t * const map, int iter);
int id2idx_next(id2idx_t * const map, int iter, int * id);

#define CREATE_ID2IDX(NAME, SIZE, HASH_SCALE, N_ITERATORS) \
   CREATE_HASH_TABLE(NAME##_ht, SIZE, N_ITERATORS) \
   int NAME##indices_vector[SIZE]; \
   id2idx_t NAME = {&(NAME##_ht), NAME##indices_vector};
