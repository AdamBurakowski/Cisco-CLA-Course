#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY (1024 * 1024)

int main()
{
	int *memory, num_of_characters;
	char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	printf("How much memory do you need? ");
	scanf("%d", &num_of_characters);
	
	memory = (int *)malloc(num_of_characters * sizeof(char));
	
	if (num_of_characters > MAX_MEMORY)
	{
	    printf("To much memory requested");
	    return 1;
	}
	
	if (memory == NULL)
	{
	    printf("Memory allocation failed");
	    return 1;
	}
	else
	{
	    *memory = num_of_characters;
	}
	
	for (int i = 1; i <= num_of_characters; i++)
	{
	    printf("%c", characters[(i-1)%26]);
	    if (i % 40 == 0)
	    {
	        printf("\n");
	    }
	}
	
	free(memory);
	
	return 0;
}
