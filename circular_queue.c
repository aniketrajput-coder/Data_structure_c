    #include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value)
{

    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}

void delete()
{
    int value;

    // Queue is empty
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    value = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("%d deleted from queue.\n", value);
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    printf("Step 1: Inserting elements\n");
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();

    printf("\nStep 2: Deleting two elements\n");
    delete();
    delete();

    display();

    printf("\nStep 3: Inserting 50 and 60\n");
    insert(50);
    insert(60);

    printf("\nStep 4: Final Circular Queue\n");
    display();

    return 0;
}