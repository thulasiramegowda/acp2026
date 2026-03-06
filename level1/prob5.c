#include <stdio.h>

typedef struct
{
    char name[50];
    int age;
} Person;

void read_person(Person *p);
void print_person(Person *p);
void swap_person(Person *p1, Person *p2);

int main()
{
    Person p1, p2;

    printf("Enter details of Person 1:\n");
    read_person(&p1);

    printf("\nEnter details of Person 2:\n");
    read_person(&p2);

    printf("\nBefore Swapping:\n");
    print_person(&p1);
    print_person(&p2);

    swap_person(&p1, &p2);

    printf("\nAfter Swapping:\n");
    print_person(&p1);
    print_person(&p2);

    return 0;
}

void read_person(Person *p)
{
    printf("Enter Name: ");
    scanf("%s", p->name);

    printf("Enter Age: ");
    scanf("%d", &p->age);
}

void print_person(Person *p)
{
    printf("\nName: %s", p->name);
    printf("\nAge: %d\n", p->age);
}

void swap_person(Person *p1, Person *p2)
{
    Person temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}