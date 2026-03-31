#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char name[50];
    char team[50];
    float battingAvg;
    struct Player* next;
};

struct Player* insertPlayer(struct Player* head, char name[], char team[], float avg) {
    struct Player* newPlayer = (struct Player*)malloc(sizeof(struct Player));
    strcpy(newPlayer->name, name);
    strcpy(newPlayer->team, team);
    newPlayer->battingAvg = avg;
    newPlayer->next = NULL;

    if (head == NULL)
        return newPlayer;

    struct Player* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newPlayer;
    return head;
}

void displayHighAverage(struct Player* head) {
    struct Player* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->battingAvg >= 50) {
            printf("Name: %s, Team: %s, Batting Average: %.2f\n", temp->name, temp->team, temp->battingAvg);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        printf("No players with batting average >= 50\n");
}

int main() {
    struct Player* head = NULL;
    int n;
    char name[50], team[50];
    float avg;

    printf("Enter number of players: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("\nPlayer %d name: ", i + 1);
        fgets(name, 50, stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Team name: ");
        fgets(team, 50, stdin);
        team[strcspn(team, "\n")] = '\0';

        printf("Batting average: ");
        scanf("%f", &avg);
        getchar();

        head = insertPlayer(head, name, team, avg);
    }

    printf("\nPlayers with batting average >= 50:\n");
    displayHighAverage(head);

    return 0;
}