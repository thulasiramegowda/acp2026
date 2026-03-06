#include <stdio.h>

typedef struct
{
    float length;
    float width;
    float cost_per_unit;
    float total_cost;
} Floor;

void input(int n, Floor floors[]);
void calculate_costs(int n, Floor floors[]);
int findHighestCost(int n, Floor floors[]);
void displayHighest(int index, Floor floors[]);

int main()
{
    int n;

    printf("Enter number of floors: ");
    scanf("%d",&n);

    Floor floors[n];

    input(n, floors);

    calculate_costs(n, floors);

    int index = findHighestCost(n, floors);

    displayHighest(index, floors);

    return 0;
}

void input(int n, Floor floors[])
{
    for(int i=0;i<n;i++)
    {
        printf("\nFloor %d\n", i+1);

        printf("Enter length: ");
        scanf("%f",&floors[i].length);

        printf("Enter width: ");
        scanf("%f",&floors[i].width);

        printf("Enter cost per unit: ");
        scanf("%f",&floors[i].cost_per_unit);
    }
}

void calculate_costs(int n, Floor floors[])
{
    for(int i=0;i<n;i++)
    {
        floors[i].total_cost =
        floors[i].length * floors[i].width * floors[i].cost_per_unit;
    }
}

int findHighestCost(int n, Floor floors[])
{
    int index = 0;

    for(int i=1;i<n;i++)
    {
        if(floors[i].total_cost > floors[index].total_cost)
            index = i;
    }

    return index;
}

void displayHighest(int index, Floor floors[])
{
    printf("\nHighest Tiling Cost = %.2f", floors[index].total_cost);
}