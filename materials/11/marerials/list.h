#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

// 構造体とポインタ型の定義
struct node {
    elementtype element;
    struct node *next, *prev;
};
typedef struct node * link;
typedef link list;
typedef link position;

// 関数のプロトタイプ宣言
list initlist(void);
void insert(position p, elementtype e); // 'l'は不要
void delete_node(position p);
elementtype retrieve(position p);
position first(list l);
position end(list l);
void printlist(list l);

#endif // DOUBLY_LIST_H