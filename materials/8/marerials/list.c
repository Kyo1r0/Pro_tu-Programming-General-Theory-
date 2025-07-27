#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

struct node {
  elementtype element;
  struct node *next;
};

struct node *initlist(void){
  struct node *n;

  n = (struct node *)malloc(sizeof(struct node));
  n->next = NULL;
  return n;
}

void insert(struct node *p, elementtype x){
  struct node *n;

  n = (struct node *)malloc(sizeof(struct node));
  n->element = x;
  n->next = p->next;
  p->next = n;
}

void delete(struct node *p){
  if(p->next != NULL){
    p->next = p->next->next;
  }
}

void print_list(struct node *list) {
    // ヘッダの次の、実際のデータを持つノードから始める
    struct node *p = list->next;

    while (p != NULL) {
        printf("%c", p->element);
        // 次のノードがあれば "->" を表示する
        if (p->next != NULL) {
            printf("->");
        }
        p = p->next; // 次のノードへ移動
    }
    printf("\n"); // 最後に見やすく改行する
}



int main(void){
  struct node *list;
  
  int n;
  list = initlist();

  insert(list, 'a');
  insert(list, 'b');

  print_list(list);
  //printf("%c\n", list->next->element);

  return 0;
}
