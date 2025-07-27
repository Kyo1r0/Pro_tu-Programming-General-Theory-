#include "reidai.h" // "" で自作のヘッダファイルを指定

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

typedef struct node *link;

int search(link p, elementtype x){ //0,1をかえす つまりbool
    int found = 0;
    while(!found && p->next != NULL){
        p = p->next;
        found = (p->element == x);
    }
    return found;
}


link copy(link src){
    link dst, p;
    dst = initlist(); p = dst;
    while(src->next != NULL){
        insert(p, src->next->element);
        p = p->next;
        src = src->next;
    }
    return dst;
}


link reverse(link src){
    link dst;
    dst = initlist();
    while(src->next != NULL){
        insert(dst, src->next->element);
        delete(src);
    }
    return dst;
}


link reverse2(link p){
    link head, oldp, keep;
    head= p; oldp= NULL;p= p->next;
    while(p != NULL){
        keep = oldp;
        oldp = p;
        p = p->next;
        oldp->next= keep;
    }
    head->next = oldp;
    return head;
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