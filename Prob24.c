/*
Q24. A peak element is an element that is strictly greater than its
neighbors. Given a 0-indexed integer array nums, find a peak element,
and return its index. If the array contains multiple peaks, return
the index to any of the peaks.

Constraint: The complexity of the code should be O(log n).
*/

#include <stdio.h>

int findPeakElement(int nums[], int n)
{
    int low = 0, high = n - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int peakIndex = findPeakElement(nums, n);

    printf("Peak element = %d\n", nums[peakIndex]);
    printf("Peak index = %d\n", peakIndex);

    return 0;
}

/*
Complexity Analysis:

Time Complexity  : O(log n)
Space Complexity : O(1)

Binary search is used to reduce the search space by half
in each iteration.
*/
