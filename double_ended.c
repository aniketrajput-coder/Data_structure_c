#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int value)
{
    if (front == 0)
    {
        printf("Deque Overflow at Front\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

void insertRear(int value)
{
    if (rear == MAX - 1)
    {
        printf("Deque Overflow at Rear\n");
        return;
    }

    if (rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted from Front: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (rear == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted from Rear: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Remaining elements: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", deque[i]);
    }

    printf("\n");
}

int main()
{

    insertFront(10);

    insertRear(20);

    insertFront(30);

    deleteFront();

    deleteRear();

    display();

    return 0;
}
