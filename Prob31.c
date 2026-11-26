/*
Question 31:
Find all anagrams in a string.

Example:
String  = "cbaebabacd"
Pattern = "abc"

Output:
Anagrams found at index: 0 6

Explanation:
"cba" at index 0 is an anagram of "abc".
"bac" at index 6 is an anagram of "abc".

Simple Approach:
Check every substring of length equal to pattern length.

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <string.h>

int isAnagram(char str[], char pattern[], int start, int m)
{
    int count[256] = {0};

    for (int i = 0; i < m; i++)
    {
        count[(unsigned char)pattern[i]]++;
        count[(unsigned char)str[start + i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

int main()
{
    char str[] = "cbaebabacd";
    char pattern[] = "abc";

    int n = strlen(str);
    int m = strlen(pattern);

    printf("Anagrams found at index: ");

    for (int i = 0; i <= n - m; i++)
    {
        if (isAnagram(str, pattern, i, m))
            printf("%d ", i);
    }

    return 0;
}
