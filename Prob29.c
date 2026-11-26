/*
Question 29:
Longest Palindromic Substring

Find the longest contiguous palindrome within a string.

Example:
Input: "babad"
Output: "bab"
("aba" is also a valid answer)

Approach:
Expand Around Center

For every character:
1. Consider it as the center of an odd-length palindrome.
2. Consider the gap after it as the center of an even-length palindrome.
3. Expand left and right while characters are equal.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <string.h>

void expand(char str[], int left, int right,
            int n, int *start, int *maxLen)
{
    while (left >= 0 && right < n &&
           str[left] == str[right])
    {
        left--;
        right++;
    }

    // Length of palindrome found
    int len = right - left - 1;

    if (len > *maxLen)
    {
        *maxLen = len;
        *start = left + 1;
    }
}

int main()
{
    char str[] = "babad";
    int n = strlen(str);

    if (n == 0)
    {
        printf("String is empty\n");
        return 0;
    }

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++)
    {
        // Odd length palindrome
        expand(str, i, i, n, &start, &maxLen);

        // Even length palindrome
        expand(str, i, i + 1, n, &start, &maxLen);
    }

    printf("Longest Palindromic Substring: ");

    for (int i = start; i < start + maxLen; i++)
    {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}
