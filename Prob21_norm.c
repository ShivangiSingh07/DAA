/*
Daily Question 21

Write a program to shift all zeros at the end in an array.

1. Write normal code
2. Identify and understand best optimal code
3. Complexity analysis of both approaches
*/

#include <stdio.h>

int main()
{
    int n, i, j = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* First store all non-zero elements */
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            temp[j++] = arr[i];
    }

    /* Fill remaining positions with zeros */
    while (j < n)
        temp[j++] = 0;

    /* Copy result back to original array */
    for (i = 0; i < n; i++)
        arr[i] = temp[i];

    printf("Array after shifting zeros to the end:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Complexity Analysis:

Time Complexity  : O(n)
Space Complexity : O(n)

Reason:
We traverse the array and use an additional array of size n.
*/



