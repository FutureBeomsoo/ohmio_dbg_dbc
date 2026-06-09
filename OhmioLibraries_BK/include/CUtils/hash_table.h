/**
 *  @file hash_table.h
 *  @brief Pre-allocated memory hash table implementation for integer keys and void pointer elements. Duplicate keys are allowed.
 *  @author    Carlos Aydos
 *  @date      4 May 2020
 **/

#pragma once

typedef struct
{
   int allocated_size;
   int n_iterators;
   int * keys;
   void ** elements;
   int * iterators;
   int size;
   int initialised;
} hash_table_t;

#define HT_DELETED -1
#define HT_NEVER_USED -2
#define HT_END NULL

/**
 *  @brief     Calcs the hash code of an integer
 *  @returns   The hash code
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
int hash_code(int key, int size);

/**
 *  @brief     Inserts an item
 *  @returns   Returns the inserted element if successful, else NULL
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void * hash_table_insert(hash_table_t * const t, int key, void * const element);

/**
 *  @brief     Find an item. If there are multiple identical keys, this will return the first inserted element
 *  @returns   Returns the found element if successful, else NULL.
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void * hash_table_find(hash_table_t * const t, int key);

/**
 *  @brief     Deletes an item. If there are multiple identical keys, this will delete the first inserted element (FIFO behaviour)
 *  @returns   Returns the deleted element if successful, else NULL.
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void * hash_table_delete(hash_table_t * const t, int key);

/**
 *  @brief     Initialise and delete all elements
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void hash_table_reset(hash_table_t * const t);

/**
 *  @brief     Finds the next item.
 *  @return    The next element or NULL if it reached the end. Argument 'key' returns the matching key. If there are multiple identical keys, the elements of that keye are iterated in the sequence they were inserted
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void * hash_table_next(
      hash_table_t * const t, //!< INPUT hash table handler
      int iter,               //!< INPUT iterator index (between 0  and  N_ITERATORS-1)
      int * key               //!< OUTPUT the next key
      );

/**
 *  @brief     Resets the iterator hash_table_next()
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void hash_table_reset_iter(
      hash_table_t * const t, //!< INPUT hash table handler
      int iter                //!< INPUT iterator index (between 0  and  N_ITERATORS-1)
      );

/**
 *  @brief     Call this first. This allocates memory required for the hash table and gives it a name. This can be declared in any scope, including the global scope. Do not use a semicolon at the end.
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
#define CREATE_HASH_TABLE( \
      NAME,                   /* scope unique name for the hash table */ \
      SIZE,                   /* maximum number of elements (not keys) the table can hold */ \
      N_ITERATORS             /* number of simultaneous iterators (iterators are not thread-safe) */ \
      ) \
   int NAME##_hash_table_keys[SIZE]; \
   void * NAME##_hash_table_elements[SIZE]; \
   int NAME##_hash_table_iterators[N_ITERATORS]; \
   hash_table_t NAME = {SIZE, N_ITERATORS, NAME##_hash_table_keys, NAME##_hash_table_elements, NAME##_hash_table_iterators, 0, 0};
