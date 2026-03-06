#include <stdio.h>

typedef struct
{
    int units;
    float rate;
    float total_bill;
} ElectricityBill;

ElectricityBill input();
ElectricityBill calculate_bill(ElectricityBill bill);
void output(ElectricityBill bill);

int main()
{
    ElectricityBill bill;

    bill = input();

    bill = calculate_bill(bill);

    output(bill);

    return 0;
}

ElectricityBill input()
{
    ElectricityBill bill;

    printf("Enter units consumed: ");
    scanf("%d", &bill.units);

    printf("Enter rate per unit: ");
    scanf("%f", &bill.rate);

    return bill;
}

ElectricityBill calculate_bill(ElectricityBill bill)
{
    if(bill.units < 50)
    {
        bill.total_bill = 0;
        printf("Free unit consumption scheme applied.\n");
    }
    else
    {
        bill.total_bill = bill.units * bill.rate;
    }

    return bill;
}

void output(ElectricityBill bill)
{
    printf("\nUnits Consumed: %d\n", bill.units);
    printf("Rate per Unit: %.2f\n", bill.rate);
    printf("Total Bill: %.2f\n", bill.total_bill);
}