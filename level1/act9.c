#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

int main()
{
    int n, count;
    char filename[] = "students.txt";

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];
    Student studentsFromFile[n];

    inputStudents(students, n);

    writeToTextFile(students, n, filename);

    count = readFromTextFile(studentsFromFile, filename);

    printf("\nData read from file:\n");
    printStudents(studentsFromFile, count);

    return 0;
}

void inputStudents(Student students[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEnter details of student %d\n", i+1);
        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void writeToTextFile(Student students[], int n, const char *filename)
{
    FILE *fp = fopen(filename, "w");

    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d %s %f\n",
        students[i].id,
        students[i].name,
        students[i].marks);
    }

    fclose(fp);
}

int readFromTextFile(Student students[], const char *filename)
{
    FILE *fp = fopen(filename,"r");
    int i=0;

    while(fscanf(fp,"%d %s %f",
          &students[i].id,
          students[i].name,
          &students[i].marks) != EOF)
    {
        i++;
    }

    fclose(fp);
    return i;
}

void printStudents(Student students[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("ID: %d  Name: %s  Marks: %.2f\n",
        students[i].id,
        students[i].name,
        students[i].marks);
    }
}