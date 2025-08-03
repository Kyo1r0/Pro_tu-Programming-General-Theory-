#include "sorts.h"

int main(void) {
    recordtype data[] = {5, 8, 2, 6, 9, 1, 3, 4, 7, 0};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Merge Sort\n");
    printf("Before: ");
    print_array(data, n); // 0番目から表示

    mergesort(data, 0, n - 1); // 0からn-1の範囲をソート

    printf("After:  ");
    print_array(data, n);

    return 0;
}