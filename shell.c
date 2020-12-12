//
//  main.c
//
//  Created by Daniel Gehrman
//  Copyright © 2020 Daniel Gehrman. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort (int* List, int Length)
{
    for (int step = Length / 2; step >= 1; step /= 2)
    {
        for (int i = step; i < Length; i++)
        {
            int cur = i - step;
            while ((List[cur] > List[cur + step]) && (cur >= 0))
            {
                swap(&List[cur], &List[cur + step]);
                cur -= step;
            }
        }
    }
}


int main ()
{
    /*
    int Length = 9;
    int data[9] = { 1, 3, 7, 2, 5, 9, 6, 8, 4 };
    
    shellSort (data, Length);
    
    for (int i = 0; i < Length; i++)
    {
        printf ("%d\t", data[i]);
    }
    
    */
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    // getting data from input file
    int Length;
    fscanf(input, "%d", &Length);
    int data[Length];
    for (int i = 0; i < Length; i++)
    {
        fscanf(input, "%d", &data[i]);
        
    }
    fclose(input);
    
    // running the algorithm
    shellSort (data, Length);
    
    // outputting the data into output file
    for (int i = 0; i < Length; i++)
    {
        fprintf(output, "%d\t", data[i]);
        fprintf(output, "\n");
        
    }
    fclose(outputfile)
    
    
    return 0;
}
