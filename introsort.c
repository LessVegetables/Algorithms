//  introsort
//
//  main.c
//
//  Created by Daniel Gehrman
//  Copyright © 2020 Daniel Gehrman. All rights reserved.
//

#include <stdio.h>
#include <math.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void maxHeap(int *data, int end)
{
    int child, parent;
    
    for (int i = end; i > 0; i--)
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


void quickSort (int *List[], int Length, int *recursion)
{
    *recursion++;
    if (*recursion > (2 * log(Length)))
    {
        int end = Length - 1;
        while (end != 0)
        {
            maxHeap(*List, end);
            swap(&*List[0], &*List[end]);
            end--;
        }
    }
    
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
        
        quickSort (less, i + 1, recursion);
        quickSort (greater, Length - i - 1, recursion);
    }
};


int main ()
{
    
    int Length = 9, recursion = 0;
    int data[9] = { 1, 3, 7, 2, 5, 9, 6, 8, 4 };
    
    introsort(&data, Length, &recursion);
    
    for (int i = 0; i < Length; i++)
    {
    printf ("%d\t", data[i]);
    }
    return 0;
}
