#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MAX を使うため
#include <string.h> 

#define LIMIT 100 // マージソートの一時配列用

// ソート対象のデータ型
typedef int recordtype;
typedef int elementtype;

struct node {
    elementtype element;
    struct node *next;
};

typedef struct node * link;
typedef link list;

// --- 関数プロトタイプ宣言 ---

// 共通ヘルパー関数
void swap(recordtype *a, recordtype *b);
void print_array(recordtype a[], int n);

// ヒープソート用
void pushdown(recordtype a[], int first, int last);
void heapsort(recordtype a[], int n);

// マージソート用
void mergesort(recordtype a[], int l, int r);
// 連結リスト版マージソート
list mergesort_list(list l);
link merge_list(link a, link b);

// テスト用のヘルパー関数
list create_list_from_array(elementtype data[], int n);
void print_linked_list(list l);



// 視覚化
void print_sort_step(recordtype a[], int n, char *msg, int focus1, int focus2);

#endif // SORTS_H