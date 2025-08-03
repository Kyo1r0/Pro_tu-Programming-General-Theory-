#include "sorts.h"

int main(void) {
    // 1-based indexで扱うため、サイズを+1し、0番目は使わない
    recordtype data[] = {-1, 5, 8, 2, 6, 9, 1, 3, 4, 7, 0}; // data[0]は無視
    int n = (sizeof(data) / sizeof(data[0])) - 1; // データ数は10

    printf("Heap Sort\n");
    printf("Before: ");
    // 1番目から表示するヘルパー関数を別途作っても良い
    for(int i = 1; i <= n; i++) printf("%d ", data[i]);
    printf("\n");

    heapsort(data, n);

    printf("After:  ");
    for(int i = 1; i <= n; i++) printf("%d ", data[i]);
    printf("\n");
    
    return 0;
}