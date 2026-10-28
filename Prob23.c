/*
Q23. Given an integer array nums, move all the even integers at the
beginning of the array followed by all the odd integers.

Do the complexity analysis of your code also.

LeetCode Problem: Sort Array By Parity
*/

#include <stdio.h>

void sortArrayByParity(int nums[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        /* Find an odd number from the left side */
        while (left < right && nums[left] % 2 == 0)
            left++;

        /* Find an even number from the right side */
        while (left < right && nums[right] % 2 != 0)
            right--;

        /* Swap odd and even elements */
        if (left < right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }
    }
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

    sortArrayByParity(nums, n);

    printf("Array after moving even elements before odd elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}

/*
Complexity Analysis:

Time Complexity  : O(n)
- Each element is checked at most once using the two pointers.

Space Complexity : O(1)
- The array is modified in-place and no extra array is used.
*/
