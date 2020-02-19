#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "queue.h"


void teste();

void busca_em_largura();

void ambrosio_ilhas();

void suspeitos();

void suspeitos_v2();

void dfs_ordem_crescente();

int main() {
    dfs_ordem_crescente();
    return 0;
}


void teste() {
    int vertices_qtd, edges_qtd, v1, v2;
    scanf("%d %d", &vertices_qtd, &edges_qtd);

    graph *g = create_graph(vertices_qtd);

    for (int i = 0; i < edges_qtd; ++i) {
        scanf("%d %d", &v1, &v2);
        add_edge_directional(g, v1, v2);
    }

    print_graph(g);
    //bfs(g, 3);
    clear_visited(g);
    printf("\n\n");
    //dfs(g, 3);
}

void busca_em_largura() {
    int vertices_qtd,
            edges_qtd,
            teste_qtd,
            v1,
            v2,
            i;
    char str[100];

    scanf("%d %d %d", &vertices_qtd, &edges_qtd, &teste_qtd);

    graph *g = create_graph(vertices_qtd);


    for (i = 0; i < edges_qtd; ++i) {
        scanf("%d %d", &v1, &v2);
        add_edge_directional(g, v1, v2);
    }

    //print_graph(g);

    for (i = 0; i < teste_qtd; ++i) {

        scanf("%d %d", &v1, &v2);

        printf("--------\n\nCaso de Teste #%d - BFS(%d)\n\n", i + 1, v1);

        full_bfs(g, v1);
        //clear_visited(g);

        for (int j = 0; j < vertices_qtd; ++j) {
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

        node *path = get_path(g, v1, v2);

        printf("\n");

        if (!path) {
            printf("Sem caminho entre %d e %d\n", v1, v2);
        } else {
            printf("Caminho entre %d e %d: ", v1, v2);

            print_linked_list(path);
            printf("\n");

        }

        clear_search_data(g);

        printf("\n");
    }

    printf("--------\n");
}

void ambrosio_ilhas() {
    int testes, ilhas, pontes, u, v;

    scanf("%d", &testes);

    int i, j;

    graph *g = NULL;

    for (i = 0; i < testes; i++) {
        scanf("%d %d", &ilhas, &pontes);

        g = create_graph(ilhas);

        for (j = 0; j < pontes; j++) {
            scanf("%d %d", &u, &v);

            add_edge_bidirectional(g, u - 1, v - 1);
        }

        printf("%d\n", bfs(g, 0, ilhas - 1));

        free(g);
    }
}

void suspeitos() {
    int qtd_estudantes, grupos;

    int i, j, k, estudante_id, estudantes_id_aux;

    graph *g = NULL;

    queue *estudantes = create_queue();
    queue *estudantes_aux = create_queue();


    scanf("%d %d", &qtd_estudantes, &grupos);

    while (qtd_estudantes != 0 || grupos != 0) {

        g = create_graph(qtd_estudantes);

        for (i = 0; i < grupos; i++) {

            scanf("%d", &k);

            for (j = 0; j < k; j++) {
                scanf("%d", &estudante_id);

                enqueue(estudantes, estudante_id);
            }

            estudante_id = dequeue(estudantes);

            while (estudante_id != -1) {

                while (!is_empty_queue(estudantes)) {
                    estudantes_id_aux = dequeue(estudantes);
                    add_edge_bidirectional(g, estudante_id, estudantes_id_aux);
                    enqueue(estudantes_aux, estudantes_id_aux);
                }

                while (!is_empty_queue(estudantes_aux)) {
                    enqueue(estudantes, dequeue(estudantes_aux));
                }

                estudante_id = dequeue(estudantes);
            }
        }

        printf("%d\n", full_bfs(g, 0));

        //print_graph_search_data(g);

        /*
        print_graph(g);
        printf("\n\n");*/

        free(g);

        scanf("%d %d", &qtd_estudantes, &grupos);
    }
}

void suspeitos_v2() {

    int qtd_estudantes, grupos;

    int i, j, k, estudante_id, estudantes_id_aux;

    graph *g = NULL;

    scanf("%d %d", &qtd_estudantes, &grupos);

    while (qtd_estudantes != 0 || grupos != 0) {

        g = create_graph(qtd_estudantes);

        for (i = 0; i < grupos; i++) {

            scanf("%d", &k);

            scanf("%d", &estudante_id);

            init_vertex(g, estudante_id);

            for (j = 0; j < k - 1; j++) {
                scanf("%d", &estudantes_id_aux);

                init_vertex(g, estudantes_id_aux);

                add_edge_bidirectional(g, estudante_id, estudantes_id_aux);
                estudante_id = estudantes_id_aux;

            }
        }

        printf("%d\n", full_bfs(g, 0));

        //print_graph_search_data(g);

        /*
        print_graph(g);
        printf("\n\n");*/

        free(g);

        scanf("%d %d", &qtd_estudantes, &grupos);
    }

}

void dfs_ordem_crescente() {
    int testes;
    scanf("%d", &testes);

    graph *g = create_graph(testes * 2);

    char str_1[16];
    char str_2[16];

    int i, j;

    for (i = 0; i < testes; ++i) {
        scanf(" %s", str_1);
        scanf(" %s", str_2);

        if (!contains(g, str_1)) {
            g = init_vertex_with_str(g, str_1);
        }
        if (!contains(g, str_2)) {
            g = init_vertex_with_str(g, str_2);
        }

//        printf("cs %d\n", g->current_size);

        add_edge_directional(g, get_index(g, str_1), get_index(g, str_2));

/*

        printf("\n");
        print_graph(g);
        printf("\n");
*/

    }

    print_graph(g);

    while (g->current_size) {
        g = remove_leafs(g);

        print_graph(g);
        printf("\n");
    }

//
//    remove_leafs(g,);
}