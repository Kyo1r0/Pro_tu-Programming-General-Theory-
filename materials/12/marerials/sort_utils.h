#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

// recordtypeの定義（構造体やintなど、ソート対象の型）
typedef int recordtype;

// --- 関数プロトタイプ ---
void print_sort_step(recordtype a[], int n, char *msg, int focus1, int focus2);
void swap(recordtype *a, recordtype *b);
void bubblesort(recordtype a[], int n);
void quicksort(recordtype a[], int l, int r);
void shellsort(recordtype a[], int n); // 今回追加
void print_vec(recordtype a[],int n);
#endif // SORT_UTILS_H