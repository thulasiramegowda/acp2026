#include <stdio.h>

typedef struct {
    float length;
    float width;
    float area;
} Rectangle;

int main() {

    int n, i, maxIndex = 0;

    printf("Enter number of rectangles: ");
    scanf("%d", &n);

    Rectangle r[n];

    for(i = 0; i < n; i++) {

        printf("\nRectangle %d\n", i+1);

        printf("Enter length: ");
        scanf("%f", &r[i].length);

        printf("Enter width: ");
        scanf("%f", &r[i].width);

        r[i].area = r[i].length * r[i].width;
    }

    printf("\nAreas of rectangles:\n");

    for(i = 0; i < n; i++) {
        printf("Rectangle %d Area = %.2f\n", i+1, r[i].area);

        if(r[i].area > r[maxIndex].area)
            maxIndex = i;
    }

    printf("\nRectangle %d has the largest area = %.2f\n",
           maxIndex + 1, r[maxIndex].area);

    return 0;
}