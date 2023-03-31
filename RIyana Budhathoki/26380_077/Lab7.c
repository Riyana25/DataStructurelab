/*Doubly linked va_list
1.Add at he beginning
2.Add at the end
3.Add at he specified position
4.Delete from the beginning
5.Delete from the end
6.Delete from specified position
7.Display
8.Exit
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Dlinked_list
{
    int data;
    struct Dlinked_list *next;
     struct Dlinked_list *previous;

}node;

void addAtBeg(node **head);
void addAtEnd(node **head);
void addSpecPos(node **head);
void delFromBeg(node **head);
void delFromEnd(node **head);
void delFromSpec(node **head);
void display(node **head);



int main()
{
    node *head;
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
        printf("7.Exit\n");

        printf("Enter your choice either 1 2 3 4 5 6 or 7");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            addAtBeg(&head);
            break;

            case 2:
            addAtEnd(&head);
            break;
            case 3:
            addSpecPos(&head);
            break;
            case 4:
            delFromBeg(&head);
            break;
            case 5:
            delFromEnd(&head);
            break;
            case 6:
            delFromSpec(&head);
            break;
            case 7:
            display(&head);
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
void addAtBeg(node **head)
{
    node *temp;
    int num;
    printf("Enter the num");
    scanf("%d",&num);
    temp = (node*)malloc(sizeof(node));
    temp->data= num;
    temp->next=NULL;
    temp->previous=NULL;

   

    if(*head == NULL)
    {
        printf("\nEmpty linked list\n");
        *head=temp;
    }else{
        temp->next= *head;
        (*head)->previous=temp;
        *head= temp;
        printf("\nAdded successfully at the Beg\n");
    }
}

void addAtEnd(node **head)
{
    node *temp;
    int num;
    printf("Enter the num");
    scanf("%d",&num);
    temp = (node*)malloc(sizeof(node));
    temp->data= num;
    temp->next=NULL;


    if(head == NULL)
    {
        printf("\nEmpty linked list");
        *head=temp;
        // exit(0);
    }else{
        node *temp1;
        temp1 = *head;
        while(temp1->next != NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->previous=temp1;
        printf("\nAdded successfully at the end\n");
    }
}

void addSpecPos(node **head)
{
    node *temp;
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
     temp = (node*)malloc(sizeof(node));
     temp->data=num;
     temp->next=NULL;
  
     if(*head == NULL)
    {
        printf("\nEmpty linked list");
        *head=temp;
        // exit(0);
    }else{


    int position;
    int count;
    printf("Enter the position to add");
    scanf("%d",&position);
    node *temp1;
    temp1 = *head;
    count=1;
    while(count < position-1)
    {
        temp1= temp1->next;
    }
    temp->next=temp1->next;
    temp->previous=temp1;
    temp1->next=temp;
    temp->next->previous=temp;
    printf("\nAdded successfully at the given position\n");
    }
}

void delFromBeg(node **head)
{
    node *temp;
    if(*head == NULL)
    {
        printf("\nEmpty list");
        return;
    }else{
        temp= *head;
        printf("Deleted item is %d",temp->data);
        *head = temp->next;
        (*head)->previous = NULL;
        free(temp);
        printf("\nDeleted successfully at the beg\n");
    }
}
void delFromEnd(node **head)
{
    node *temp1;
    if(*head == NULL)
    {
        printf("\nEmpty linked list\n");
        return;
    }else{
        temp1 = *head;
        while(temp1->next->next != NULL)
        {
            temp1 = temp1->next;
        
        }
        node *temp;
        temp= temp1->next;
        printf("Deleted item is %d",temp->data);
          temp1->next = NULL;
        
        free(temp);
      
        printf("\nDeleted successfully at the End\n");
    }
}

void delFromSpec(node **head)
{
    node *temp1;
    if(*head == NULL)
    {
        printf("\nEmpty linked list\n");
        return;
    }else{
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
        temp->next->previous=temp1;
        free(temp);
    }

}
void display(node **head)
{
    node *temp;
    // temp= *head;
    if(*head == NULL)
    {
        printf("\nEmpty linked list\n");
        return;
    }else{
        temp = *head;
        printf("\nThe data are\n");
        while(temp->next != NULL)
        {
            printf(" %d",temp->data);
            temp = temp->next;
        
        }
        printf(" %d",temp->data);
    }
}
