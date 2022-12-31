#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 5

int q[max], front = -1, rear = -1;
void enqueuef();
void enqueuer();
void dequeuef();
void dequeuer();
void disp();

int main()
{
    int ch;
    printf("\n DE QA 1. PushF  2.PushR  3.PopF  4.PopR 5.Dislay  6.Exit");

    while (1)
    {
        printf("\n Enter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueuef();
            break;

        case 2:
            enqueuer();
            break;

        case 3:
            dequeuef();
            break;

        case 4:
            dequeuer();
            break;

        case 5:
            disp();
            break;

        case 6:
            exit(0);
        default:
            printf("\n Wrong Choice");
        }
    }
}

void enqueuef()
{
    int data;
    printf("\n Enter data");
    scanf("%d", &data);
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
        printf("\n Queue is Full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[front] = data;
    }
    else
    {
        front--;
        q[front] = data;
    }
}

void enqueuer()
{
    int data;
    printf("\n Enter data");
    scanf("%d", &data);
    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
        printf("\n Queue is Full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        q[rear] = data;
    }
    else if (rear == max - 1)
    {
        rear = 0;
        q[rear] = data;
    }
    else
    {
        rear++;
        q[rear] = data;
    }
}

void disp()
{
    int i = front;
    while (i != rear)
    {
        printf("%d  ", q[i]);
        i = (i + 1) % max;
    }
    printf("%d", q[rear]);
}

void dequeuef()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is Empty");
    }
    else if (front == rear)
    {
        front = rear - 1;
    }
    else if (front == max - 1)
    {
        printf("%d  ", q[front]);
        front = 0;
    }
    else
    {
        printf("%d  ", q[front]);
        front++;
    }
}

void dequeuer()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is Empty");
    }
    else if (front == rear)
    {
        front = rear - 1;
    }
    else if (rear == 0)
    {
        printf("%d  ", q[rear]);
        rear = max - 1;
    }
    else
    {
        printf("%d  ", q[rear]);
        rear--;
    }
}