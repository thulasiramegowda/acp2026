#include <stdio.h>
#include <stdlib.h>

int* create_array(int n);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = create_array(n);

    initialize_array(arr, n);

    printf("\nArray elements:\n");
    print_array(arr, n);

    delete_array(&arr);

    return 0;
}

int* create_array(int n)
{
    int *arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    return arr;
}

void initialize_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void print_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void delete_array(int **arr)
{
    free(*arr);
    *arr = NULL;
    printf("\nMemory freed successfully\n");
}