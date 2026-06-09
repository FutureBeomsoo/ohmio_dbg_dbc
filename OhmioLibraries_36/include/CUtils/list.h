#pragma once

#define LIST_RESULT_OK 0
#define LIST_RESULT_FULL 1
#define LIST_RESULT_NOT_UNIQUE 2
#define LIST_RESULT_NOT_FOUND 3
#define LIST_RESULT_OUT_OF_BOUNDS 4

#define LIST_ADD(list, size, max_size, elem, result) \
{\
   if (size < max_size) { \
      list[size++] = elem; \
      result = LIST_RESULT_OK; \
   } \
   else \
      result = LIST_RESULT_FULL;\
}

// result == 1 ==> success
// result == 0 ==> unsuccessful, full
// result == 2 ==> unsuccessful, duplicate
#define LIST_ADD_UNIQUE(list, size, max_size, elem, result) \
{\
   int found = 0; \
   for (int i = 0; i < size; i++) \
      if (elem == list[i]) \
         found = 1; \
   if (!found) { \
      if (size < max_size) { \
         list[size++] = elem; \
         result = LIST_RESULT_OK; \
      } \
      else \
         result = LIST_RESULT_FULL;\
   } \
   else \
      result = LIST_RESULT_NOT_UNIQUE;\
}

#define LIST_REMOVE(list, size, elem, result) \
{ \
   result = LIST_RESULT_NOT_FOUND; \
   for (int i = 0; i < size; i++) { \
      if (list[i] == elem) { \
         result = LIST_RESULT_OK; \
         size--; \
         for (int j = i; j < size; j++) \
            list[j] = list[j + 1]; \
      }\
   }\
}

#define LIST_REMOVE_AT(list, size, idx, result) \
{ \
   if (idx >= size) \
      result = LIST_RESULT_OUT_OF_BOUNDS;\
   else \
   { \
      size--; \
      for (int  j = idx; j < size; j++) \
         list[j] = list[j + 1]; \
      result = LIST_RESULT_OK;\
   } \
}
