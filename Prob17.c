/*
Given a string s, find the length of the longest substring without duplicate characters.
*/
#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256  // Total possible ASCII characters

// Function to find length of the longest substring without repeating characters
int lengthOfLongestSubstring(const char *s) {
    if (s == NULL) return 0;

    int lastIndex[ASCII_SIZE]; // Stores last index of each character
    for (int i = 0; i < ASCII_SIZE; i++)
        lastIndex[i] = -1;

    int maxLen = 0;  // Result
    int start = 0;   // Start index of current window

    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char ch = s[end];

        // If character is repeated within the current window, move start
        if (lastIndex[ch] >= start) {
            start = lastIndex[ch] + 1;
        }

        lastIndex[ch] = end; // Update last seen index
        int windowLen = end - start + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }

    return maxLen;
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    int result = lengthOfLongestSubstring(str);
    printf("Length of the longest substring without repeating characters: %d\n", result);

    return 0;
}
