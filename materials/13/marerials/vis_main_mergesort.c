#include "sort_visualizer.h"

int main(void) {
    recordtype data[] = {5, 8, 2, 6, 9, 1, 3, 4, 7, 0};
    int n = sizeof(data) / sizeof(data[0]);

    printf("--- Merge Sort Visualizer ---\n");
    print_sort_step(data, n, "Initial Array", -1, -1, 0);

    mergesort_visualized(data, 0, n - 1, n);
    
    printf("\nFinal Result:\n");
    print_sort_step(data, n, "Sorted", -1, -1, 0);

    return 0;
}