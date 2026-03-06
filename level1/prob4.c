#include <stdio.h>

typedef struct
{
    int car_id;
    char model_name[50];
    int manufacture_year;
    float price;
} Car;

void readCars(int n, Car c[]);
void displayModernCars(int n, Car c[]);

int main()
{
    int n = 4;
    Car c[4];

    readCars(n, c);

    printf("\nModern Cars (Manufactured after 2022):\n");
    displayModernCars(n, c);

    return 0;
}

void readCars(int n, Car c[])
{
    for(int i=0;i<n;i++)
    {
        printf("\nEnter details for Car %d\n",i+1);

        printf("Car ID: ");
        scanf("%d",&c[i].car_id);

        printf("Model Name: ");
        scanf("%s",c[i].model_name);

        printf("Manufacture Year: ");
        scanf("%d",&c[i].manufacture_year);

        printf("Price: ");
        scanf("%f",&c[i].price);
    }
}

void displayModernCars(int n, Car c[])
{
    for(int i=0;i<n;i++)
    {
        if(c[i].manufacture_year > 2022)
        {
            printf("\nCar ID: %d", c[i].car_id);
            printf("\nModel: %s", c[i].model_name);
            printf("\nYear: %d", c[i].manufacture_year);
            printf("\nPrice: %.2f\n", c[i].price);
        }
    }
}