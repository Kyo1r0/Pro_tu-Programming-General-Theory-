#include <stdio.h>
#include <stdlib.h>

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

int main(int ac, char **av){
  int ndata;
  int data[SIZE];

  if(ac != 2){
    fprintf(stderr, "Usage: %s <datafile>\n", av[0]);
    exit(1);
  }

  ndata = loaddata(av[1], data);

  printdata(data, ndata);

  bubblesort(data, ndata);

  printdata(data, ndata);

  return 0;
}
