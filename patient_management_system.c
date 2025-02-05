#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRITICAL 1
#define SERIOUS 2
#define STABLE 3

typedef struct Patient Patient;

struct Patient
{
    int id;
    int severity;
    Patient* next;
};

int getSeverityValue(char* severity)
{
    if (strcmp(severity, "Critical") == 0) return CRITICAL;
    if (strcmp(severity, "Serious") == 0) return SERIOUS;
    return STABLE;
}

void enqueue(Patient** head, int id, char* severity) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->id = id;
    newPatient->severity = getSeverityValue(severity);
    newPatient->next = NULL;

    if (*head == NULL)
    {
        *head = newPatient;
        return;
    }

    Patient* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newPatient;
}

void bubbleSort(Patient** head)
{
    int swapped;
    Patient *ptr1;
    Patient *lptr = NULL;

    if (*head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr)
        {
            if (ptr1->severity > ptr1->next->severity)
            {
                int tempId = ptr1->id;
                int tempSeverity = ptr1->severity;

                ptr1->id = ptr1->next->id;
                ptr1->severity = ptr1->next->severity;

                ptr1->next->id = tempId;
                ptr1->next->severity = tempSeverity;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void printPatients(Patient* head)
{
    while (head != NULL)
    {
        printf("%d ", head->id);
        if (head->severity == CRITICAL) printf("Critical\n");
        else if (head->severity == SERIOUS) printf("Serious\n");
        else printf("Stable\n");
        head = head->next;
    }
}

void freeList(Patient* head)
{
    Patient* temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
 {
    int n, id;
    char severity[10];
    Patient* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &id, severity);
        enqueue(&head, id, severity);
    }

    bubbleSort(&head);

    printPatients(head);

    freeList(head);
    return 0;
}