#include "sort.h"
#define SIZE 10000
#define LINELEN 20

void printdata(int data[], int n){
  int i;
  for(i = 1; i <= n; i++){
    printf("%d ", data[i]);
  }
  printf("\n");
}

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubblesort(int a[], int n){
  int i, j;

  for(i = 1; i < n; i++){
    for(j = n; j >= i+1; j--){
      if(a[j] < a[j-1]){
        swap(&a[j], &a[j-1]);
      }
    }
  }
}

void selection_sort(int a[], int n){
int i, j, minindex;
for(i = 1; i < n; i++){
minindex = i;
for(j = i+1; j <= n; j++){
if(a[j].key < a[minindex].key){ minindex = j; }
}
swap(&a[minindex], &a[i]);
}
}

void insertion_sort(int a[], int n){
int i, j; recordtype v;
a[0].key = -10000; /* keyとしてあり得る最小値 */
for(i = 2; i <= n; i++){
v = a[i]; j = i;
while(a[j-1].key > v.key){ a[j] = a[j-1]; j--; }
a[j] = v;
}
}


int loaddata(char *filename, int data[]){
  FILE *fp;
  char line[LINELEN];
  int pos;

  fp = fopen(filename, "r");
  if(fp == NULL){
    fprintf(stderr, "Can't open file: %s\n", filename);
    exit(1);
  }

  pos = 1;
  while(fgets(line, sizeof(line), fp) != NULL){
    sscanf(line, "%d", &data[pos]);
    pos++;
  }

  fclose(fp);

  return pos-1;
}

void bubblesort_print(int a[], int n) {
    int i, j;
    char message[100]; // メッセージを格納するためのバッファ

    for (i = 1; i < n; i++) {
        printf("--- Pass %d ---\n", i);
        for (j = n; j >= i + 1; j--) {
            // 比較するステップを表示
            sprintf(message, "Comparing a[%d] and a[%d]", j, j - 1);
            print_step(a, n, message, j, j - 1);

            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]);
                // 交換したステップを表示
                sprintf(message, "-> Swapped");
                print_step(a, n, message, j, j - 1);
            }
        }
    }
}

void print_step(int data[], int n, char *msg, int focus1, int focus2) {
    int i;
    printf("%-25s: [", msg); // メッセージを左詰25文字で表示
    for (i = 1; i <= n; i++) {
        printf("%3d", data[i]);
        // 注目しているインデックスの要素に目印（*）を付ける
        if (i == focus1 || i == focus2) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("]\n");
}
