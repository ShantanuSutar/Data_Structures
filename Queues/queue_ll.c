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
            display();
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
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\n Enter data ");
    scanf("%d", &temp->data);

    if (front == NULL)
    {
        temp->next = NULL;
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = NULL;
    }
}

void dequeue()
{

    if (front == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        printf("\n Deleted element is %d ", temp->data);
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("\n Queue is Empty");
    }
    else
    {
        printf("\n Elements are: ");
        for (temp = front; temp != NULL; temp = temp->next)
        {
            printf("\n %d ", temp->data);
        }
    }
}