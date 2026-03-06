#include <stdio.h>

void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[], int b[]);

int main()
{
    int n;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("\nEnter elements of first array:\n");
    read_array(n, a);

    printf("\nEnter elements of second array:\n");
    read_array(n, b);

    swap_array(n, a, b);

    printf("\nAfter swapping:\n");

    printf("Array A: ");
    print_array(n, a);

    printf("\nArray B: ");
    print_array(n, b);

    return 0;
}

void read_array(int n, int arr[])
{
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void print_array(int n, int arr[])
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void swap_array(int n, int a[], int b[])
{
    int temp;

    for(int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}