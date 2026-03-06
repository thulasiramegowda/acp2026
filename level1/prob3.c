#include <stdio.h>

typedef struct
{
    float length;
    float width;
    float area;
    float costPerUnit;
    float totalCost;
} Floor;

void inputDetails(int n, Floor floors[]);
void calculateCosts(int n, Floor floors[]);
int highestCostFloor(int n, Floor floors[]);
void displayHighestCost(int index, Floor floors[]);

int main()
{
    int n;

    printf("Enter number of floors: ");
    scanf("%d",&n);

    Floor floors[n];

    inputDetails(n, floors);

    calculateCosts(n, floors);

    int index = highestCostFloor(n, floors);

    displayHighestCost(index, floors);

    return 0;
}

void inputDetails(int n, Floor floors[])
{
    for(int i=0;i<n;i++)
    {
        printf("\nFloor %d\n",i+1);

        printf("Enter length: ");
        scanf("%f",&floors[i].length);

        printf("Enter width: ");
        scanf("%f",&floors[i].width);

        printf("Enter cost per unit: ");
        scanf("%f",&floors[i].costPerUnit);
    }
}

void calculateCosts(int n, Floor floors[])
{
    for(int i=0;i<n;i++)
    {
        floors[i].area = floors[i].length * floors[i].width;

        floors[i].totalCost = floors[i].area * floors[i].costPerUnit;
    }
}

int highestCostFloor(int n, Floor floors[])
{
    int index = 0;

    for(int i=1;i<n;i++)
    {
        if(floors[i].totalCost > floors[index].totalCost)
        {
            index = i;
        }
    }

    return index;
}

void displayHighestCost(int index, Floor floors[])
{
    printf("\nFloor with Highest Tiling Cost:\n");
    printf("Length = %.2f\n",floors[index].length);
    printf("Width = %.2f\n",floors[index].width);
    printf("Area = %.2f\n",floors[index].area);
    printf("Total Cost = %.2f\n",floors[index].totalCost);
}