#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

// --- 型定義 (Type Definitions) ---
typedef int elementtype;
typedef int position;

struct list {
    elementtype elements[MAXLENGTH];
    position last;
};

typedef struct list * list;


// --- 関数プロトタイプ (Function Prototypes) ---
list initlist(void);
void insert(list l, position p, elementtype e);
position first(list l);
position end(list l);
position next(list l, position p);
position previous(list l, position p);
elementtype retrieve(list l, position p);
void printlist(list l);

//追加関数
position locate(list l,elementtype e);
void delete(list l, position p);
void movetofront(list l, position p);


#endif // ARRAY_LIST_H