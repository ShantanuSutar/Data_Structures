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
    printf("\n Circular QA 1. Push  2.Pop  3. Display  4.Exit");

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
    printf("\n Enter data");
    scanf("%d", &data);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = data;
    }
    else if ((rear + 1) % max == front)
    {
        printf("\n Queue is Full");
    }
    else
    {
        rear = (rear + 1) % max;
        q[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is Empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

void disp()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is Empty");
    }
    else
    {
        printf("\n Queue is ");
        while (i != rear)
        {
            printf(" %d ", q[i]);
            i = (i + 1) % max;
        }
        printf(" %d ", q[i]);
    }
}