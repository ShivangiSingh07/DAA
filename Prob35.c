/*
Question 35:
In an array, find the third maximum number.

Constraints:
1. Time complexity should be better than O(n log n).
2. Duplicate elements count as one entity.

Example:
Input:  [2, 2, 3, 1, 5, 5, 4]
Unique: [2, 3, 1, 5, 4]
Third maximum = 3

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[] = {2, 2, 3, 1, 5, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        long long x = arr[i];

        // Ignore duplicate values
        if (x == first || x == second || x == third)
            continue;

        if (x > first)
        {
            third = second;
            second = first;
            first = x;
        }
        else if (x > second)
        {
            third = second;
            second = x;
        }
        else if (x > third)
        {
            third = x;
        }
    }

    if (third == LLONG_MIN)
        printf("Third maximum does not exist\n");
    else
        printf("Third maximum number = %lld\n", third);

    return 0;
}
