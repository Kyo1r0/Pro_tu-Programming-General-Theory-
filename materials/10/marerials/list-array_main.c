# include"list.h"

int main(void){
  list l;

  l = initlist();
 //中身がよくわからなくてもかける！！
  insert(l, first(l), 0); //lにlの先頭の場所に0を入れる
  insert(l, end(l), 1); //lにlの後ろの場所に1を入れる
  insert(l, end(l), 2); //lにlの後ろの場所に2を入れる

  printlist(l);

  return 0;
}