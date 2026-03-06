#include <stdio.h>

void inputMarks(int n, float marks[]);
float findHighestMark(int n, float marks[]);
float findLowestMark(int n, float marks[]);
void output(float max, float min);

int main()
{
    int n;

    printf("Enter number of students: ");
    scanf("%d",&n);

    float marks[n];

    inputMarks(n, marks);

    float max = findHighestMark(n, marks);
    float min = findLowestMark(n, marks);

    output(max, min);

    return 0;
}

void inputMarks(int n, float marks[])
{
    for(int i=0;i<n;i++)
    {
        printf("Enter mark %d: ",i+1);
        scanf("%f",&marks[i]);
    }
}

float findHighestMark(int n, float marks[])
{
    float max = marks[0];

    for(int i=1;i<n;i++)
    {
        if(marks[i] > max)
            max = marks[i];
    }

    return max;
}

float findLowestMark(int n, float marks[])
{
    float min = marks[0];

    for(int i=1;i<n;i++)
    {
        if(marks[i] < min)
            min = marks[i];
    }

    return min;
}

void output(float max, float min)
{
    printf("\nHighest Mark = %.2f", max);
    printf("\nLowest Mark = %.2f", min);
}