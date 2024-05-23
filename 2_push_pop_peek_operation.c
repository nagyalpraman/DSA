#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int stack[SIZE], top = -1;

int isEmpty()
{
    return (top == -1) ? 1 : 0;
}

int isFull()
{
    return (top == SIZE - 1) ? 1 : 0;
}

void push()
{
    if (isFull())
        printf("stack overflow");

    else
    {
        top++;
        int val;
        printf("enter the value:");
        scanf("%d", &val);
        stack[top] = val;
        printf("value added");
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("stack underflow");
    }

    else
    {
        int val = stack[top];
        top--;
        printf("element %d is removd from the stack", val);
    }
}

void peek()
{
    if (isEmpty())
        printf("the stack is empty");

    else
    {
        printf("the top element of the stack is %d", stack[top]);
    }
}


void show()
{
    if (isEmpty())
        printf("the stack is empty ");

    else
    {
        int i;
        for (i = top; i >= 0; i--)
        {
            printf("the elements are %d\n ", stack[i]);
        }
    }
}

int main()
{
    while (1)
    {
        system("cls");
        printf("1.push\n");
        printf("2.peek\n");
        printf("3.pop\n");
        printf("4.show\n");
        printf("5.exit\n");
        int choice;
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            peek();
            break;
        case 3:
            pop();
            break;
        case 4:
            show();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid choice");
        }
        printf("\n\n");
        system("pause");
    }
    return 0;
}




