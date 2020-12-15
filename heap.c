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

    return 0;
}
