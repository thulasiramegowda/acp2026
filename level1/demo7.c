#include <stdio.h>

void input(char *name);
int calculate_name_length(char *name);
void compare_output(int len1, int len2);

int main()
{
    char name1[100], name2[100];
    int len1, len2;

    printf("Enter first student name: ");
    input(name1);

    printf("Enter second student name: ");
    input(name2);

    len1 = calculate_name_length(name1);
    len2 = calculate_name_length(name2);

    compare_output(len1, len2);

    return 0;
}

void input(char *name)
{
    scanf("%s", name);
}

int calculate_name_length(char *name)
{
    int length = 0;

    while(name[length] != '\0')
    {
        length++;
    }

    return length;
}

void compare_output(int len1, int len2)
{
    printf("Length of first name: %d\n", len1);
    printf("Length of second name: %d\n", len2);

    if(len1 > len2)
        printf("First student's name is longer\n");
    else if(len2 > len1)
        printf("Second student's name is longer\n");
    else
        printf("Both names have equal length\n");
}