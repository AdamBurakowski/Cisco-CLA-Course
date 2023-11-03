#include <stdio.h>

int main()
{
	struct person
	{
	    char first_name[8];
	    char last_name[8];
	};
	struct person mary = {"Mary", "Smith"};
	struct person james = {"James", "Johnson"};
	struct person patricia = {"Patricia", "Williams"};
	struct person john = {"John", "Brown"};
	
	struct person people[] = {mary, james, patricia, john};
	
	for (int i = 0; i < 4; i++)
	{
	    for (int j = 0; j < sizeof(people[j].first_name); j++)
	    {
	        printf("%c", people[i].first_name[j]);
	    }
	    printf(" ");
	    for (int j = 0; j < sizeof(people[j].last_name); j++)
	    {
	        printf("%c", people[i].last_name[j]);
	    }
	    printf("\n");
	}
}
