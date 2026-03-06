#include <stdio.h>

typedef struct
{
    char name[50];
    float length;
    float width;
    float cost_per_unit;
    float total_cost;
} Floor;

Floor input();
float calculate_cost(Floor floor);
void compare_costs(Floor f1, Floor f2, Floor f3);

int main()
{
    Floor f1, f2, f3;

    printf("Enter details for Floor 1\n");
    f1 = input();
    f1.total_cost = calculate_cost(f1);

    printf("\nEnter details for Floor 2\n");
    f2 = input();
    f2.total_cost = calculate_cost(f2);

    printf("\nEnter details for Floor 3\n");
    f3 = input();
    f3.total_cost = calculate_cost(f3);

    compare_costs(f1, f2, f3);

    return 0;
}

Floor input()
{
    Floor f;

    printf("Enter floor name: ");
    scanf("%s", f.name);

    printf("Enter length: ");
    scanf("%f",&f.length);

    printf("Enter width: ");
    scanf("%f",&f.width);

    printf("Enter cost per unit: ");
    scanf("%f",&f.cost_per_unit);

    return f;
}

float calculate_cost(Floor floor)
{
    return floor.length * floor.width * floor.cost_per_unit;
}

void compare_costs(Floor f1, Floor f2, Floor f3)
{
    printf("\nTotal Cost of %s = %.2f", f1.name, f1.total_cost);
    printf("\nTotal Cost of %s = %.2f", f2.name, f2.total_cost);
    printf("\nTotal Cost of %s = %.2f\n", f3.name, f3.total_cost);

    if(f1.total_cost > f2.total_cost && f1.total_cost > f3.total_cost)
        printf("\nMost Expensive Floor: %s", f1.name);

    else if(f2.total_cost > f1.total_cost && f2.total_cost > f3.total_cost)
        printf("\nMost Expensive Floor: %s", f2.name);

    else
        printf("\nMost Expensive Floor: %s", f3.name);
}