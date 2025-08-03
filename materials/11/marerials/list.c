#include "list.h"

// リストの初期化（双方向リストではheadとtailのダミーノードを作るのが一般的）
list initlist(void) {
    list head = (list)malloc(sizeof(*head));
    list tail = (list)malloc(sizeof(*tail));
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
    return head; // headへのポインタをリストとして返す
}

// pの「前」に新しい要素eを挿入する
void insert(position p, elementtype e) {
    position n = (position)malloc(sizeof(*n));
    n->element = e;
    
    n->next = p;
    n->prev = p->prev;
    p->prev->next = n;
    p->prev = n;
}

void delete_node(position p) {
    if (p->prev == NULL || p->next == NULL) return; // ダミーノードは削除しない
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

elementtype retrieve(position p) {
    return p->element;
}

position first(list l) {
    return l->next;
}

// endはtailノードを指すことにする
position end(list l) {
    position p = l;
    while(p->next != NULL) {
        p = p->next;
    }
    return p;
}

void printlist(list l) {
    position p = first(l);
    printf("[");
    while (p->next != NULL) { // tailノpードの手前まで
        printf(" %d ", retrieve(p));
        p = p->next;
    }
    printf("]\n");
}