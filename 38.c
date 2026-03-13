#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if(front == -1)
        return 1;
    return 0;
}

int isFull()
{
    if((front == 0 && rear == MAX-1) || (front == rear+1))
        return 1;
    return 0;
}

void push_front(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

void push_back(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

void pop_front()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from front: %d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void pop_back()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX-1;
    }
    else
    {
        rear--;
    }
}

void showFront()
{
    if(isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void showBack()
{
    if(isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void size()
{
    if(isEmpty())
    {
        printf("Size: 0\n");
        return;
    }

    int count;

    if(rear >= front)
        count = rear - front + 1;
    else
        count = MAX - front + rear + 1;

    printf("Size: %d\n", count);
}

void display()
{
    if(isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;

    printf("Deque elements: ");

    while(1)
    {
        printf("%d ", deque[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    showFront();
    showBack();

    pop_front();
    pop_back();

    display();

    size();

    return 0;
}
