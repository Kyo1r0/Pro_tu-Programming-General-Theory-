#include "sorts.h"

int main(void) {
    elementtype data[] = {5, 8, 2, 6, 9, 1, 3, 4, 7, 0};
    int n = sizeof(data) / sizeof(data[0]);

    // 1. 配列からテスト用の連結リストを作成
    list mylist = create_list_from_array(data, n);
    
    printf("Linked List Merge Sort\n");
    printf("Before: ");
    print_linked_list(mylist);

    // 2. マージソートを実行
    mylist = mergesort_list(mylist);

    printf("After:  ");
    print_linked_list(mylist);

    return 0;
}