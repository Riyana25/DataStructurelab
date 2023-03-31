// circular Linear List
// 1.Add at the beginning
// 2.Add at the end
// 3.Add at the specified position
// 4.Delete from the beginnig
// 5.Delete from the end
// 6.Delete from the specified position
// 7.Display
// 8.Exit

#include<stdio.h>
#include<stdlib.h>
typedef struct Circular_link
{
    int data;
    struct Circular_link *next;

}node;

void addAtBeg(node **head,node **tail);
void addAtEnd(node **head,node **tail);
void addSpecPos(node **head,node **tail);
void delFromBeg(node **head,node **tail);
void delFromEnd(node **head,node **tail);
void delFromSpec(node **head,node **tail);
void display(node **head,node **tail);


int main()
{
    node *head, *tail;
    tail=NULL;
    head = NULL;
    int choice,num;
    
    while(1)
    {
        printf("1.Add at beginning,");
        printf("2.Add at end,");
        printf("3.Add at specific position,");
        printf("4.Delete From beginning,");
        printf("5.Delete From end,");
        printf("6.Delete From specific position,");
        printf("7.Display\n");
        printf("8.Exit\n");

        printf("Enter your choice either 1 2 3 4 5 6 or 7");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            addAtBeg(&head,&tail);
            break;

            case 2:
            addAtEnd(&head,&tail);
            break;
            case 3:
            addSpecPos(&head,&tail);
            break;
            case 4:
            delFromBeg(&head,&tail);
            break;
            case 5:
            delFromEnd(&head,&tail);
            break;
            case 6:
            delFromSpec(&head,&tail);
            break;
            case 7:
            display(&head,&tail);
            break;
            case 8:
            exit(0);
            default:
            printf("No choice\n");
            break;
        }
    }
    return 0;
}

void addAtBeg(node **head,node **tail)
{
    node *temp;
    int num;
    printf("Enter the num");
    scanf("%d",&num);
    temp=(node*)malloc(sizeof(node));
    temp->data=num;
    temp->next=temp;

    if(*head == NULL)
    {
        *head=temp;
        *tail=temp;
    }else{
        temp->next=*head;
        *head=temp;
        (*tail)->next=*head;
    }
}
void addAtEnd(node **head,node **tail)
{
    node *temp;
    int num;
    printf("Enter the num");
    scanf("%d",&num);
    temp=(node*)malloc(sizeof(node));
    temp->data=num;
    temp->next=temp;

    if(*head == NULL)
    {
        *head=temp;
        *tail=temp;
    }else{
        (*tail)->next=temp;
        temp->next=*head;
        *tail=temp;
    }

}
void addSpecPos(node **head,node **tail)
{
     node *temp;
    int num;
    printf("Enter the num");
    scanf("%d",&num);
    temp=(node*)malloc(sizeof(node));
    temp->data=num;
    temp->next=temp;

    if(*head == NULL)
    {
        *head=temp;
        *tail=temp;
    }else{
        node *temp1;
        int position,count=1;
        printf("Enter the position");
        scanf("%d",&position);
        temp1=*head;

        while(count < position-1)
        {
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
        
    }
}
void delFromBeg(node **head,node **tail)
{
    node *temp;
    if(*head == NULL)
    {
        printf("No list");
    }else{
        temp=*head;
        (*tail)->next=temp->next;
        printf("Deleted item is %d",temp->data);
        *head=temp->next;
        free(temp);
        
    }
}
void delFromEnd(node **head,node **tail)
{
    node *temp;
    if(*head == NULL)
    {
        printf("No list");
    }else{
        node *temp1;
        temp1 = *head;
        while(temp1->next != *tail)
        {
            temp1=temp1->next;
        }
        temp= *tail;
        temp1->next=temp->next;
        printf("Deleted item is %d",temp->data);
        free(temp);
        temp1=*tail;
        
    }

}
void delFromSpec(node **head,node **tail)
{
     node *temp;
    if(*head == NULL)
    {
        printf("No list");
    }else{
        node *temp1;
        int count=1;
        int position;
        printf("\nEnter the position to delete\n");
        scanf("%d",&position);
        temp1= *head;
        while(count < position-1)
        {
            temp1 = temp1->next;
        }
        node *temp;
        temp = temp1->next;
        printf("\nDeleted item is %d",temp->data);
        temp1->next = temp->next;
        free(temp);
        
    }

}
void display(node **head,node **tail)
{
     node *temp;
    if(*head == NULL)
    {
        printf("No list");
    }else{
        temp=*head;
        while(temp != *tail)
        {

            printf(" %d",temp->data);
            temp = temp->next;
        }
         printf(" %d",temp->data);
    }
}

