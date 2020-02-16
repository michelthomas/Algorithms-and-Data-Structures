//
// Created by MichelT on 13/02/2020.
//

#include "CUnit/Basic.h"
#include <stdlib.h>
#include "max_heap.h"

void create_test() {
    HEAP *h = create_heap();
    CU_ASSERT_PTR_NOT_NULL(h)

    for (int i = 1; i < HEAP_MAX_SIZE; ++i) {
        CU_ASSERT_PTR_NULL(h->data[i])
    }

    CU_ASSERT_EQUAL(h->size, 0)
}

void get_parent_index_test() {
    CU_ASSERT_EQUAL(get_parent_index(0), 0)
    CU_ASSERT_EQUAL(get_parent_index(1), 0)
    CU_ASSERT_EQUAL(get_parent_index(2), 1)
    CU_ASSERT_EQUAL(get_parent_index(5), 2)
    CU_ASSERT_EQUAL(get_parent_index(10), 5)
}

void get_left_index_test() {
    CU_ASSERT_EQUAL(get_left_index(0), 0)
    CU_ASSERT_EQUAL(get_left_index(1), 2)
    CU_ASSERT_EQUAL(get_left_index(2), 4)
    CU_ASSERT_EQUAL(get_left_index(5), 10)
    CU_ASSERT_EQUAL(get_left_index(10), 20)
}

void get_right_index_test() {
    CU_ASSERT_EQUAL(get_right_index(0), 1)
    CU_ASSERT_EQUAL(get_right_index(1), 3)
    CU_ASSERT_EQUAL(get_right_index(2), 5)
    CU_ASSERT_EQUAL(get_right_index(5), 11)
    CU_ASSERT_EQUAL(get_right_index(10), 21)
}

void swap_test() {
    HEAP *h = create_heap();

    h->data[1] = "CORLEONE";
    h->data[2] = "BARZINI";

    CU_ASSERT_EQUAL("CORLEONE", h->data[1])
    CU_ASSERT_EQUAL("BARZINI", h->data[2])

    void *p1 = h->data[1];
    void *p2 = h->data[2];

    CU_ASSERT_EQUAL("CORLEONE", p1)
    CU_ASSERT_EQUAL("BARZINI", p2)

    swap(&h->data[1], &h->data[2]);

    CU_ASSERT_EQUAL("CORLEONE", h->data[2])
    CU_ASSERT_EQUAL("BARZINI", h->data[1])

    CU_ASSERT_EQUAL(p2, h->data[1])
    CU_ASSERT_EQUAL(p1, h->data[2])
}

void enqueue_test_aux(HEAP *h, int in[], int out[], int n) {

    struct intt {
        int i;
    };

    struct intt *arr[n];

    int i;

    for (i = 0; i < n; ++i) {
        arr[i] = malloc(sizeof(struct intt));
    }

    for (i = 0; i < n; ++i) {
        arr[i]->i = in[i];
    }


    for (i = 0; i < n; ++i) {
        enqueue(h, arr[i]->i, arr[i]);
    }

    for (i = 0; i < n; ++i) {
        CU_ASSERT_EQUAL(((struct intt *) dequeue(h))->i, out[i])
    }

}

void enqueue_test() {


    int n = 5;

    int in[5] = {5, 9, 3, 6, 10};
    int out[5] = {10, 9, 6, 5, 3};
    HEAP *h = create_heap();

    enqueue_test_aux(h, in, out, n);

}

void print_int(int i) {
    printf("%d", i);
}

void heapsort_test() {
    int arr[10] = {2, 5, 1, 3, 7, 8, 6, 9, 0, 4};

    HEAP *h = heapsort_int(arr, 10);

    typedef struct _node {
        int priority;
        void *data;
    } _node;

    print_heap_int(h);

    CU_ASSERT_EQUAL(((_node *) h->data[1])->priority, 0)
    CU_ASSERT_EQUAL(((_node *) h->data[2])->priority, 1)
    CU_ASSERT_EQUAL(((_node *) h->data[3])->priority, 2)
    CU_ASSERT_EQUAL(((_node *) h->data[4])->priority, 3)
    CU_ASSERT_EQUAL(((_node *) h->data[5])->priority, 4)
    CU_ASSERT_EQUAL(((_node *) h->data[6])->priority, 5)
    CU_ASSERT_EQUAL(((_node *) h->data[7])->priority, 6)
    CU_ASSERT_EQUAL(((_node *) h->data[8])->priority, 7)
    CU_ASSERT_EQUAL(((_node *) h->data[9])->priority, 8)
    CU_ASSERT_EQUAL(((_node *) h->data[10])->priority, 9)
}

int main(int argc, char **argv) {
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (NULL == CU_add_test(pSuite, "create_heap test", create_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "get_parent_index test", get_parent_index_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "get_left_index test", get_left_index_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "get_right_index test", get_right_index_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "swap test", swap_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "enqueue test", enqueue_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "heapsort test", heapsort_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }



    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

