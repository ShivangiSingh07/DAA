/*
Question 30:
Given an unsorted array containing positive and negative numbers,
find the first missing positive number.

Example:
Input:  {3, 4, -1, 1}
Output: 2

Explanation:
Positive numbers are 1, 3, 4.
So the first missing positive number is 2.

Approach:
Use an extra array to mark which positive numbers are present.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int arr[], int n)
{
    // We only need to check numbers from 1 to n
    int *present = (int *)calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            present[arr[i]] = 1;
        }
    }

    // Find first positive number not present
    for (int i = 1; i <= n; i++)
    {
        if (present[i] == 0)
        {
            free(present);
            return i;
        }
    }

    free(present);

    // If 1 to n are present, answer is n + 1
    return n + 1;
}

int main()
{
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("First missing positive number = %d\n",
           firstMissingPositive(arr, n));

    return 0;
}
