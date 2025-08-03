#　やったこと

- 双方向リスト
- 基本的なアルゴリズム(バカソート)


## 抽象データ型のリスト
list ,positon,linkは同じ型

```
struct node {
    elementtype element;
    struct node *next, *prev;
};
typedef struct node *link;
typedef link list;
typedef link position;
```

## コンパイラ
```
gcc list-array.c list-array_main.c -o list-array
```
並べるといい
## 実行方法
```
./sort data10.txt 
```
## 実行結果

```
 ./sort data10.txt 
8 1 3 7 10 6 4 9 2 5 
1 2 3 4 5 6 7 8 9 10 
```

