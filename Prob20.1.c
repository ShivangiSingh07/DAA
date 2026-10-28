/*
Daily Question Series
Question No. 20

Write a program to print the longest substring
without repeating a character.

Example:
Input  : abcabcbb
Output : abc

Time Complexity  : O(n)
Space Complexity : O(1)
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int last[256];
    int start = 0;
    int maxLength = 0;
    int maxStart = 0;
    int i;

    printf("Enter a string: ");
    scanf("%999s", str);

    /* Initialize last occurrence of every character */
    for (i = 0; i < 256; i++)
        last[i] = -1;

    for (i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)str[i];

        /*
        If the character is already present in the
        current substring, move start after its
        previous occurrence.
        */
        if (last[ch] >= start)
            start = last[ch] + 1;

        /* Store current position */
        last[ch] = i;

        /* Update longest substring */
        if (i - start + 1 > maxLength)
        {
            maxLength = i - start + 1;
            maxStart = start;
        }
    }

    printf("Longest substring without repeating characters: ");

    for (i = maxStart; i < maxStart + maxLength; i++)
        printf("%c", str[i]);

    printf("\nLength = %d\n", maxLength);

    return 0;
}

/*
Complexity Analysis:

Time Complexity  : O(n)

Reason:
Each character of the string is processed only once.


Space Complexity : O(1)

Reason:
The last[] array has a fixed size of 256 characters.
Its size does not depend on the input size.


Approach:
Sliding Window + Last Occurrence Array

Example:

Input:
abcabcbb

Processing:
abc -> no repeating characters
Next 'a' is repeated, so the window moves forward.

Output:
abc

Length:
3
*/
