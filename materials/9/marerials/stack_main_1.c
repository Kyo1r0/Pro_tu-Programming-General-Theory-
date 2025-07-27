#include "stack.h"

int main(void){
  stack s;

  initstack(&s);

  push(s, 'a');
  push(s, 'b');
  push(s, 'c');

    printlist(s);

  while(!stackempty(s)){
    printf("%c ", pop(s));
  }
  printf("\n");

  return 0;
}