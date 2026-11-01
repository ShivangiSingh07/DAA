/*
QUESTION 27:

A mall has a 2D parking layout (rows and columns).
Some spots are empty (0), and some are occupied (1).

Write a system that automatically finds the first
available parking spot for an arriving car and parks it.

-------------------------------------------------------
AIM:

To implement a parking management system using a
2D array in C that finds the first empty parking spot
and assigns it to an arriving car.

-------------------------------------------------------
THEORY:

The parking lot is represented using a 2D array.

0 -> Parking spot is EMPTY
1 -> Parking spot is OCCUPIED

The program searches the parking lot row by row.

When the first 0 is found:
1. The position is displayed.
2. The value is changed from 0 to 1.
3. The car is considered parked.

If no 0 is found, the parking lot is full.

-------------------------------------------------------
ALGORITHM:

Step 1: Start.

Step 2: Create a 2D array representing the parking lot.

Step 3: Traverse the array row by row and column
        by column.

Step 4: Check whether the current spot contains 0.

Step 5: If it contains 0:
        Change the value from 0 to 1.
        Display the parking position.
        Stop searching.

Step 6: If no empty spot is found, display
        "Parking is Full".

Step 7: Display the updated parking layout.

Step 8: Stop.

-------------------------------------------------------
PROGRAM:
*/

#include <stdio.h>

#define ROWS 3
#define COLS 4

int main()
{
    /* 0 = Empty spot, 1 = Occupied spot */
    int parking[ROWS][COLS] =
    {
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 0}
    };

    int i, j;
    int found = 0;

    /* Display the parking layout before parking */
    printf("Current Parking Layout:\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", parking[i][j]);
        }
        printf("\n");
    }

    /*
       Search for the first available parking spot.
       The search starts from the first row and
       checks each column one by one.
    */
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (parking[i][j] == 0)
            {
                /* Park the car by changing 0 to 1 */
                parking[i][j] = 1;

                printf("\nFirst available spot found!\n");

                /*
                   +1 is used because array indexes start
                   from 0, but parking rows/columns are
                   easier to understand starting from 1.
                */
                printf("Car parked at Row %d, Column %d\n",
                       i + 1, j + 1);

                found = 1;
                break;
            }
        }

        /* Stop searching after finding a spot */
        if (found == 1)
        {
            break;
        }
    }

    /* If no empty parking spot was found */
    if (found == 0)
    {
        printf("\nParking is Full!\n");
    }

    /* Display updated parking layout */
    printf("\nUpdated Parking Layout:\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", parking[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
-------------------------------------------------------
SAMPLE PARKING LAYOUT:

1 1 0 1
1 0 0 1
1 1 0 0

Here, the first available spot (0) is located at:

Row 1, Column 3

-------------------------------------------------------
SAMPLE OUTPUT:

Current Parking Layout:
1 1 0 1
1 0 0 1
1 1 0 0

First available spot found!
Car parked at Row 1, Column 3

Updated Parking Layout:
1 1 1 1
1 0 0 1
1 1 0 0

-------------------------------------------------------
TIME COMPLEXITY:

Worst Case: O(ROWS * COLS)

This happens when the program has to check every
parking spot.

-------------------------------------------------------
CONCLUSION:

The program uses a 2D array to represent a mall
parking lot.

It searches for the first empty spot (0) and
automatically parks the arriving car by changing
the value from 0 to 1.

If all parking spots contain 1, the program displays
"Parking is Full".
-------------------------------------------------------
*/
