#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure */
struct Node
{
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* enqueue operation */
void enqueue(int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if(rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

/* dequeue operation */
int dequeue()
{
    int value;
    struct Node* temp;

    if(front == NULL)
        return -1;

    temp = front;
    value = temp->data;
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return value;
}

int main()
{
    int n, i, value;
    char op[20];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &value);
            enqueue(value);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
