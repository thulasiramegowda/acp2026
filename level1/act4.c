#include <stdio.h>
#include <string.h>

typedef struct {
    int flight_number;
    char destination[50];
    int available_seats;
} Flight;

void readFlights(int n, Flight f[]);
void searchByDestination(int n, Flight f[], char searchDest[]);

int main()
{
    int n = 4;
    Flight f[4];
    char searchDest[50];

    readFlights(n, f);

    printf("\nEnter destination to search: ");
    scanf("%s", searchDest);

    searchByDestination(n, f, searchDest);

    return 0;
}

void readFlights(int n, Flight f[])
{
    for(int i = 0; i < n; i++)
    {
        printf("\nFlight %d\n", i+1);

        printf("Enter flight number: ");
        scanf("%d", &f[i].flight_number);

        printf("Enter destination: ");
        scanf("%s", f[i].destination);

        printf("Enter available seats: ");
        scanf("%d", &f[i].available_seats);
    }
}

void searchByDestination(int n, Flight f[], char searchDest[])
{
    int found = 0;

    for(int i = 0; i < n; i++)
    {
        if(strcmp(f[i].destination, searchDest) == 0)
        {
            printf("\nFlight available!\n");
            printf("Flight Number: %d\n", f[i].flight_number);
            found = 1;
        }
    }

    if(found == 0)
        printf("\nNo flight found for this destination.\n");
}