#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("Inserted into queue :");
    printf("%d\n", value);
}

void deleteElement()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted from queue :");
    printf("%d\n",queue[front]);
    front++;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Remaining elements: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    deleteElement();
    deleteElement();
    insert(40);
    display();

    return 0;
}
