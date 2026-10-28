/*
Q20 Daily Question

Find the kth largest element in an array.

1. With Sorting
2. Without Sorting
3. Figure out any optimal code for this problem

Approach 1: Using Sorting
*/

#include <stdio.h>

int main()
{
    int n, k, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    /* Sort array in descending order */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("%dth largest element = %d\n", k, arr[k - 1]);

    return 0;
}

/*
Complexity Analysis:

Time Complexity  : O(n^2)
Space Complexity : O(1)

Note:
The above code uses simple sorting.
Using an efficient sorting algorithm like Merge Sort
would take O(n log n) time.
*/
