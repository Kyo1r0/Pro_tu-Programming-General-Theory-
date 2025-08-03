#include "sorts.h"

// --- 共通ヘルパー関数 ---
void swap(recordtype *a, recordtype *b) {
    recordtype tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(recordtype a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// --- ヒープソート実装 (1-based index) ---
void pushdown(recordtype a[], int first, int last) {
    int r = first;
    while (2 * r <= last) {
        int k = 2 * r;
        if (k < last && a[k] < a[k + 1]) {
            k++;
        }
        if (a[r] >= a[k]) {
            break;
        }
        swap(&a[r], &a[k]);
        r = k;
    }
}

void heapsort(recordtype a[], int n) {
    int i;
    // 配列をヒープ構造にする
    for (i = n / 2; i >= 1; i--) {
        pushdown(a, i, n);
    }
    // ソート実行
    for (i = n; i >= 2; i--) {
        swap(&a[1], &a[i]);
        pushdown(a, 1, i - 1);
    }
}

// --- マージソート実装 (0-based index) ---
void mergesort(recordtype a[], int l, int r) {
    int i, j, k, m;
    recordtype b[LIMIT];
    if (l < r) {
        m = (r + l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        for (i = m; i >= l; i--) {
            b[i] = a[i];
        }
        for (j = m + 1; j <= r; j++) {
            b[r + m + 1 - j] = a[j];
        }
        i = l;
        j = r;
        for (k = l; k <= r; k++) {
            if (b[i] < b[j]) {
                a[k] = b[i++];
            } else {
                a[k] = b[j--];
            }
        }
    }
}



 // --- マージ処理で使うダミーノード（番兵） ---
// このファイル内でのみ使用する
static struct node z_node;
static link z = &z_node;

/**
 * @brief 2つのソート済みリストaとbをマージする
 */
link merge_list(link a, link b) {
    link c = z; // 作業用ポインタをダミーノードzに初期化
    z->element = INT_MAX;// 番兵の値を設定

    // aとbの小さい方をcの次につなげていく
    while (a != z && b != z) {
        if (a->element < b->element) {
            c->next = a; c = a; a = a->next;
        } else {
            c->next = b; c = b; b = b->next;
        }
    }
    // 残ったリストをつなげる (aかbのどちらかはzになっている)
    c->next = (a == z) ? b : a;

    // ダミーノードzの次が、マージ済みリストの本当の先頭
    return z->next;
}

/**
 * @brief 連結リストをマージソートで並べ替える
 */
list mergesort_list(list l) {
    // リストが空か、要素が1つなら、すでにソート済み
    if (l == NULL || l->next == NULL) {
        return l;
    }

    // 1. リストを中央で2つに分割する (slow/fast ポインタ法)
    link slow = l, fast = l->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    link list_b = slow->next; // 2つ目のリストの先頭
    slow->next = NULL;       // 1つ目のリストをここで分断
    link list_a = l;

    // 2. 分割した2つのリストをそれぞれ再帰的にソート
    list_a = mergesort_list(list_a);
    list_b = mergesort_list(list_b);

    // 最後に番兵ノードを末尾に接続
    link tail_a = list_a, tail_b = list_b;
    while(tail_a->next != NULL) tail_a = tail_a->next;
    while(tail_b->next != NULL) tail_b = tail_b->next;
    tail_a->next = z;
    tail_b->next = z;

    // 3. ソート済みの2つのリストをマージして返す
    return merge_list(list_a, list_b);
}


// --- テスト用のヘルパー関数 ---
list create_list_from_array(elementtype data[], int n) {
    if (n == 0) return NULL;
    list head = (link)malloc(sizeof(*head));
    head->element = data[0];
    link p = head;
    for (int i = 1; i < n; i++) {
        p->next = (link)malloc(sizeof(*p->next));
        p = p->next;
        p->element = data[i];
    }
    p->next = NULL;
    return head;
}

void print_linked_list(list l) {
    printf("[ ");
    while (l != NULL) {
        printf("%d ", l->element);
        l = l->next;
    }
    printf("]\n");
}



