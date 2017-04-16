/*
** Created by ummon on 4/16/2017.
*/

#include "pqueue_test.h"
#include <stdio.h>
#include <assert.h>

static inline int int_compare(int x, int y)
{
    return (x>y) - (y>x);
}
#define T int
#include "pqueue.h"

int pqueue_test()
{
    printf("Testing pqueue insertion and peeks!\n");

    int l;

    int_pqueue* pq;
    int_pqueue_init(pq);
    assert(pq->length == 0);

    l = pq->length;
    int_pqueue_insert(pq, 10);
    assert(int_pqueue_peek(pq) == 10);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 5);
    assert(int_pqueue_peek(pq) == 10);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 25);
    assert(int_pqueue_peek(pq) == 25);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 7);
    assert(int_pqueue_peek(pq) == 25);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 13);
    assert(int_pqueue_peek(pq) == 25);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 7);
    assert(int_pqueue_peek(pq) == 25);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 17);
    assert(int_pqueue_peek(pq) == 25);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 50);
    assert(int_pqueue_peek(pq) == 50);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 60);
    assert(int_pqueue_peek(pq) == 60);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 1);
    assert(int_pqueue_peek(pq) == 60);
    assert(pq->length = l+1);

    printf("Testing pqueue pops!\n");

    l = pq->length;
    assert(int_pqueue_pop(pq) == 60);
    assert(pq->length = l-1);
    assert(int_pqueue_peek(pq) == 50);

    l = pq->length;
    assert(int_pqueue_pop(pq) == 50);
    assert(pq->length = l-1);
    assert(int_pqueue_peek(pq) == 25);

    l = pq->length;
    assert(int_pqueue_pop(pq) == 25);
    assert(pq->length = l-1);
    assert(int_pqueue_peek(pq) == 17);

    l = pq->length;
    assert(int_pqueue_pop(pq) == 17);
    assert(pq->length = l-1);
    assert(int_pqueue_peek(pq) == 13);

    l = pq->length;
    assert(int_pqueue_pop(pq) == 13);
    assert(pq->length = l-1);
    assert(int_pqueue_peek(pq) == 10);

    l = pq->length;
    assert(int_pqueue_pop(pq) == 10);
    assert(pq->length = l-1);
    assert(int_pqueue_peek(pq) == 7);

    l = pq->length;
    assert(int_pqueue_pop(pq) == 7);
    assert(pq->length = l-1);
    assert(int_pqueue_peek(pq) == 5);

    l = pq->length;
    int_pqueue_insert(pq, 3);
    assert(int_pqueue_peek(pq) == 5);
    assert(pq->length = l+1);

    l = pq->length;
    int_pqueue_insert(pq, 20);
    assert(int_pqueue_peek(pq) == 20);
    assert(pq->length = l+1);

    return 1;
}