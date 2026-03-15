#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

/* enqueue */
void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

/* dequeue */
int dequeue()
{
    int x = queue[front];
    front++;
    return x;
}

/* push */
void push(int x)
{
    top++;
    stack[top] = x;
}

/* pop */
int pop()
{
    int x = stack[top];
    top--;
    return x;
}

int main()
{
    int n, i, x;

    scanf("%d", &n);

    /* read queue elements */
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    /* move queue to stack */
    for(i = 0; i < n; i++)
        push(dequeue());

    /* move stack back to queue */
    front = 0;
    rear = -1;

    for(i = 0; i < n; i++)
        enqueue(pop());

    /* print reversed queue */
    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}
