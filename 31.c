#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

/* Function to push element */
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

/* Function to pop element */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d\n", stack[top]);
        top--;
    }
}

/* Function to display stack */
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, choice, value, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &choice);

        if (choice == 1)
        {
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
    }

    return 0;
}
