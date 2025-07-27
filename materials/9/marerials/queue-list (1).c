#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

struct node {
  elementtype element;
  struct node *next;
};

struct node *initlist(void){
  struct node *n;

  n = (struct node *)malloc(sizeof(struct node));
  n->next = NULL;
  return n;
}

void insert(struct node *p, elementtype x){
  struct node *n;

  n = (struct node *)malloc(sizeof(struct node));
  n->element = x;
  n->next = p->next;
  p->next = n;
}

void delete(struct node *p){
  if(p->next != NULL){
    p->next = p->next->next;
  }
}

void printlist(struct node *l){
  l = l->next; /* skip a head */
  while (l != NULL) {
        printf("%c", l->element);
        // 次のノードがあれば "->" を表示する
        if (l->next != NULL) {
            printf("->");
        }
        l = l->next; // 次のノードへ移動
    }
    printf("\n"); // 最後に見やすく改行する
}




typedef struct node * link;

struct queue{
  link front, rear;
};

void initqueue(struct queue *q){
  q->front = initlist();
  q->rear = q->front;
}

int queueempty(struct queue q){
  return q.front->next == NULL;
}

void enqueue(struct queue *q, elementtype x){
  insert(q->rear, x);
  q->rear = q->rear->next;
}

elementtype dequeue(struct queue *q){
  elementtype work;
  if(queueempty(*q)){
    printf("underflow\n");
    exit(1);
  }else{
    work = q->front->next->element;
    delete(q->front);
    if(queueempty(*q)){
      q->rear = q->front;
    }
    return work;
  }
}

