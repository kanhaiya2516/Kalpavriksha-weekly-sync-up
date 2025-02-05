#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef enum { VIP = 1, SENIOR_CITIZEN = 2, GENERAL = 3 } PassengerType;

typedef struct
{
    int id;
    PassengerType type;
    char name[50];
} Passenger;

Passenger queue[MAX_PASSENGERS];
int size = 0;

void enqueue(int id, PassengerType type, char *name)
{
    if (size >= MAX_PASSENGERS)
    {
        printf("Queue is full!\n");
        return;
    }
    Passenger newPassenger = {id, type, ""};
    strncpy(newPassenger.name, name, 49);
    newPassenger.name[49] = '\0';

    int i = size - 1;
    while (i >= 0 && queue[i].type > newPassenger.type)
    {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = newPassenger;
    size++;
}

void dequeue()
{
    if (size == 0)
    {
        printf("No passengers to serve!\n");
        return;
    }
    printf("Serving Passenger: ID %d, Name: %s, Type: ", queue[0].id, queue[0].name);
    switch (queue[0].type)
    {
        case VIP: printf("VIP\n"); break;
        case SENIOR_CITIZEN: printf("SENIOR_CITIZEN\n"); break;
        case GENERAL: printf("GENERAL\n"); break;
    }
    for (int i = 1; i < size; i++)
    {
        queue[i - 1] = queue[i];
    }
    size--;
}

void displayQueue()
{
    if (size == 0)
    {
        printf("No waiting passengers.\n");
        return;
    }
    printf("Waiting Passengers:\n");
    for (int i = 0; i < size; i++)
    {
        printf("ID %d, Name: %s, Type: ", queue[i].id, queue[i].name);
        switch (queue[i].type)
        {
            case VIP: printf("VIP\n"); break;
            case SENIOR_CITIZEN: printf("SENIOR_CITIZEN\n"); break;
            case GENERAL: printf("GENERAL\n"); break;
        }
    }
}

int main()
{
    int n, operation, id;
    char name[50], typeStr[20];
    PassengerType type;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &operation);
        if (operation == 1)
        {
            scanf("%d %s %[^\n]s", &id, typeStr, name);
            if (strcmp(typeStr, "VIP") == 0) type = VIP;
            else if (strcmp(typeStr, "SENIOR_CITIZEN") == 0) type = SENIOR_CITIZEN;
            else type = GENERAL;
            enqueue(id, type, name);
        }
        else if (operation == 2)
        {
            dequeue();
        }
        else if (operation == 3)
        {
            displayQueue();
        }
    }
    return 0;
}