#ifndef SORT_VISUALIZER_H
#define SORT_VISUALIZER_H

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

typedef int recordtype;

// --- 関数プロトタイプ宣言 ---

/**
 * @brief ソートの各ステップの状態を表示するヘルパー関数
 */
void print_sort_step(recordtype a[], int n, const char *msg, int focus1, int focus2, int is_heapsort);

/**
 * @brief ヒープソートをステップ表示付きで実行する (1-based index)
 */
void heapsort_visualized(recordtype a[], int n);

/**
 * @brief マージソートをステップ表示付きで実行する (0-based index)
 */
void mergesort_visualized(recordtype a[], int l, int r, int total_n);

#endif // SORT_VISUALIZER_H