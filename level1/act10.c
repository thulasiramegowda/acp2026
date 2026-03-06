#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

void inputStudents(Student students[], int n);
void writeToBinaryFile(Student students[], int n, const char *filename);
int readFromBinaryFile(Student students[], const char *filename);
void printStudents(Student students[], int n);

int main()
{
    int n, count;
    char filename[] = "students.dat";

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];
    Student studentsFromFile[n];

    inputStudents(students, n);

    writeToBinaryFile(students, n, filename);

    count = readFromBinaryFile(studentsFromFile, filename);

    printf("\nData read from binary file:\n");
    printStudents(studentsFromFile, count);

    return 0;
}

void inputStudents(Student students[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEnter details of student %d\n", i+1);

        printf("ID: ");
        scanf("%d",&students[i].id);

        printf("Name: ");
        scanf("%s",students[i].name);

        printf("Marks: ");
        scanf("%f",&students[i].marks);
    }
}

void writeToBinaryFile(Student students[], int n, const char *filename)
{
    FILE *fp = fopen(filename,"wb");

    fwrite(students, sizeof(Student), n, fp);

    fclose(fp);
}

int readFromBinaryFile(Student students[], const char *filename)
{
    FILE *fp = fopen(filename,"rb");

    int count = fread(students, sizeof(Student), 100, fp);

    fclose(fp);

    return count;
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