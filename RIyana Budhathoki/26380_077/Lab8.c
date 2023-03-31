// STACK AS A LINEAR 
// 1.PUSH
// 2.POP
// 3.DISPLAY
// 4.EXIT

#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
    int data;
    struct Stack *next;
    

}node;

void push(node **top);
void pop(node **top);
void display(node **top);



int main()
{
    node *top;
    top = NULL;
    int choice;
    
    while(1)
    {
        printf("1.push,");
        printf("2.pop,");
        printf("3.Display,");
        printf("4.Exit\n");

        printf("Enter your choice either 1 2 3 or 4");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            push(&top);
            break;

            case 2:
            pop(&top);
            break;

            case 3:
            display(&top);
            break;

            case 4:
            exit(0);
            default:
            printf("No choice\n");
            break;
        }
    }
    return 0;
}
void push(node **top)
{
    node *temp;
    int num;
    printf("Enter the number");
    scanf("%d",&num);
    temp= (node*)malloc(sizeof(node));
    temp->data=num;
    temp->next=NULL;
    if(*top == NULL)
    {
        *top=temp;
    }else{
        temp->next= *top;
        *top=temp;
        printf("\npushed");
    }

}
void pop(node **top)
{
    node *temp;
    if(*top == NULL)
    {
        printf("\nNO pop");
    }else{
        temp = *top;
        *top =temp->next;
        printf("\nDeleted data is %d\n",temp->data);
        free(temp);
    }
}
void display(node **top)
{
    node *temp;
    temp = *top;
    printf("The data are:");
    if(*top == NULL)
    {
        printf("No stack");
    }else{
        while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp= temp->next;
    }

        
    }
    

}
