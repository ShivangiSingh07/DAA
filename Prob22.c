/*
Q22. Implementation of Bucket Sort Algorithm

Bucket Sort distributes elements into different buckets,
sorts each bucket, and then combines them to get the sorted array.
*/

#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n)
{
    int max = arr[0];
    int i, j;

    /* Find the maximum element */
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    /* Create buckets */
    int bucketCount = max / 10 + 1;
    int **bucket = (int **)malloc(bucketCount * sizeof(int *));
    int *count = (int *)calloc(bucketCount, sizeof(int));

    for (i = 0; i < bucketCount; i++)
        bucket[i] = (int *)malloc(n * sizeof(int));

    /* Put elements into buckets */
    for (i = 0; i < n; i++)
    {
        int index = arr[i] / 10;
        bucket[index][count[index]++] = arr[i];
    }

    /* Sort each bucket using insertion sort */
    for (i = 0; i < bucketCount; i++)
    {
        for (j = 1; j < count[i]; j++)
        {
            int key = bucket[i][j];
            int k = j - 1;

            while (k >= 0 && bucket[i][k] > key)
            {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = key;
        }
    }

    /* Combine all buckets */
    int k = 0;

    for (i = 0; i < bucketCount; i++)
    {
        for (j = 0; j < count[i]; j++)
            arr[k++] = bucket[i][j];
    }

    /* Free allocated memory */
    for (i = 0; i < bucketCount; i++)
        free(bucket[i]);

    free(bucket);
    free(count);
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter non-negative array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Complexity Analysis:

Average Time Complexity : O(n + k)
Worst Time Complexity   : O(n^2)
Space Complexity        : O(n + k)

where:
n = number of elements
k = number of buckets
*/
