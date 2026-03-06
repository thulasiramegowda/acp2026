#include <stdio.h>
#include <string.h>

void inputStrings(char str1[], char str2[]);
int compareStrings(char str1[], char str2[]);
void output(int result);

int main()
{
    char str1[100], str2[100];
    int result;

    inputStrings(str1, str2);

    result = compareStrings(str1, str2);

    output(result);

    return 0;
}

void inputStrings(char str1[], char str2[])
{
    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);
}

int compareStrings(char str1[], char str2[])
{
    int res = strcmp(str1, str2);

    if(res == 0)
        return 0;
    else if(res > 0)
        return 1;
    else
        return -1;
}

void output(int result)
{
    if(result == 0)
        printf("Both strings are equal\n");
    else if(result == 1)
        printf("First string is lexicographically greater\n");
    else
        printf("Second string is lexicographically greater\n");
}