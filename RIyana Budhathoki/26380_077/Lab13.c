#include<stdio.h>
#include<stdlib.h>
int create(int arr[]) // returns size of array
{
    int n,i;
    printf("\nEnter the size of array:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

int linear_search(int a[],int n,int key)

{
	 int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
            return i;
    }
    return -1;
}

int binary_search(int arr[],int low,int high,int key)
{
    int m;
    while(low<high)
    {
        m=(high+low)/2;
        if(arr[m]==key)
            return m;
        else if(arr[m]>key)
            return binary_search(arr,low,m-1,key);
        else
            return binary_search(arr,m+1,high,key);
    }
}

int main()
{
    int n,choice,arr[100];
    int index,key;
    while(1)
	{
		printf("\n1.Linear Search\n2.Binary Search\n3.Exit\n");
		printf("Your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
                n=create(arr);
                printf("\nEnter the item to be searched:");
                scanf("%d",&key);
                index=linear_search(arr,n,key);
                printf("\nAt index: %d \n",index);
				break;
			case 2:
                n=create(arr);
                printf("\nEnter the item to be searched:");
                scanf("%d",&key);
                index=binary_search(arr,0,n-1,key);
                printf("\nAt index: %d \n",index);
				break;
			case 3:
				exit(0);
			default:
				printf("\n");
		}
	}
	return 0;
}