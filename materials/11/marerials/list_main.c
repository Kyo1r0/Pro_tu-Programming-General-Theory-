#include "list.h"

int main(void) {
    list mylist = initlist();

    // 先頭に挿入 (endはtailノードなので、その手前に挿入)
    insert(end(mylist), 10);
    insert(end(mylist), 20);
    insert(end(mylist), 30);
    
    printf("List contents: ");
    printlist(mylist); // -> [ 10  20  30 ]

    // 20のノードを探してその手前に15を挿入
    position p20 = first(mylist)->next;
    insert(p20, 15);
    
    printf("After inserting 15: ");
    printlist(mylist); // -> [ 10  15  20  30 ]

    // 15のノードを削除
    position p15 = first(mylist)->next;
    delete_node(p15);
    
    printf("After deleting 15: ");
    printlist(mylist); // -> [ 10  20  30 ]

    return 0;
}