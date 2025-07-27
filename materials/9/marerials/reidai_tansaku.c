#include "reidai.h"

int main(void) {
    // リストの準備
    link list = initlist();
    insert(list, 'c');
    insert(list, 'b');
    insert(list, 'a'); // リストは a -> b -> c の順になる

    printf("Original list: ");
    print_list(list);

    // --- 探索のテスト ---
    elementtype target1 = 'b'; // 見つかるはずの要素
    elementtype target2 = 'z'; // 見つからないはずの要素

    // target1 ('b') の探索
    if (search(list, target1)) {
        printf("Element '%c' was found.\n", target1);
    } else {
        printf("Element '%c' was NOT found.\n", target1);
    }

    // target2 ('z') の探索
    if (search(list, target2)) {
        printf("Element '%c' was found.\n", target2);
    } else {
        printf("Element '%c' was NOT found.\n", target2);
    }

    return 0;
}