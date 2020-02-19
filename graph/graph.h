//
// Created by MichelT on 14/02/2020.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "list.h"

typedef struct adj_list {
    char str[16];
    node *list;
} adj_list;


typedef struct pred_dist {
    int predecessor;
    int dist;
} pred_dist;

typedef struct graph {
    int current_size;
    int vertices_qtd;
    adj_list *vertices;
    int *visited;
    pred_dist *pred_dist_arr;
} graph;

graph *create_graph(int vertices_qtd);

graph *create_graph_init_vertices(int vertices_qtd);

graph *init_vertex_with_str(graph *g, char *str);

void init_vertex(graph *g, int v);

void add_edge_directional(graph *g, int vertex1, int vertex2);

void add_edge_bidirectional(graph *g, int vertex1, int vertex2);

void dfs(graph *graph, int source);

int full_bfs(graph *graph, int source);

int bfs(graph *graph, int source, int dest);

void print_graph(graph *graph);

void print_graph_search_data(graph *g);

void clear_search_data(graph *g);

void clear_visited(graph *g);

node *get_path(graph *g, int source, int dest);

void clear_pred_dist_arr(pred_dist *arr, int n);

int contains(graph *g, char *str);

int get_index(graph *g, char *str);

graph *remove_leafs(graph *g);

#endif //GRAPH_GRAPH_H
