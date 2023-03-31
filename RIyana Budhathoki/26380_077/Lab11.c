#include<stdio.h>
#include<stdlib.h>
int create(int arr[]) //returns size of array
{
    int n;
    printf("\nEnter the size of array:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    return n;
}

void display(int arr[],int n)
{
    printf("\nSorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("arr[%d]= %d\n",i,arr[i]);
    }
    printf("--------------------\n");
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble(int a[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
    display(a,n);
}

void selection(int a[],int n)
{
    int min_index,i,j;
    for(i=0;i<n-1;i++)
    {
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
                min_index=j;
        }
        if(min_index!=i)
            swap(&a[i],&a[min_index]);
    }
    display(a,n);
}

void insertion(int a[],int n)
{
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 & a[j]>temp;j--)
            a[j+1]=a[j];

        a[j+1]=temp;
    }
    display(a,n);
}

void shell(int a[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=a[i];
            for(j=i;j>=gap & a[j-gap]>temp;j-=gap)
                 a[j]=a[j-gap];

            a[j]=temp;
        }
    }
    display(a,n);
}

int main()
{
    int u_choice,n;
    int arr[10000];

    while(1)
    {
        printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Shell Sort\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&u_choice);

        switch(u_choice)
        {
            case 1:
                n=create(arr);
                bubble(arr,n);
                break;
            case 2:
                n=create(arr);
                selection(arr,n);
                break;
            case 3:
                n=create(arr);
                insertion(arr,n);
                break;
            case 4:
                n=create(arr);
                shell(arr,n);
                break;
            case 5:
                exit(0);
            default:
                printf("\n");
        }
    }
    return 0;
}
