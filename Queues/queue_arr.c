#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 5

int q[max], front = -1, rear = -1;
void enqueue();
void dequeue();
void disp();

int main()
{
    int ch;
    printf("\n 1. Push  2.Pop  3. Display  4.Exit");

    while (1)
    {
        printf("\n Enter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;

        case 3:
            disp();
            break;

        case 4:
            exit(0);

        default:
            printf("\n Wrong Choice");
        }
    }
}

void enqueue()
{
    int data;
    if (rear == max - 1)
    {
        printf("\n Overflow");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("\n Enter element");
        scanf("%d", &data);
        rear++;
        q[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\n Underflow");
    }
    else
    {
        printf("\n Dequeued element is %d", q[front]);
        front++;
    }
}

void disp()
{
    int i = 0;
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("\n Elements: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d", q[i]);
        }
    }
}