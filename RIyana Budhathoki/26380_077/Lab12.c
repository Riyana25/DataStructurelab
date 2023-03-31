#include <stdio.h>
#include <stdlib.h>
int temp[100];
int create(int arr[]) // returns size of array
{
    int n;
    printf("\nEnter the size of array:");
    scanf("%d", &n);
    int i;

    for ( i = 0; i < n; i++)
    {
        printf("Enter arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

void display(int arr[], int n)
{
	int i;
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]= %d\n", i, arr[i]);
    }
    printf("--------------------\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// merge
void merge(int a[], int temp[], int l, int m, int h)
{
    int i, j, k;
    i = l, j = m + 1, k = l;
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];
    while (j <= h)
        temp[k++] = a[j++];
    for (i = l; i <= h; i++)
        a[i] = temp[i];
}
void mergesort(int a[], int l, int h)
{
    int m;
    if (l < h)
    {
        m = (l + h) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, h);
        merge(a, temp, l, m, h); // int temp[ ] â†’ Global Array
    }
}

// quick
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

// heap
void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void build_heap(int arr[], int n)
{
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
void heap_sort(int arr[], int n)
{
		int i;
    build_heap(arr, n);
    for (i  = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

int main()
{
    int u_choice, n;
    int arr[10000];

    while (1)
    {
        printf("\n1.Merge Sort\n2.Quick Sort\n3.Heap Sort\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &u_choice);

        switch (u_choice)
        {
        case 1:
            n = create(arr);
            mergesort(arr, 0, n-1);
            display(arr,n);
            break;
        case 2:
            n = create(arr);
            quickSort(arr, 0, n-1);
            display(arr,n);
            break;
        case 3:
            n = create(arr);
            heap_sort(arr, n);
            display(arr,n);
            break;
        case 4:
            exit(0);
        default:
            printf("\n");
        }
    }
    return 0;
}