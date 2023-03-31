// Queue AS A LINEAR 
// 1.Enqueue
// 2.Dequeue
// 3.DISPLAY
// 4.EXIT

#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
    int data;
    struct Queue *next;
    

}node;

void enqueue(node **front,node **rear);
void dequeue(node **front,node **rear);
void display(node **front,node **rear);



int main()
{
    node *front;
    node *rear;
    front=NULL;
    rear=NULL;
    int choice;
    
    while(1)
    {
        printf("1.Enqueue,");
        printf("2.Dequeue,");
        printf("3.Display,");
        printf("4.Exit\n");

        printf("Enter your choice either 1 2 3 or 4");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            enqueue(&front,&rear);
            break;

            case 2:
            dequeue(&front,&rear);
            break;

            case 3:
            display(&front,&rear);
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
void enqueue(node **front,node **rear)
{
    node *temp;
    int num;
    printf("Enter the number");
    scanf("%d",&num);
    temp= (node*)malloc(sizeof(node));
    temp->data=num;
    temp->next=NULL;
    if(*front == NULL)
    {
        *front=temp;
        *rear=temp;
    }else{

       (*rear)->next =temp;
        *rear=temp;
        // printf("\nEnqueued\n");
    }

}
void dequeue(node **front,node **rear)
{
    node *temp;
    if(*front == NULL)
    {
        printf("\nNO queue");
    }else{
        temp = *front;
        *front =temp->next;
        printf("\nDeleted data is %d\n",temp->data);
        free(temp);
    }
}
void display(node **front,node **rear)
{
    node *temp;
    temp = *front;
    printf("The data are:");
    if(*front == NULL)
    {
        printf("No queue");
    }else{
        while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }

        
    }
    

}
