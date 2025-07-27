# 9回
- キュー(リスト)
- スタック(リスト)
- 探索
- 複製
- 逆転
## コンパイラのコマンド

### キュー

```
 gcc queue_main_1.c queue-list\ \(1\).c -o queue
```



### スタック

```
gcc stack_main_1.c stack-list\ \(1\).c -o stack
```


##　コード

<details><summary>すごく長い文章とかプログラムとか</summary>



### スタック


```
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



```

### キュー

```
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




typedef struct node * link;

struct queue{
  link front, rear;
};

void initqueue(struct queue *q){
  q->front = initlist();
  q->rear = q->front;
}

int queueempty(struct queue q){
  return q.front->next == NULL;
}

void enqueue(struct queue *q, elementtype x){
  insert(q->rear, x);
  q->rear = q->rear->next;
}

elementtype dequeue(struct queue *q){
  elementtype work;
  if(queueempty(*q)){
    printf("underflow\n");
    exit(1);
  }else{
    work = q->front->next->element;
    delete(q->front);
    if(queueempty(*q)){
      q->rear = q->front;
    }
    return work;
  }
}


```


</details>


### 例題

複製
```
gcc reidai_fukusei.c reidai.c -o reidai_fukusei
```

逆転
```
gcc reidai_gyakuten.c reidai.c -o reidai_gyakuten
```

探索
```
gcc reidai_tansaku.c reidai.c -o reidai_tansaku
```

### 実行結果


ポイントは芋づる式に出てくることdstで初期化しているので```return dst```をすることでそれに繋がっているものが全て出てくる

```

 ./reidai_fukusei 
Original list   : a->b->c
Copied list     : a->b->c

--- Inserting 'x' into ORIGINAL list ---
Original list   : x->a->b->c
Copied list     : a->b->c


./reidai_gyakuten 
--- Testing reverse() ---
Original list1  : a->b->c
Reversed list1  : c->b->a
Original list1 after reverse()  : 

--- Testing reverse2() ---
Original list2  : x->y->z
Reversed list2  : z->y->x

./reidai_tansaku 
Original list: a->b->c
Element 'b' was found.
Element 'z' was NOT found.

```