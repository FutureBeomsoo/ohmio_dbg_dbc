/**
 * @file graph.h
 *  @brief     Graph theory algorithms. Graphs are represented as adjacency lists with compile-time defined maximum sizes. The element types and the maximum number of types must be defined before this header file is included. For example:
 *  \snippet unit_tests/test_graph.cpp graph part1
 *  There are no limits to the maximum size of the possible graph
 *  @author    Carlos Aydos
 *  @date      12 Feb 2020
 **/

#pragma once

typedef struct
{
   int * adjacency;
   int * n_adjacents;
   int n_vertices;
   int n_max_adjacents;
} g_t;

void graph_int_init(g_t * g);

void add_edge(g_t * g, int v1, int v2);

/**
 *  @brief     Graph depth first traversal algorithm
 *  @author    Carlos Aydos
 *  @date      12 Feb 2020
 **/
void dfs(
      const g_t * const g,
      int v0,                        //!< INPUT - The start vertex
      int * visited,                 //!< INPUT - Temporary variable used by the function, must be set to zeros before calling function
      void (*visitor)(int v)         //!< INPUT - A callback for when each vertex is visited.
);

/**
 *  @brief     Graph breadth first traversal algorithm
 *  @author    Carlos Aydos
 *  @date      12 Feb 2020
 **/
void bfs(
      const g_t * const g,
      int v0,                           //!< INPUT - The start vertex
      int * visited,                    //!< INPUT/OUTPUT - Used by the function. Visited vertices are set to 1.
      int max_depth,                      //!< INPUT - The maximum search depth
      int * vbuf,                       //!< INPUT - User allocated temporary storage of 2*size n_vertices
      void (*visitor)(int v, int depth) //!< INPUT - A callback for when each vertex is visited. The depth parameter shows the distance from the root.
);

/**
 *  @brief Graph coloring algorithm useful for TDMA applications. Colors are guaranteed to not conflict in any depth-2 neighbourhood
 *  @author    Carlos Aydos
 *  @date      12 Feb 2020
 */
void graph_coloring(
      const g_t * const g,
      int * cbuf,            //!< INPUT - User allocated temporary storage of size n_vertices
      int * vbuf,            //!< INPUT - User allocated temporary storage of size 3 * n_vertices
      int * colors           //!< OUTPUT - User allocated result
);

#define CREATE_GRAPH_INT(NAME, N_V, MAX_ADJ) \
      int NAME##_adjacency[N_V * MAX_ADJ]; \
      int NAME##_n_adjacents[N_V]; \
      g_t NAME##_g = {NAME##_adjacency, NAME##_n_adjacents, N_V, MAX_ADJ};
