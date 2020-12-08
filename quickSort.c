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
      int i = -1, pivot = List[Length - 1];

      for (int j = 0; j < Length - 1; j++)
      {
          if (List[j] < pivot)
          {
              i++;
              swap(&List[j], &List[i]);
          }
      }

      swap(&List[i + 1], &List[Length - 1]);
      
      printf("%d\n", i);
      int less[i + 1];
      int greater[Length - i - 2];

      for (int a = 0; a <= i + 1; a++)
      {
          less[a] = List[a];
          printf ("%d\t", List[a]);
      }
      printf("\n");

      for (int a = i + 2; a < Length; a++)
      {
          greater[a] = List[a];
          printf ("%d\t", List[a]);
      }
      printf("\n");

      quickSort (less, i + 1);
      quickSort (greater, Length - i - 2);
    }
    
    for (int a = 0; a < Length; a++)
    {
      printf ("%d\t", List[a]);
    }
    printf("\n");
}


int main ()
{
    /*
	int Length = 9;
    int data[Length] = { 1, 3, 7, 2, 5, 9, 6, 8, 4 };
    
    quickSort (data[], Length);

    for (int i = 0; i < Length; i++)
    {
      printf ("%d\t", data[i]);
    }
	*/
	
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	
	if (in_file == NULL || out_file == NULL) 
	{
		printf("Error! Could not open file\n"); 
		exit(-1); // must include stdlib.h 
	}
	
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
    quickSort(data[], Length);

	// outputting the data into output file
    for (int i = 0; i < Length; i++)
    {
        fprintf(output, "%d\t", data[i]);
		fprintf(output, "\n");
    }
    fclose(outputfile);

  return 0;
}
