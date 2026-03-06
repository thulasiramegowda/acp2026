#include <stdio.h>

void input(char *str);
void count(char *str, int *vowels, int *consonants);
void display(char *str, int vowels, int consonants);

int main()
{
    char str[100];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    input(str);

    count(str, &vowels, &consonants);

    display(str, vowels, consonants);

    return 0;
}

void input(char *str)
{
    scanf("%s", str);
}

void count(char *str, int *vowels, int *consonants)
{
    int i = 0;

    while(str[i] != '\0')
    {
        char ch = str[i];

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            (*vowels)++;
        }
        else
        {
            (*consonants)++;
        }

        i++;
    }
}

void display(char *str, int vowels, int consonants)
{
    printf("\nString: %s\n", str);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}