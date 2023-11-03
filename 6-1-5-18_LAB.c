#include <stdio.h>
#include <stdlib.h>

struct element
{
    int value;
    struct element *next;
};

void loop(struct element *head, int num, int max_value)
{
    printf("First %d values: \n", num);
    struct element *current_element = head;
    if (num > max_value)
    {
        num = max_value;
        printf("Number you specified was greater than the number of elements in the list\n");
        printf("The number has been changed to %d\n\n", num);
    }
    for (int i = 0; i < num && current_element != NULL; i++)
    {
        printf("%d\n", current_element -> value);
        current_element = current_element -> next;
    }
}

int main(void)
{
    int values[10] = {2, 4, 5, 6, 7, 8, 9, 1, 3, 0};
    
    int max_value = sizeof(values)/sizeof(int);

    struct element *head = NULL;
    struct element *current_element = NULL;

    for (int i = 0; i < 10; i++)
    {
        struct element *new_element = (struct element *)malloc(sizeof(struct element));
        if (new_element == NULL)
        {
            return 1;
        }

        new_element->value = values[i];
        new_element->next = NULL;

        if (head == NULL)
        {
            head = new_element;
            current_element = new_element;
        }
        else
        {
            current_element -> next = new_element;
            current_element = new_element;
        }
    }

    loop(head, 5, max_value);
    loop(head, 7, max_value);

    struct element *current_node = head;
    while (current_node != NULL)
    {
        struct element *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }
    printf("Memory is freed");

    return 0;
}
