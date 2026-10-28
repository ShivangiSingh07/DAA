/*
Daily Question 21 - Optimal Approach

Move all zeros to the end of the array while maintaining
the relative order of non-zero elements.

This solution modifies the array in-place.
*/

#include <stdio.h>

int main()
{
    int n, i, j = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /*
    j represents the position where the next
    non-zero element should be placed.
    */

    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            j++;
        }
    }

    printf("Array after shifting zeros to the end:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Complexity Analysis:

Time Complexity  : O(n)
Space Complexity : O(1)

Reason:
The array is traversed only once.
No extra array is required.

Therefore, this is the optimal approach.
*/
