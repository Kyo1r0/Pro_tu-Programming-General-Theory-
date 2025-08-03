#include "sort_visualizer.h"

int main(void) {
    // 1-based indexで扱うため、0番目はダミー
    recordtype data[] = {-99, 5, 8, 2, 6, 9, 1, 3, 4, 7, 0}; 
    int n = (sizeof(data) / sizeof(data[0])) - 1;

    printf("--- Heap Sort Visualizer ---\n");
    print_sort_step(data, n, "Initial Array", -1, -1, 1);
    
    heapsort_visualized(data, n);
    
    printf("\nFinal Result:\n");
    print_sort_step(data, n, "Sorted", -1, -1, 1);
    
    return 0;
}