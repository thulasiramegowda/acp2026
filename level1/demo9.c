#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    float salary;
} Employee;

void inputEmployees(Employee e[], int n);
void writeToTextFile(Employee e[], int n, const char *filename);
float calculateTotalPayroll(const char *filename);
void displayExpenditure(float total);

int main()
{
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    Employee e[n];

    inputEmployees(e, n);

    writeToTextFile(e, n, "payroll.txt");

    float total = calculateTotalPayroll("payroll.txt");

    displayExpenditure(total);

    return 0;
}

void inputEmployees(Employee e[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEmployee %d\n", i+1);

        printf("Enter ID: ");
        scanf("%d", &e[i].id);

        printf("Enter Name: ");
        scanf("%s", e[i].name);

        printf("Enter Salary: ");
        scanf("%f", &e[i].salary);
    }
}

void writeToTextFile(Employee e[], int n, const char *filename)
{
    FILE *fp = fopen(filename, "w");

    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d %s %.2f\n", e[i].id, e[i].name, e[i].salary);
    }

    fclose(fp);
}

float calculateTotalPayroll(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    int id;
    char name[50];
    float salary, total = 0;

    while(fscanf(fp,"%d %s %f",&id,name,&salary)!=EOF)
    {
        total += salary;
    }

    fclose(fp);

    return total;
}

void displayExpenditure(float total)
{
    printf("\nTotal Salary Expenditure = %.2f\n", total);
}