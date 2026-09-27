// Remove duplicates from a sorted array without using extra space

#include <stdio.h>

int main() {
    int arr[] = {1, 1, 2, 3, 3, 3, 4};
    int n = 7;
    int k = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    printf("k = %d\n", k);

    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
