#include <stdio.h>

void inputTemperatures(int n, float temps[n]);
float findHighest(int n, float temps[n]);
float findLowest(int n, float temps[n]);
void output(float max, float min);

int main()
{
    int n = 7;
    float temps[7];
    float max, min;

    inputTemperatures(n, temps);

    max = findHighest(n, temps);
    min = findLowest(n, temps);

    output(max, min);

    return 0;
}

void inputTemperatures(int n, float temps[n])
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter temperature for day %d: ", i+1);
        scanf("%f", &temps[i]);
    }
}

float findHighest(int n, float temps[n])
{
    float max = temps[0];

    for(int i = 1; i < n; i++)
    {
        if(temps[i] > max)
        {
            max = temps[i];
        }
    }

    return max;
}

float findLowest(int n, float temps[n])
{
    float min = temps[0];

    for(int i = 1; i < n; i++)
    {
        if(temps[i] < min)
        {
            min = temps[i];
        }
    }

    return min;
}

void output(float max, float min)
{
    printf("\nHighest Temperature: %.2f\n", max);
    printf("Lowest Temperature: %.2f\n", min);
}