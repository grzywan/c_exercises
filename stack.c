#include <stdio.h>
#include <stdlib.h>

typedef struct  stack
{
    int value;
    struct stack* next;
} stack;

int choice, number;

stack new_stack(int value)
{
    stack el = {value, NULL};
    return el;
}

void push(stack **ptr, int value)
{
    stack* new_element = (stack*)malloc(sizeof(stack));

    new_element->value = value;
    new_element->next = *ptr;

    *ptr = new_element;
}

int pop(stack **ptr)
{
    int value;
    stack* old_ptr = *ptr;

    if (*ptr == NULL)
    {
        printf("\nStack is EMPTY!\n");
        return 0;
    }
    else
    {
        *ptr = (*ptr)->next;
        value = old_ptr->value;

        free(old_ptr);
        return value;
    }
}

int main()
{
    stack* stack = NULL;
    int end_stack = 1;


    while (end_stack) {
        do {
            printf("Select operation:\n0 - End program\n1 - Push value on stack\n2 - Pop value from stack\n");
            scanf_s("%d", &choice);

            if (choice > 2 || choice < 0) 
            {
                printf("\nWrong operation. Try again.\n\n");
                continue;
            } else 
            {
                switch (choice) 
                {
                case 0:
                    end_stack = 0;
                    printf("\nProgram is end.\n");
                    getchar();
                    break;
                case 1:

                    printf("\nNumber to push on stack: \n");
                    scanf_s("%d", &number);
                    push(&stack, number);
                    break;
                case 2:
                    printf("\nNumber pop from stack: %d\n", pop(&stack));
                }

            }
        } while (choice);

    }

    return 0;
}