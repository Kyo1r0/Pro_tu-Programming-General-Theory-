#include "list_2.h" // "" で自作のヘッダファイルを指定

struct node *initlist(void) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->next = NULL;
    return n;
}

void insert(struct node *p, elementtype x) {
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->element = x;
    n->next = p->next;
    p->next = n;
}

// メモリリークを修正した版を推奨
void delete(struct node *p) {
    if (p->next != NULL) {
        struct node *temp = p->next;
        p->next = temp->next;
        free(temp); // メモリを解放
    }
}

void print_list(struct node *list) {
    struct node *p = list->next;
    while (p != NULL) {
        printf("%c", p->element);
        if (p->next != NULL) {
            printf("->");
        }
        p = p->next;
    }
    printf("\n");
}