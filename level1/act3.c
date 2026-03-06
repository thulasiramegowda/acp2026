#include <stdio.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

void input(int n, Rectangle rects[]);
void calculate_area(int n, Rectangle rects[]);
int findLargestArea(int n, Rectangle rects[]);
void output(int largestIndex, Rectangle rects[]);

int main()
{
    int n;
    printf("Enter number of rectangles: ");
    scanf("%d", &n);

    Rectangle rects[n];

    input(n, rects);
    calculate_area(n, rects);

    int largestIndex = findLargestArea(n, rects);

    output(largestIndex, rects);

    return 0;
}

void input(int n, Rectangle rects[])
{
    for(int i = 0; i < n; i++)
    {
        printf("\nRectangle %d\n", i+1);

        printf("Enter length: ");
        scanf("%f", &rects[i].length);

        printf("Enter width: ");
        scanf("%f", &rects[i].width);
    }
}

void calculate_area(int n, Rectangle rects[])
{
    for(int i = 0; i < n; i++)
    {
        rects[i].area = rects[i].length * rects[i].width;
    }
}

int findLargestArea(int n, Rectangle rects[])
{
    int largest = 0;

    for(int i = 1; i < n; i++)
    {
        if(rects[i].area > rects[largest].area)
        {
            largest = i;
        }
    }

    return largest;
}

void output(int largestIndex, Rectangle rects[])
{
    printf("\nLargest Rectangle Details:\n");
    printf("Length = %.2f\n", rects[largestIndex].length);
    printf("Width = %.2f\n", rects[largestIndex].width);
    printf("Area = %.2f\n", rects[largestIndex].area);
}