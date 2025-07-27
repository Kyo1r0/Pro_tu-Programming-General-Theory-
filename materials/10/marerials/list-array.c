#include "list.h"

#define MAXLENGTH 1000

typedef int elementtype;

typedef int position;

typedef struct list * list;


list initlist(void){
  list p;
  p = (list)malloc(sizeof(struct list));
  p->last = -1;
  return p;
}

void insert(list l, position p, elementtype e){
  position i;
  if(l->last >= MAXLENGTH-1){
    printf("overflow\n");
    exit(1);
  }else if(p < 0 || p > l->last + 1){
    printf("illegal position\n");
    exit(1);
  }else{
    for(i = l->last; i >= p; i--){
      l->elements[i+1] = l->elements[i];
    }
    l->elements[p] = e;
    l->last++;
  }
}

position first(list l){
  return 0;
}

position end(list l){
  return l->last + 1;
}

position next(list l, position p){
  if(p < 0 || p > l->last){
    printf("illegal position\n");
    exit(1);
  }else{
    return p + 1;
  }
}

position previous(list l, position p){
  if(p < 1 || p > l->last){
    printf("illegal position\n");
    exit(1);
  }else{
    return p - 1;
  }
}

elementtype retrieve(list l, position p){
  if(p < 0 || p > l->last){
    printf("illegal position\n");
    exit(1);
  }

  return l->elements[p];
}

void printlist(list l){
  position i;
  for(i = 0; i <= l->last; i++){
    printf("%d ", retrieve(l, i));
  }
  printf("\n");
}


