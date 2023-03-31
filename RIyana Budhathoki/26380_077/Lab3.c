#include <stdio.h>
#include <stdlib.h>
#define MAX 3
struct Cqueue
{
    int front,rear;
    int items[MAX];
};
void enqueue(struct Cqueue *qptr, int num);
void dequeue(struct Cqueue *qptr);
void display(struct Cqueue *qptr);
int main()
{
    struct Cqueue q;
   q.front =MAX-1;
   q.rear = MAX-1;
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

void enqueue(struct Cqueue *qptr,int num)
{
    
   
    printf("\nEnter the number to enqueue");
    scanf("%d",&num);

    if((qptr->rear+1)%MAX == qptr->front)
    {
        printf("Queue is full\n");

    }else{
        qptr->rear = (qptr->rear +1)%MAX;
        qptr->items[qptr->rear]=num;
    }
    
}

void dequeue(struct Cqueue *qptr)
{
    if(qptr->rear == qptr->front)
    {
        printf("Queue is empty\n");
    }else{
        qptr->front = (qptr->front +1)%MAX;
        printf("%d",qptr->items[qptr->front]);

    }
}
// display function definition
void display(struct Cqueue *qptr)
{
    
    int i;
    if(qptr->rear == qptr->front)
    {
        printf("Queue is empty\n");

    }else{
        printf("Items of queue are\n");
        for(i=(qptr->front+1)%MAX;i!=qptr->rear;i=(i+1)%MAX)
        {
            printf("%d\t",qptr->items[i]);

        }
        printf("%d\t",qptr->items[qptr->rear]);
    }
    
    
}