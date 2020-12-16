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

void maxHeap(int *data, int *end)
{
    int child, parent;
    
    for (int i = *end; i > 0; i--)
    {
        child = data[i];
        parent = data[(i - 1) / 2];
        
        if (parent < child)
        {
            data[i] = parent;
            data[(i - 1) / 2] = child;
        }
    }
}


int main() {
    /*
    int n = 10, data[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int end = n - 1;
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
    
    while (end != 0)
    {
        maxHeap(&data, &end);
        swap(&data[0], &data[end]);
        end--;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
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
    while (end != 0)
    {
        maxHeap(&data, &end);
        swap(&data[0], &data[end]);
        end--;
    }

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
