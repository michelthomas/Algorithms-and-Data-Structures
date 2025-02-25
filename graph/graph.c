//
// Created by MichelT on 14/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "queue.h"

graph *create_graph(int vertices_qtd) {
    graph *new_graph = (graph *) malloc(sizeof(graph));
    new_graph->vertices_qtd = vertices_qtd;
    new_graph->vertices = (adj_list *) malloc(sizeof(adj_list) * vertices_qtd);
    new_graph->visited = (int *) malloc(sizeof(int) * vertices_qtd);
    new_graph->pred_dist_arr = (pred_dist *) malloc(sizeof(pred_dist) * vertices_qtd);
    new_graph->current_size = 0;


    return new_graph;
}

graph *create_graph_init_vertices(int vertices_qtd) {
    graph *new_graph = (graph *) malloc(sizeof(graph));

    new_graph->vertices_qtd = vertices_qtd;
    new_graph->current_size = 0;
    new_graph->vertices = (adj_list *) malloc(sizeof(adj_list) * vertices_qtd);
    new_graph->visited = (int *) malloc(sizeof(int) * vertices_qtd);
    new_graph->pred_dist_arr = (pred_dist *) malloc(sizeof(pred_dist) * vertices_qtd);

    for (int i = 0; i < vertices_qtd; i++) {
        new_graph->vertices[i].list = NULL;
        new_graph->vertices[i].str[0] = '\0';
        new_graph->visited[i] = 0;
        new_graph->pred_dist_arr[i].predecessor = -1;
        new_graph->pred_dist_arr[i].dist = -1;
    }

    return new_graph;
}

void init_vertex(graph *g, int v) {

    if (g->pred_dist_arr[v].predecessor != -1) {
        g->vertices[v].list = NULL;
        g->vertices[v].str[0] = '\0';
        g->visited[v] = 0;
        g->pred_dist_arr[v].predecessor = -1;
        g->pred_dist_arr[v].dist = -1;

    }
}

graph *init_vertex_with_str(graph *g, char *str) {
    g->vertices[g->current_size].list = NULL;
    g->vertices[g->current_size].str[0] = '\0';
    strcpy(g->vertices[g->current_size].str, str);
    g->visited[g->current_size] = 0;
    g->pred_dist_arr[g->current_size].predecessor = -1;
    g->pred_dist_arr[g->current_size].dist = -1;

    g->current_size = g->current_size + 1;

    return g;
}

void add_edge_directional(graph *g, int vertex1, int vertex2) {
//    g->vertices[vertex1].list = add_ordered(g->vertices[vertex1].list, vertex2);
    g->vertices[vertex1].list = add_begin(g->vertices[vertex1].list, vertex2);

}

void add_edge_bidirectional(graph *g, int vertex1, int vertex2) {
    add_edge_directional(g, vertex1, vertex2);
    add_edge_directional(g, vertex2, vertex1);
}

void dfs(graph *graph, int source) {
    graph->visited[source] = 1;
    printf("%d ", source);
    node *list = graph->vertices[source].list;

    while (list != NULL) {
        if (!graph->visited[list->key]) {
            dfs(graph, list->key);
        }

        list = list->next;
    }
}

int full_bfs(graph *graph, int source) {
    queue *queue = create_queue();
    int dequeued;

    node *list = NULL;

    int qtd_visited = 1;

    graph->visited[source] = 1;

    enqueue(queue, source);

    graph->pred_dist_arr[source].predecessor = -1;
    graph->pred_dist_arr[source].dist = 0;

    //printf("Iniciando busca em largura a partir de %d\n", source);

    while (!is_empty_queue(queue)) {
        dequeued = dequeue(queue);
        list = graph->vertices[dequeued].list;

        while (list != NULL) {
            if (!graph->visited[list->key]) {
                graph->pred_dist_arr[list->key].dist = graph->pred_dist_arr[dequeued].dist + 1;
                graph->pred_dist_arr[list->key].predecessor = dequeued;

                //printf("Iniciando busca em largura a partir de %d\n", list->key);

                graph->visited[list->key] = 1;
                qtd_visited++;

                enqueue(queue, list->key);
            }

            list = list->next;
        }
    }

    //printf("\n");

    return qtd_visited;
}

int bfs(graph *graph, int source, int dest) {
    queue *queue = create_queue();
    int dequeued;

    node *list = NULL;
    graph->visited[source] = 1;

    enqueue(queue, source);

    graph->pred_dist_arr[source].predecessor = -1;
    graph->pred_dist_arr[source].dist = 0;

    //printf("Iniciando busca em largura a partir de %d\n", source);

    if (source == dest) {
        return 0;
    }

    while (!is_empty_queue(queue)) {
        dequeued = dequeue(queue);
        list = graph->vertices[dequeued].list;

        while (list != NULL) {
            if (!graph->visited[list->key]) {
                graph->pred_dist_arr[list->key].dist = graph->pred_dist_arr[dequeued].dist + 1;

                if (dest == list->key) {
                    return graph->pred_dist_arr[list->key].dist;
                }

                graph->pred_dist_arr[list->key].predecessor = dequeued;

                //printf("Iniciando busca em largura a partir de %d\n", list->key);

                graph->visited[list->key] = 1;
                enqueue(queue, list->key);
            }

            list = list->next;
        }
    }

    //printf("\n");

    return -1;
}

node *_get_path(node *path, pred_dist *arr, int dest) {

    if (dest == -1) {
        return path;
    }

    path = add_begin(path, dest);

    return _get_path(path, arr, arr[dest].predecessor);
}

node *get_path(graph *g, int source, int dest) {

    node *n = create_node(dest);

    if (source == dest) {
        return n;
    }

    if (g->pred_dist_arr[dest].predecessor == -1) {
        return NULL;
    }

    n = _get_path(n, g->pred_dist_arr, g->pred_dist_arr[dest].predecessor);

    return n;
}

void print_graph(graph *graph) {
    for (int i = 0; i < graph->current_size; ++i) {
        printf("%d %s | ", i, graph->vertices[i].str);
        print_linked_list(graph->vertices[i].list);
        printf("\n");
    }
}

void print_graph_search_data(graph *g) {
    char str[100];

    for (int j = 0; j < g->vertices_qtd; ++j) {
        if (g->pred_dist_arr[j].dist == -100) {
            sprintf(str, "%c", '-');
        } else {
            sprintf(str, "%d", g->pred_dist_arr[j].dist);
        }

        printf("%d | %s | ", j, str);

        if (g->pred_dist_arr[j].predecessor == -1) {
            sprintf(str, "%c", '-');
        } else {
            sprintf(str, "%d", g->pred_dist_arr[j].predecessor);
        }

        printf("%s\n", str);
    }
}

void clear_visited(graph *g) {
    for (int i = 0; i < g->vertices_qtd; ++i) {
        g->visited[i] = 0;
    }
}

void clear_pred_dist_arr(pred_dist *arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i].predecessor = -1;
        arr[i].dist = -1;
    }
}

void clear_search_data(graph *g) {
    for (int i = 0; i < g->vertices_qtd; ++i) {
        g->visited[i] = 0;
        g->pred_dist_arr[i].predecessor = -1;
        g->pred_dist_arr[i].dist = -1;
    }
}


int contains(graph *g, char *str) {
    for (int i = 0; i < g->current_size; ++i) {
        if (strcmp(g->vertices[i].str, str) == 0) {
            return 1;
        }
    }

    return 0;
}

int get_index(graph *g, char *str) {
    for (int i = 0; i < g->current_size; ++i) {
        if (strcmp(g->vertices[i].str, str) == 0) {
            return i;
        }
    }

    return -1;
}

graph *remove_leafs(graph *g) {

    graph *new_g = create_graph(g->current_size);

    int j = 0;
    for (int i = 0; i < g->current_size; ++i) {
        if (!is_empty(g->vertices[i].list)) {
            init_vertex_with_str(new_g, g->vertices[i].str);


            new_g->vertices[j].list = g->vertices[i].list;


            node *head = new_g->vertices[j].list;

            while (new_g->vertices[j].list) {
                if (is_empty(g->vertices[new_g->vertices[j].list->key].list)) {
                   head =  remove_node(head, new_g->vertices[j].list);
                }

                new_g->vertices[j].list = new_g->vertices[j].list->next;
            }

            new_g->vertices[j].list = head;

            j++;
        }
    }

    free(g);

    return new_g;
}