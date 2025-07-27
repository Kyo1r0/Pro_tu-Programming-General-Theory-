#include "reidai.h"

int main(void) {
    // --- reverse関数のテスト (破壊的) ---
    printf("--- Testing reverse() ---\n");
    link list1 = initlist();
    insert(list1, 'c');
    insert(list1, 'b');
    insert(list1, 'a'); // a -> b -> c

    printf("Original list1\t: ");
    print_list(list1);

    link reversed_list1 = reverse(list1);
    printf("Reversed list1\t: ");
    print_list(reversed_list1);

    printf("Original list1 after reverse()\t: ");
    print_list(list1); // 元のリストが空になることを確認
    printf("\n");


    // --- reverse2関数のテスト (非破壊的・インプレース) ---
    printf("--- Testing reverse2() ---\n");
    link list2 = initlist();
    insert(list2, 'z');
    insert(list2, 'y');
    insert(list2, 'x'); // x -> y -> z

    printf("Original list2\t: ");
    print_list(list2);

    reverse2(list2); // 戻り値を受け取らなくてもlist2自体が変更される
    printf("Reversed list2\t: ");
    print_list(list2);

    return 0;
}