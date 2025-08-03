#include "sort_utils.h"

int main(void) {
    recordtype data[] = {5, 8, 2, 6, 9, 1, 3, 4, 7, 0};
    int n = sizeof(data) / sizeof(data[0]);

   
    shellsort(data, n);

    print_vec(data,n);

    return 0;
}