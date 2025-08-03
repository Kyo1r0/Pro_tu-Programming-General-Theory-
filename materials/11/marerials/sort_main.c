#include "sort.h"

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