#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

// --- 型定義 (Type Definitions) ---

typedef char elementtype;

struct node {
    elementtype element;
    struct node *next;
};

// stack型を struct node へのポインタとして定義
typedef struct node * stack;


// --- 関数プロトタイプ (Function Prototypes) ---

// 連結リスト操作関数 (スタックの実装に使われるヘルパー関数)
struct node *initlist(void);
void insert(struct node *p, elementtype x);
void delete(struct node *p);
void printlist(struct node *l);

// スタック操作関数
void initstack(stack *s);
int stackempty(stack s);
void push(stack s, elementtype x);
elementtype pop(stack s);

#endif // STACK_H