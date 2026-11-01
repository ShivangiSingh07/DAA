/*
QUESTION 26:
Study and implement the Dutch National Flag Algorithm.
Identify 2-3 case studies where it is applicable.

-------------------------------------------------------
AIM:
To implement the Dutch National Flag Algorithm in C
and understand its applications.

-------------------------------------------------------
THEORY:
The Dutch National Flag Algorithm is used to arrange
elements into three different groups.

For an array containing 0, 1 and 2:

0 -> First group
1 -> Middle group
2 -> Last group

The algorithm uses three pointers:
low  -> position for 0
mid  -> current element
high -> position for 2

-------------------------------------------------------
ALGORITHM:

Step 1: Set low = 0, mid = 0 and high = n - 1.

Step 2: Repeat while mid <= high.

Step 3: If arr[mid] == 0,
        swap arr[mid] with arr[low].
        Increase low and mid.

Step 4: If arr[mid] == 1,
        increase mid.

Step 5: If arr[mid] == 2,
        swap arr[mid] with arr[high].
        Decrease high.

Step 6: Stop when mid > high.

Time Complexity  : O(n)
Space Complexity : O(1)

-------------------------------------------------------
CASE STUDIES / APPLICATIONS:

1. SORTING 0, 1 AND 2:
   The algorithm can efficiently sort an array
   containing only three different values.

2. STUDENT CLASSIFICATION:
   Students can be divided into three categories:
   Fail, Pass and Distinction.

3. TASK PRIORITY MANAGEMENT:
   Tasks can be classified as:
   High Priority, Medium Priority and Low Priority.

-------------------------------------------------------
PROGRAM:
*/

#include <stdio.h>

/* Function to swap two numbers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function implementing Dutch National Flag Algorithm */
void dutchNationalFlag(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            /* Move 0 to the left side */
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            /* 1 belongs in the middle */
            mid++;
        }
        else if (arr[mid] == 2)
        {
            /* Move 2 to the right side */
            swap(&arr[mid], &arr[high]);
            high--;
        }
        else
        {
            /* Invalid input */
            printf("Invalid input! Enter only 0, 1 and 2.\n");
            return;
        }
    }
}

int main()
{
    int arr[100];
    int n, i;

    /* Taking number of elements from user */
    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Taking array elements */
    printf("Enter %d elements (only 0, 1 and 2):\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Calling Dutch National Flag Algorithm */
    dutchNationalFlag(arr, n);

    /* Displaying the sorted array */
    printf("\nArray after applying Dutch National Flag Algorithm:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

/*
-------------------------------------------------------
SAMPLE INPUT:

Enter number of elements: 8
Enter 8 elements:
2 0 1 2 1 0 2 0

SAMPLE OUTPUT:

Array after applying Dutch National Flag Algorithm:
0 0 0 1 1 2 2 2

-------------------------------------------------------
CONCLUSION:

The Dutch National Flag Algorithm successfully divides
an array into three groups in a single traversal.

It has O(n) time complexity and O(1) space complexity.

It can be used for:
1. Sorting arrays containing three types of elements.
2. Student result classification.
3. Task priority management.
-------------------------------------------------------
*/
