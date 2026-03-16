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

int main(){
    ElectricityBill bill;
    bill = input();
    bill = calculate_bill(bill);
    output(bill);
    return 0;
}
ElectricityBill input(){
    ElectricityBill bill;
    printf("enter units :");
    scanf("%d",&bill.units);
    printf("enter rate:");
    scanf("%f",&bill.rate);
    return bill;
}
ElectricityBill calculate_bill(ElectricityBill bill){
    ElectricityBill bill;
        bill.total_bill = bill.units * bill.rate;
        if(bill.units>100){
            bill.total_bill += (bill.units - 100) * 5;
            printf("High consumption alert extra! charge appiled \n");
        }
        return bill;    
}
void output(ElectricityBill bill){
   printf("the total bill is ",bill.total_bill);
}