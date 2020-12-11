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
}







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
	FILE *output = fopen("outputQuick.txt", "w");
	
	// getting the data from input file
 
	int Length;
 
	fscanf(input, "%d", &Length);
 
	int data[Length];
	
 
	for (int i = 0; i < Length; i++)
	{
		fscanf(input, "%d", &data[i]);
	}
	fclose(input);
	
	// running the algorithm
	quickSort(data, Length);
	// outputting the data into output file
 
	for (int i = 0; i < Length; i++)
	{
		fprintf(output, "%d\t", data[i]);
	}
	fprintf(output, "\n");
	fclose(output);

	return 0;
}
