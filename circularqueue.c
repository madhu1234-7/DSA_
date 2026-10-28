#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
int count = 0;
void enqueue()
{
    int value;
    if (count == SIZE)
    {
        printf("Queue is FULL\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);
    if (count == 0)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    queue[rear] = value;
    count++;
    printf("%d inserted\n", value);
}

/* Delete element */
void dequeue()
{
    int value;
    if (count == 0)
    {
        printf("Queue is EMPTY\n");
        return;
    }
    value = queue[front];
    if (count == 1)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
    count--;
    printf("%d deleted\n", value);
}

/* Display queue */
void display()
{
    int i, index;
    if (count == 0)
    {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Queue elements: ");
    index = front;
    for (i = 0; i < count; i++)
    {
        printf("%d ", queue[index]);
        index = (index + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
```
