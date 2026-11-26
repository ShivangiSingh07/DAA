/*
Question 32:
Find unique triplets in an array whose sum is 0.

Example:
Input:
2 0 3 -2 -1 0 1

Output:
-1 0 1

Note:
Duplicate triplets should not be printed.

Approach:
1. Sort the array.
2. Fix one element.
3. Use two pointers to find the other two elements.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <stdio.h>

void sortArray(int arr[], int n)
{
    // Simple sorting for demonstration
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 0, 3, -2, -1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);

    printf("Unique triplets whose sum is 0:\n");

    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0)
            {
                printf("%d %d %d\n",
                       arr[i], arr[left], arr[right]);

                left++;
                right--;

                // Skip duplicates
                while (left < right &&
                       arr[left] == arr[left - 1])
                    left++;

                while (left < right &&
                       arr[right] == arr[right + 1])
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return 0;
}
