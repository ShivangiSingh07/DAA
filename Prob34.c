/*
Question 34:
Find the square root of a number without using any inbuilt square root function.

Approach:
Use Binary Search to find the square root.

Example:
Input: 25
Output: Square root = 5.000000

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <stdio.h>

int main()
{
    double num, low, high, mid;
    double precision = 0.000001;

    printf("Enter a number: ");
    scanf("%lf", &num);

    if (num < 0)
    {
        printf("Square root of a negative number is not a real number.\n");
        return 0;
    }

    if (num == 0 || num == 1)
    {
        printf("Square root = %.6lf\n", num);
        return 0;
    }

    low = 0;
    high = (num > 1) ? num : 1;

    while ((high - low) > precision)
    {
        mid = low + (high - low) / 2;

        if (mid > num / mid)
            high = mid;
        else
            low = mid;
    }

    printf("Square root = %.6lf\n", (low + high) / 2);

    return 0;
}
