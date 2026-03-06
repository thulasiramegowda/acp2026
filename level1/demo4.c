#include <stdio.h>

typedef struct
{
    char player_name[50];
    int jersey_number;
    int runs_scored;
} Player;

void readPlayers(int n, Player p[]);
float calculateAverageRuns(int n, Player p[]);

int main()
{
    int n = 11;

    Player p[11];

    readPlayers(n,p);

    float avg = calculateAverageRuns(n,p);

    printf("\nAverage Runs Scored by Team: %.2f\n", avg);

    return 0;
}

void readPlayers(int n, Player p[])
{
    for(int i=0;i<n;i++)
    {
        printf("\nPlayer %d\n", i+1);

        printf("Enter player name: ");
        scanf("%s", p[i].player_name);

        printf("Enter jersey number: ");
        scanf("%d", &p[i].jersey_number);

        printf("Enter runs scored: ");
        scanf("%d", &p[i].runs_scored);
    }
}

float calculateAverageRuns(int n, Player p[])
{
    int total = 0;

    for(int i=0;i<n;i++)
    {
        total += p[i].runs_scored;
    }

    return (float)total/n;
}