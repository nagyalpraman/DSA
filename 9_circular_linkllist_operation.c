#include <stdio.h>
#include <stdlib.h>

// node creation
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;

struct node *createnode()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    return temp;
}

void createlist()
{
    int n;
    int i;
    printf("enter the number of elements:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        struct node *newnode = createnode();

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            tail->next = newnode;
        }
        tail = newnode;
    }
    if (tail != NULL)
        tail->next = head;
}

// for display the linklist
void Display()
{
    if (head == NULL)
    {
        printf("the list is empty!!!");
    }
    else
    {
        struct node *temp = head;
        do
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

// for inserting the node in beganing of linklist
void InsertNodeAtBeg()
{
    struct node *newnode = createnode();
    newnode->next = head;
    head = newnode;
    tail->next = head;
}

// for inserting the node at the end of linklist
void InsertNodeAtEnd()
{
    struct node *newnode = createnode();
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = head;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

// for inserting the node at any location
void InsretNodeAtAnyLocation()
{
    if (head == NULL)
        printf("the list is empty!!!");

    else
    {
        int position;
        printf("enter the position :");
        scanf("%d", &position);

        if (position == 1)
        {
            InsertNodeAtBeg();
        }

        else
        {
            int i = 1;
            struct node *temp = head;
            do
            {
                if (i == position - 1)
                {
                    struct node *newnode = createnode();
                    newnode->next = temp->next;
                    temp->next = newnode;
                    break;
                }
                temp = temp->next;
                i++;
            } while (temp != head);
            if (temp == head)
            {
                printf("invalid position");
            }
        }
    }
}

// for deletion of a node
void DeletionFromLinklist()
{
    if (head == NULL)
        printf("the list is empty");

    else
    {
        int pos;
        printf("enter the position:");
        scanf("%d", &pos);
        if (pos == 1 && head != tail)
        {
            head = head->next;
            tail->next = head;
        }
        else if(pos==1&&head==tail)
        {
            head=tail=NULL;
        }
        else{
                struct node*temp=head;
                int i=1;
            do
            {
                if(i==pos-1)
                {
                    temp->next=temp->next->next;
                    tail=temp;
                    break;
                }
                temp=temp->next;
                i++;

               
            } while (temp!=head);
            if(temp==head)
            printf("invalid position");
            
        }
    }
}

// searching any element int he linklist
void SearchFromLinklist()
{
    if (head == NULL)
    {
        printf("the list is empty");
    }
    else
    {
        int value;
        printf("enter the value :");
        scanf("%d", &value);
        struct node *temp = head;
        do
        {
            if (temp->data == value)
            {
                break;
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != head);
        if (temp == head)
        {
            printf("element  not found");
        }
        else
        {
            printf("element found");
        }
    }
}

int main()
{
    int choice;
    createlist();
    while (1)
    {
        system("cls");
        printf("\n******* Implementation of circular singly linked list. *******\n\n");
        printf("1. Insert Element In Begining Of Linked List\n");
        printf("2. Insert Element In End Of Linked List\n");
        printf("3. Insert Element In Any Location Of Linked List\n");
        printf("4. Delete Element From Linked List\n");
        printf("5. Search Element In Linked List\n");
        printf("6. Display All Elements Of Linked List\n");
        printf("7. Exit\n\n");

        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertNodeAtBeg();
            break;

        case 2:
            InsertNodeAtEnd();
            break;

        case 3:
            InsretNodeAtAnyLocation();
            break;

        case 4:
            DeletionFromLinklist();
            break;

        case 5:
            SearchFromLinklist();
            break;

        case 6:
            Display();
            break;

        case 7:
            exit(0);
            break;

        default:
        {
            printf("invalid choice!!!!");
        }
        }
        printf("\n");
        system("pause");
    }
    return 0;
}