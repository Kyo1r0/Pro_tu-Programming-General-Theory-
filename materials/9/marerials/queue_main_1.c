# include "queue.h"

int main(void){
  struct queue q;

  initqueue(&q);

  enqueue(&q, 'a');
  enqueue(&q, 'b');
  enqueue(&q, 'c');

 printlist(q.front);

  while(!queueempty(q)){
    printf("%c ", dequeue(&q));
  }
  printf("\n");

  return 0;
}
