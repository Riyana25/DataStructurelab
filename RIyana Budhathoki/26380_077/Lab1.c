#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Stack
{
    int top;
    int items[MAX];
};
void push(struct Stack *sptr, int num);
void pop(struct Stack *sptr);
void display(struct Stack *sptr);
int main()
{
    struct Stack s;
    s.top = -1;
    int choice;
    int num;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter your choice either 1 2 3 or 4");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter your number to push");
            scanf("%d",&num);
            push(&s,num);
            break;
        case 2:
            
            pop(&s);
            break;
        case 3:
           
            display(&s);
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
// push function definition
void push(struct Stack *sptr,int num)
{
    if(sptr->top >= (MAX-1))
    {
        printf("The stack is full\n");
    }else{
        sptr->top = sptr->top+1;
        sptr->items[sptr->top]=num;
    }
}
// pop function definition
void pop(struct Stack *sptr)
{
    if(sptr->top <= -1)
    {
        printf("The stack is empty\n");
    }else{
        printf("THe popped number is %d\n",sptr->items[sptr->top]);
       sptr->top = sptr->top -1;
    }
}
// display function definition
void display(struct Stack *sptr)
{
    int i;
    printf("The number are \n");
    for(i=0;i<MAX;i++)
    {
        printf("%d\n",sptr->items[i]);
    }
}