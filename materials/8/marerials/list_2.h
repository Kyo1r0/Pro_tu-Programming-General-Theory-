#ifndef LIST_H // 二重インクルードを防止するためのインクルードガード
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// データ型の定義
typedef char elementtype;

// 構造体の定義
struct node {
  elementtype element;
  struct node *next;
};

// 関数のプロトタイプ宣言
struct node *initlist(void);
void insert(struct node *p, elementtype x);
void delete(struct node *p);
void print_list(struct node *list);

#endif // LIST_H