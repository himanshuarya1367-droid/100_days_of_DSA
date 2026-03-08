#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void moveFrontToRear()
{
    if(front == NULL)
        return;

    struct node *temp = front;

    if(front == rear)
        return;

    front = front->next;
    rear->next = temp;
    rear = temp;
    rear->next = NULL;
}

void display()
{
    struct node *temp = front;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        moveFrontToRear();
    }

    display();

    return 0;
}
