#include <stdio.h>

typedef struct
{
    int consumerID;
    float unitsConsumed;
    float billAmount;
} Bill;

void input(int n, Bill bills[n]);
void calculate_Bills(int n, Bill bills[n]);
int findHighestBillIndex(int n, Bill bills[n]);
void displayHighestBill(int index, Bill bills[]);

int main()
{
    int n;

    printf("Enter number of consumers: ");
    scanf("%d", &n);

    Bill bills[n];

    input(n, bills);

    calculate_Bills(n, bills);

    int index = findHighestBillIndex(n, bills);

    displayHighestBill(index, bills);

    return 0;
}

void input(int n, Bill bills[n])
{
    for(int i=0;i<n;i++)
    {
        printf("\nConsumer %d\n", i+1);

        printf("Enter Consumer ID: ");
        scanf("%d",&bills[i].consumerID);

        printf("Enter units consumed: ");
        scanf("%f",&bills[i].unitsConsumed);
    }
}

void calculate_Bills(int n, Bill bills[n])
{
    float rate = 6;

    for(int i=0;i<n;i++)
    {
        bills[i].billAmount = bills[i].unitsConsumed * rate;
    }
}

int findHighestBillIndex(int n, Bill bills[n])
{
    int index = 0;

    for(int i=1;i<n;i++)
    {
        if(bills[i].billAmount > bills[index].billAmount)
        {
            index = i;
        }
    }

    return index;
}

void displayHighestBill(int index, Bill bills[])
{
    printf("\nConsumer with Highest Bill\n");
    printf("Consumer ID: %d\n", bills[index].consumerID);
    printf("Units Consumed: %.2f\n", bills[index].unitsConsumed);
    printf("Bill Amount: %.2f\n", bills[index].billAmount);
}