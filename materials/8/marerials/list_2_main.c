#include "list_2.h" // list.h をインクルードする

int main(void) {
    struct node *list;
    
    list = initlist();

    insert(list, 'a');
    insert(list, 'b');
    insert(list, 'c');

    printf("Current list: ");
    print_list(list); // c->b->a と表示される

    delete(list); // 先頭の 'c' を削除

    printf("After deletion: ");
    print_list(list); // b->a と表示される

    return 0;
}