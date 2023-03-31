#include <stdio.h>
#include <stdlib.h>
#define MAX 4
struct Queue
{
    int front,rear;
    int items[MAX];
};
void enqueue(struct Queue *qptr, int num);
void dequeue(struct Queue *qptr);
void display(struct Queue *qptr);
int main()
{
    struct Queue q;
   q.front =0;
   q.rear = -1;
    int choice;
    int num;
    while (1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter your choice either 1 2 3 or 4");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter your number to enqueue");
            scanf("%d",&num);
            enqueue(&q,num);
            break;
        case 2:
            
            dequeue(&q);
            break;
        case 3:
           
            display(&q);
            break;
        case 4:
            
            exit(-1);
            break;
        default:
            printf("\nNO choice");
            break;
        }
    }
    return 0;
}

void enqueue(struct Queue *qptr,int num)
{
    if(qptr->rear >= (MAX-1))
    {
        printf("The stack is full\n");
    }else{
        qptr->rear ++;
        qptr->items[qptr->rear]=num;
    }

    
}

void dequeue(struct Queue *qptr)
{
    if(qptr->rear < qptr->front)
    {
        printf("The stack is empty\n");
    }else{
        printf("THe enqueued number is %d\n",qptr->items[qptr->front]);
        qptr->front=qptr->front+1;
        
      
    }
    
    
}
// display function definition
void display(struct Queue *qptr)
{
    int i;
    printf("The number are \n");
    for(i=0;i<MAX;i++)
    {
        printf("%d\n",qptr->items[i]);
    }
    
}