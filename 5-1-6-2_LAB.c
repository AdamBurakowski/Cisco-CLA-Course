#include <stdio.h>
#include <stdlib.h>

// This constant just adds some clarity
#define MAX_SIZE 20

int main()
{
    int size;
    
    printf("Type a number of your multiplication table: ");
    scanf("%d", &size);
	
	if (size > MAX_SIZE)
	{
	    printf("Matrix too big.");
	    return 1;
	}
	
	int **table = (int **)malloc(size * sizeof(int*));
	
	if (table == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
	
	for (int r = 0; r < size; r++)
	{
	    table[r] = (int *)malloc(size * sizeof(int));
	    if (table[r] == NULL)
	    {
	        printf("Memory allocation failed.\n");
	        // Free previously allocated memory
	        for (int i = 0; i < r; i++)
	        {
	            free(table[i]);
	        }
	        free(table);
	        return 1;
	    }
	}
	
	for (int r = 0; r < size; r++)
	{
	    for(int c = 0; c < size; c++)
	    {
	        table[r][c] = (r+1)*(c+1);
	    }
	}

	printf("    ");
	for (int i = 1; i <= size; i++)
	{
	    if (i < 10)
	    {
	    printf("   %d", i);
	    }
	    else
	    {
	        printf("  %d", i);
	    }
	}
	printf("\n");
	for (int c = 1; c <= size; c++)
	{
	    if (c < 10)
	    {
	    printf("   %d", c);
	    }
	    else
	    {
	        printf("  %d", c);
	    }
	    for (int r = 0; r < size; r++)
	    {
	        int number = table[r][c-1];
	        if (number > 99)
	        {
	            printf(" %d", number);
	        }
	        else if (number > 9)
	        {
	            printf("  %d", number);
	        }
	        else
	        {
	            printf("   %d", number);
	        }
	    }
	    printf("\n");
	}
	
	// Free dynamically allocated memory
	for (int r = 0; r < size; r++)
	{
	    free(table[r]);
	}
	free(table);
	
	return 0;
}
