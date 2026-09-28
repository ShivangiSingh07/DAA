// Q19. Check whether a substring of the main string is an anagram of the given string.

#include <stdio.h>
#include <string.h>

int main() {
    char mainStr[100], subStr[100];
    int found = 0;

    printf("Enter main string: ");
    scanf("%s", mainStr);

    printf("Enter substring: ");
    scanf("%s", subStr);

    int n = strlen(mainStr);
    int m = strlen(subStr);

    for (int i = 0; i <= n - m; i++) {
        int freq1[256] = {0};
        int freq2[256] = {0};

        for (int j = 0; j < m; j++) {
            freq1[(unsigned char)mainStr[i + j]]++;
            freq2[(unsigned char)subStr[j]]++;
        }

        int same = 1;

        for (int j = 0; j < 256; j++) {
            if (freq1[j] != freq2[j]) {
                same = 0;
                break;
            }
        }

        if (same) {
            printf("Anagram substring found: ");

            for (int j = 0; j < m; j++)
                printf("%c", mainStr[i + j]);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("No anagram substring found.");

    return 0;
}
