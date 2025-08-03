#include "sort_utils.h"
#include <string.h> // sprintf用にインクルード

// 以前作成したステップ表示関数（名前を少し変更）


// 以前作成したswap関数
void swap(recordtype *a, recordtype *b) {
    recordtype tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_vec(recordtype a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void shellsort(recordtype a[], int n) {
    int i, j, h;
    recordtype v;

    // ギャップhの決定
    for (h = 1; h <= n / 9; h = 3 * h + 1);

    // ギャップhを狭めながらソート
    for (; h > 0; h /= 3) {
        // h-ソート（間隔hの挿入ソート）
        for (i = h; i < n; i++) {
            v = a[i];
            j = i;
            while (j >= h && a[j - h] > v) { // j >= h に修正
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
        }
    }
}

int partition(recordtype a[], int l, int r){
int i, j; recordtype v;
v = a[l]; i = l; j = r+1;
do{
do{ i++; }while(a[i]< v);
do{ j--; }while(a[j] > v);
if(i < j){ swap(&a[i], &a[j]); }
}while(j > i);
a[l] = a[j]; a[j] = v;
return j;
}



void quicksort(recordtype a[], int l, int r){
int i;
if(l < r){
i = partition(a, l, r);
quicksort(a, l, i-1);
quicksort(a, i+1, r);
}
}


