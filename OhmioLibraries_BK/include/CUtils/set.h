/**
 *  @file set.h
 *  @brief
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 **/

#pragma once

#define SET_DELETED -1
#define SET_NEVER_USED -2
#define SET_FAIL 0
#define SET_SUCCESS 1
#define SET_END 2

typedef struct
{
   int allocated_size;
   int n_iterators;
   int * keys;
   int * iterators;
   int size;
   int initialised;
} set_t;

/**
 *  @brief     Inserts an item
 *  @returns   Returns SET_SUCCESS or SET_FAIL
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
int set_insert(set_t * const t, int key);

/**
 *  @brief     Find an item. If there are multiple identical keys, this will return only one of the elements.
 *  @returns   Returns SET_SUCCESS or SET_FAIL
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
int set_find(set_t * const t, int key);

/**
 *  @brief     Deletes an item. If there are multiple identical keys, this will delete only one of the elements.
 *  @returns   Returns SET_SUCCESS or SET_FAIL
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
int set_delete(set_t * const t, int key);

/**
 *  @brief     Delete all elements and initialises
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void set_reset(set_t * const t);

/**
 *  @brief     Finds the next item.
 *  @returns   Returns SET_SUCCESS or SET_END
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
int set_next(
      set_t * const t, //!< INPUT hash table handler
      int iter,               //!< INPUT iterator index (between 0  and  N_ITERATORS-1)
      int * key               //!< OUTPUT the next key
      );

/**
 *  @brief     Resets the iterator set_next()
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
void set_reset_iter(
      set_t * const t, //!< INPUT hash table handler
      int iter                //!< INPUT iterator index (between 0  and  N_ITERATORS-1)
      );

/**
 *  @brief     Call this first. This allocates memory required for the hash table and gives it a name. This can be declared in any scope, including the global scope. Do not use a semicolon at the end.
 *  @author    Carlos Aydos
 *  @date      5 May 2020
 */
#define CREATE_SET(NAME, SIZE, N_ITERATORS) \
   int NAME##_set_keys[SIZE+1]; \
   int NAME##_set_iterators[N_ITERATORS]; \
   set_t NAME = {SIZE+1, N_ITERATORS, NAME##_set_keys, NAME##_set_iterators, 0, 0};
   // the SIZE+1 is to ensure the set can return fail for a duplciate when the set is full


