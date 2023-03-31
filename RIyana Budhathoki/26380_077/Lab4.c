#include <stdio.h>
#include<stdlib.h>
#include <limits.h>

struct Item
{
    int value;
    int priority;
};
void enqueue(int value, int priority);
int peek();
void dequeue();
void display();
struct Item pr[10000];
int size = -1;

int main()
{
    int choice;
    int value, priority;
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
            printf("Enter the value and priority");
            scanf("%d %d", &value, &priority);

            enqueue(value, priority);
            break;
        case 2:
            

            dequeue();
            break;
        case 3:

            display();
            break;
        case 4:

            exit(0);
            break;
        default:
            printf("\nNO choice");
            break;
        }

        
    }
        return 0;
    }
    void enqueue(int value, int priority)
    {
        size++;
        pr[size].value = value;
        pr[size].priority = priority;
    }
    void dequeue()
    {
        
        int ind = peek();
        printf("%d\n",ind);
        printf("%d\n",pr[ind].value);
        for (int i = ind; i < size; i++)
        {
            pr[i] = pr[i + 1];
            size--;
        }
    }
    int peek()
    {
        int highestPriority = INT_MIN;
        int ind = -1;

        for (int i = 0; i <= size; i++)
        {
            if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
            {
                highestPriority = pr[i].priority;
                ind = i;
            }
            else if (highestPriority < pr[i].priority)
            {
                highestPriority = pr[i].priority;
                ind = i;
            }
        }
        return ind;
    }

void display()
{
    printf("\nEnqueued values are:\n");
    for(int i=0;i<=size;i++)
    {
        printf("\n%d",pr[i].value);
    }
}