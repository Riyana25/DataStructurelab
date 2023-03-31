#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter the size of array");
    scanf("%d",&n);

    int array[n];
    printf("Enter the elements of array");
    for(int i=0;i<n;i++)
    {
        printf("array[%d]=",i);
        scanf("%d",&array[i]);
    }

    int i=0,j=0;
    while(j<(n-i-1))
    {
        if(array[j]>array[j+1])
        {
            int temp;
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
        }
        j+=j;
    }
    i++;

    return 0;
}