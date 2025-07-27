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


void printlist(struct node *l){
  l = l->next; /* skip a head */
  while (l != NULL) {
        printf("%c", l->element);
        // 次のノードがあれば "->" を表示する
        if (l->next != NULL) {
            printf("->");
        }
        l = l->next; // 次のノードへ移動
    }
    printf("\n"); // 最後に見やすく改行する
}

typedef struct node * stack;

void initstack(stack *s){
  *s = initlist();
}

int stackempty(stack s){
  return s->next == NULL;
}

void push(stack s, elementtype x){
  insert(s, x);
}

elementtype pop(stack s){
  elementtype work;

  if(stackempty(s)){
    printf("underflow\n");
    exit(1);
  }else{
    work = s->next->element;
    delete(s);
    return work;
  }
}


