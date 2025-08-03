#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

// --- マクロ定義 (Macros) ---
#define SIZE 10000
#define LINELEN 20



// --- 関数プロトタイプ (Function Prototypes) ---


void printdata(int data[], int n);


void swap(int *a, int *b);


void bubblesort(int a[], int n);
int loaddata(char *filename, int data[]);

void selectionsort(int a[], int n);
void insertsort(int a[], int n);

void bubblesort_print(int a[], int n) ;
void print_step(int data[], int n, char *msg, int focus1, int focus2);
#endif // SORT_UTILS_H