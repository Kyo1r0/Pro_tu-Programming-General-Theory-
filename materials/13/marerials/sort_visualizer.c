#include "sort_visualizer.h"
#include <string.h> // sprintf用

// ======== このファイル内だけで使われるヘルパー関数 ========

// ステップ表示関数
void print_sort_step(recordtype a[], int n, const char *msg, int focus1, int focus2, int is_heapsort) {
    int i_start = is_heapsort ? 1 : 0;
    int i_end = is_heapsort ? n + 1 : n;
    printf("%-28s: [", msg);
    for (int i = i_start; i < i_end; i++) {
        printf("%3d", a[i]);
        if (i == focus1 || i == focus2) printf("*");
        else printf(" ");
    }
    printf("]\n");
}

// swap関数
void swap(recordtype *a, recordtype *b) {
    recordtype tmp = *a;
    *a = *b;
    *b = tmp;
}


// ======== ヒープソート関連 (1-based index) ========
void pushdown_visualized(recordtype a[], int first, int last, int n_total) {
    int r = first;
    char msg[100];
    while (2 * r <= last) {
        int k = 2 * r;
        if (k < last && a[k] < a[k + 1]) k++;
        
        sprintf(msg, "pushdown(r=%d), is a[%d]>=a[%d]?", r, r, k);
        print_sort_step(a, n_total, msg, r, k, 1);

        if (a[r] >= a[k]) break;

        swap(&a[r], &a[k]);
        sprintf(msg, "-> swapped a[%d] and a[%d]", r, k);
        print_sort_step(a, n_total, msg, r, k, 1);
        r = k;
    }
}

void heapsort_visualized(recordtype a[], int n) {
    printf("--- Phase 1: Heap Construction ---\n");
    for (int i = n / 2; i >= 1; i--) {
        pushdown_visualized(a, i, n, n);
    }
    printf("--- Heap Constructed ---\n");

    printf("\n--- Phase 2: Sorting ---\n");
    for (int i = n; i >= 2; i--) {
        char msg[100];
        sprintf(msg, "Move max a[1] to a[%d]", i);
        swap(&a[1], &a[i]);
        print_sort_step(a, n, msg, 1, i, 1);
        pushdown_visualized(a, 1, i - 1, n);
    }
}


// ======== マージソート関連 (0-based index) ========
void mergesort_visualized(recordtype a[], int l, int r, int total_n) {
    if (l < r) {
        int m = (l + r) / 2;
        char msg[100];
        recordtype b[LIMIT];

        mergesort_visualized(a, l, m, total_n);
        mergesort_visualized(a, m + 1, r, total_n);

        sprintf(msg, "--- Merging a[%d..%d] & a[%d..%d]", l, m, m+1, r);
        print_sort_step(a, total_n, msg, -1, -1, 0);

        for (int i = m; i >= l; i--) b[i] = a[i];
        for (int j = m + 1; j <= r; j++) b[r + m + 1 - j] = a[j];
        
        int i = l, j = r;
        for (int k = l; k <= r; k++) {
            if (b[i] < b[j]) a[k] = b[i++];
            else a[k] = b[j--];
        }

        sprintf(msg, "-> Merged a[%d..%d]", l, r);
        print_sort_step(a, total_n, msg, l, r, 0);
    }
}