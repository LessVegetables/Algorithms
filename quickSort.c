//
//  main.c
//
//  Created by Daniel Gehrman
//  Copyright © 2020 Daniel Gehrman. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void quickSort (int *List[], int Length)
{
    if (Length > 1)
    {
        int i = -1, pivot = *List[Length - 1];
        
        for (int j = 0; j < Length - 1; j++)
        {
            if (*List[j] < pivot)
            {
                i++;
                if (*List[i] != *List[j])
                {
                    swap(&*List[j], &*List[i]);
                }
            }
        }
        
        swap(&*List[i + 1], &*List[Length - 1]);
        
        printf("%d\n", i);
        int less[i + 1];
        int greater[Length - i - 1];
        
        for (int a = 0; a <= i + 1; a++)
        {
            less[a] = *List[a];
        }
        
        for (int a = i + 1; a < Length; a++)
        {
            greater[a - i - 1] = *List[a];
        }
        
        quickSort (less, i + 1);
        quickSort (greater, Length - i - 1);
    }
    
    for (int a = 0; a < Length; a++)
    {
        printf ("%d\t", *List[a]);
    }
    return;
};



int main ()
{
    /*
    int Length = 9;
    int data[9] = { 1, 3, 7, 2, 5, 9, 6, 8, 4 };
    
    quickSort (data, Length);
    for (int i = 0; i < Length; i++)
    {
        printf ("%d\t", data[i]);
    }
    */

    FILE *input = fopen("input.txt", "r");

    // getting data from input file
    int Length;
    fscanf(input, "%d", &Length);
    int data[Length];
    for (int i = 0; i < Length; i++)
    {
        fscanf(input, "%d", &data[i]);

    }
    fclose(input);


    // starting timer
    struct timeval stop, start;
    gettimeofday(&start, NULL);

    // running the algorithm
    quickSort (data, Length); ////////////////////////////////////////////////////////

    // ending timer
    gettimeofday(&stop, NULL);
    int Time = (stop.tv_usec - start.tv_usec) / 60;

    FILE *output = fopen("output.txt", "w");
    // outputting the data into output file
    fprintf(output, "It took %d, %d milliseconds\n", Length, Time);
    fprintf(output, "%d\t", data[0]);
    for (int i = 1; i < Length; i++)
    {
        fprintf(output, "%d\t", data[i]);

        // checker
        if (data[i - 1] > data[i])
        {
            printf("SORTING STOPPED DUE TO UNEXPECTED ERROR\nPLEASE STAY CALM\nREBOOTING COMPUTER\nIF ERROR DOESN'T GO AWAY, PLEASE CONTACT OUR NEAREST INDIAN IT SPECIALIST\n\n");
            printf("ERROR OCCURRED IN %d AND %d\n", data[i - 1], data[i]);
            break;
        }
    }
    fprintf(output, "\n");
    fclose(output);

    return 0;
}
