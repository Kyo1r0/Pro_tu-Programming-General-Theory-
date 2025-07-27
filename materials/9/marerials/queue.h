#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// --- 型定義 (Type Definitions) ---

typedef char elementtype;

struct node {
    elementtype element;
    struct node *next;
};

typedef struct node * link;

struct queue {
    link front, rear;
};


// --- 関数プロトタイプ (Function Prototypes) ---

// 連結リスト操作関数
struct node *initlist(void);
void insert(struct node *p, elementtype x);
void delete(struct node *p);
void printlist(struct node *l);

// キュー操作関数
void initqueue(struct queue *q);
int queueempty(struct queue q);
void enqueue(struct queue *q, elementtype x);
elementtype dequeue(struct queue *q);

#endif // QUEUE_H