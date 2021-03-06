#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void queue_init(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;
}

void queue_destroy(Queue *Q) {
    queue_clear(Q);
}

void queue_push(Queue *Q, int data) {
    pNode p = (pNode)malloc(sizeof(struct Node));
    if(NULL == p) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    p->data = data;
    p->next = NULL;
    if(queue_is_empty(Q)) {
        Q->head = Q->tail = p;
    } else {
        Q->tail->next = p;
        Q->tail = p;
    }
    ++Q->size;
}

void queue_pop(Queue *Q) {
    assert(!queue_is_empty(Q));
    pNode p = Q->head;
    Q->head = Q->head->next;
    free(p);
    --Q->size;
}

int queue_top(const Queue *Q) {
    assert(!queue_is_empty(Q));
    return Q->head->data;
}

void queue_clear(Queue *Q) {
    while(!queue_is_empty(Q))
        queue_pop(Q);
}

int queue_size(const Queue *Q) {
    return Q->size;
}

int queue_is_empty(const Queue *Q) {
    return NULL == Q->head;
}


int main()
{
  Queue *q = (Queue*)malloc(sizeof(Queue));
  if(NULL == q) {
      perror("malloc");
      exit(EXIT_FAILURE);
  }
  queue_init(q);
  queue_push(q, 10);
  printf("head: %d\ttail: %d\tsize: %d\n", q->head->data, q->tail->data, q->size);
  queue_push(q, 20);
  printf("head: %d\ttail: %d\tsize: %d\n", q->head->data, q->tail->data, q->size);
  queue_pop(q);
  printf("head: %d\ttail: %d\tsize: %d\n", q->head->data, q->tail->data, q->size);
  queue_destroy(q);
  if(queue_is_empty(q))
      printf("The queue is emtpy now!\n");
  return 0;
}
