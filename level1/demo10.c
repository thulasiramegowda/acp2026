#include <stdio.h>

typedef struct
{
    int flightNumber;
    char destination[50];
    float ticketPrice;
} Flight;

void inputFlights(Flight f[], int n);
void saveToBinary(Flight f[], int n, const char *filename);
Flight findMostExpensive(const char *filename);
void displayTopFlight(Flight f);

int main()
{
    int n;

    printf("Enter number of flights: ");
    scanf("%d",&n);

    Flight f[n];

    inputFlights(f,n);

    saveToBinary(f,n,"flights.bin");

    Flight expensive = findMostExpensive("flights.bin");

    displayTopFlight(expensive);

    return 0;
}

void inputFlights(Flight f[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nFlight %d\n",i+1);

        printf("Enter Flight Number: ");
        scanf("%d",&f[i].flightNumber);

        printf("Enter Destination: ");
        scanf("%s",f[i].destination);

        printf("Enter Ticket Price: ");
        scanf("%f",&f[i].ticketPrice);
    }
}

void saveToBinary(Flight f[], int n, const char *filename)
{
    FILE *fp = fopen(filename,"wb");

    fwrite(f,sizeof(Flight),n,fp);

    fclose(fp);
}

Flight findMostExpensive(const char *filename)
{
    FILE *fp = fopen(filename,"rb");

    Flight f, max;

    fread(&max,sizeof(Flight),1,fp);

    while(fread(&f,sizeof(Flight),1,fp)==1)
    {
        if(f.ticketPrice > max.ticketPrice)
        {
            max = f;
        }
    }

    fclose(fp);

    return max;
}

void displayTopFlight(Flight f)
{
    printf("\nMost Expensive Flight\n");
    printf("Flight Number: %d\n",f.flightNumber);
    printf("Destination: %s\n",f.destination);
    printf("Ticket Price: %.2f\n",f.ticketPrice);
}