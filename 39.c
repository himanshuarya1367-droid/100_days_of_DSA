#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

/* swap function */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* heapify up */
void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

/* heapify down */
void heapifyDown(int index)
{
    int left, right, smallest;

    while(1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

/* insert operation */
void insert(int value)
{
    heap[size] = value;
    heapifyUp(size);
    size++;
}

/* peek operation */
int peek()
{
    if(size == 0)
        return -1;

    return heap[0];
}

/* extractMin operation */
int extractMin()
{
    int min;

    if(size == 0)
        return -1;

    min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int main()
{
    int n, i, value;
    char op[20];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if(strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
        else if(strcmp(op, "extractMin") == 0)
        {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}
