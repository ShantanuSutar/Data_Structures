#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void dequeue();
void display();
void peek();
int main()
{
    int ch;
    printf("\n 1. Push  2.Pop  3. Display  4. Peek 5.Exit");

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
            display();
            break;
        case 4:
            peek();
            break;

        case 5:
            exit(0);

        default:
            printf("\n Wrong Choice");
        }
    }
}

void enqueue()
{
    struct node *new;
    new = malloc(sizeof(struct node));
    int data;
    printf("\n Enter data");
    scanf("%d", &data);
    new->data = data;
    new->next = NULL;

    if (rear == NULL && front == NULL)
    {
        front = rear = new;
        rear->next = front;
    }
    else
    {
        rear->next = new;
        rear = new;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("\n Queue is empty");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if (front == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n %d", front->data);
    }
}

void display()
{

    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        while (temp->next != front)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}