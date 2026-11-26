/*
Question 28:
Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps.

Find the number of distinct ways to climb to the top.

Example:
n = 3

Ways:
1 + 1 + 1
1 + 2
2 + 1

Output: 3

Logic:
ways(n) = ways(n - 1) + ways(n - 2)

This follows the Fibonacci pattern.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

long long climbStairs(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    long long first = 1;
    long long second = 2;
    long long current;

    for (int i = 3; i <= n; i++)
    {
        current = first + second;

        first = second;
        second = current;
    }

    return second;
}

int main()
{
    int n;

    printf("Enter number of steps: ");
    scanf("%d", &n);

    printf("Number of distinct ways = %lld\n",
           climbStairs(n));

    return 0;
}
