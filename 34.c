#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    struct Node *temp;
    int value;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int evaluatePostfix(char exp[])
{
    int i = 0;
    int op1, op2, result;

    while(exp[i] != '\0')
    {
        if(exp[i] == ' ')
        {
            i++;
            continue;
        }

        if(isdigit(exp[i]))
        {
            int num = 0;

            while(isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
            i++;
        }
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    gets(exp);   // works in old Dev-C

    printf("Result = %d", evaluatePostfix(exp));

    return 0;
}
