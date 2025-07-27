#include "reidai.h"

int main(void) {
    // 1. 元となるリストを作成
    link original_list = initlist();
    insert(original_list, 'c');
    insert(original_list, 'b');
    insert(original_list, 'a'); // a -> b -> c

    printf("Original list\t: ");
    print_list(original_list);

    // 2. リストを複製
    link copied_list = copy(original_list);
    printf("Copied list\t: ");
    print_list(copied_list);

    // 3. 複製元にのみ新しい要素を追加
    printf("\n--- Inserting 'x' into ORIGINAL list ---\n");
    insert(original_list, 'x');

    // 4. 両方のリストを再度表示
    printf("Original list\t: ");
    print_list(original_list); // 'x'が追加されている
    printf("Copied list\t: ");
    print_list(copied_list);   // 'x'が追加されていないことを確認

    return 0;
}