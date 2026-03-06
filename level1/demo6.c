#include <stdio.h>
#include <stdlib.h>

int* allocate_scores(int n);
void read_scores(int *arr, int n);
int calculate_total(int *arr, int n);
void display_scores(int *arr, int n);
void delete_scores(int **arr);

int main()
{
    int n, total;
    int *scores;

    printf("Enter number of players: ");
    scanf("%d", &n);

    scores = allocate_scores(n);

    read_scores(scores, n);

    printf("\nScores of players:\n");
    display_scores(scores, n);

    total = calculate_total(scores, n);

    printf("\nTotal Team Score = %d\n", total);

    delete_scores(&scores);

    return 0;
}

int* allocate_scores(int n)
{
    int *arr;

    arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    return arr;
}

void read_scores(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter score of player %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

int calculate_total(int *arr, int n)
{
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    return total;
}

void display_scores(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Player %d Score = %d\n", i+1, arr[i]);
    }
}

void delete_scores(int **arr)
{
    free(*arr);
    *arr = NULL;

    printf("\nMemory deallocated successfully\n");
}