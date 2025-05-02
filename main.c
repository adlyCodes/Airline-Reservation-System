#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000 // used for delete and modify

int seats;
int tickets;

struct flight {
int ticket;
char first_name[50];
char last_name[50];
int age;
char from[50];
char to[50];
};

void ticket() {
    fflush(stdin);

    struct flight f1;
    FILE* fn = fopen("seats.txt", "r");
    if (fn == NULL) {
        printf("Error opening seats.txt!\n");
        exit(1);
    }

    char buffer[100];
    if (fgets(buffer, sizeof(buffer), fn) != NULL) {
        seats = (int)strtol(buffer, NULL, 10);
    } else {
        printf("Error reading seats!\n");
        fclose(fn);
        exit(1);
    }
    fclose(fn);
    printf("Available seats: %d\n", seats);

    FILE* fy = fopen("tickets.txt", "r");
    if (fy == NULL) {
        printf("Error opening tickets.txt!\n");
        exit(1);
    }

    if (fgets(buffer, sizeof(buffer), fy) != NULL) {
        tickets = (int)strtol(buffer, NULL, 10);
    } else {
        printf("Error reading tickets!\n");
        fclose(fy);
        exit(1);
    }
    fclose(fy);
    printf("Booked tickets: %d\n", tickets);

    // Read passenger info
    printf("Please enter your first name: ");
    scanf("%s", f1.first_name);
    printf("Please enter your last name: ");
    scanf("%s", f1.last_name);
    printf("Please enter your age: ");
    scanf("%d", &f1.age);
    printf("From: ");
    scanf("%s", f1.from);
    printf("To: ");
    scanf("%s", f1.to);

    // Update seats and tickets
    tickets += 1;
    seats -= 1;

    // Append new ticket to data.txt
    FILE* fptr = fopen("data.txt", "a");
    if (fptr == NULL) {
        printf("Error opening data.txt!\n");
        exit(1);
    }
    fprintf(fptr, "%d  %s %s %d  %s %s\n", tickets, f1.first_name, f1.last_name, f1.age, f1.from, f1.to);
    fclose(fptr);

    // Write updated seat count
    FILE* fp = fopen("seats.txt", "w");
    if (fp == NULL) {
        printf("Error writing to seats.txt!\n");
        exit(1);
    }
    fprintf(fp, "%d", seats);
    fclose(fp);

    // Write updated ticket count
    FILE* ft = fopen("tickets.txt", "w");
    if (ft == NULL) {
        printf("Error writing to tickets.txt!\n");
        exit(1);
    }
    fprintf(ft, "%d", tickets);
    fclose(ft);
}

void show() {
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Not found!\n");
        exit(1);
    } else {
        int ch;
        while ((ch = fgetc(fp)) != EOF)
            putchar(ch);
    }
    fclose(fp);
}


void modify() {
    int target_ticket;
    printf("Enter ticket number to modify: ");
    scanf("%d", &target_ticket);

    FILE *fPtr = fopen("data.txt", "r");
    FILE *fTemp = fopen("replace.tmp", "w");

    if (fPtr == NULL || fTemp == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    struct flight f1;
    int found = 0;

    while (fscanf(fPtr, "%d %s %s %d %s %s\n", &f1.ticket, f1.first_name, f1.last_name, &f1.age, f1.from, f1.to) == 6) {
        if (f1.ticket == target_ticket) {
            found = 1;
            printf("Enter new first name: ");
            scanf("%s", f1.first_name);
            printf("Enter new last name: ");
            scanf("%s", f1.last_name);
            printf("Enter new age: ");
            scanf("%d", &f1.age);
            printf("From: ");
            scanf("%s", f1.from);
            printf("To: ");
            scanf("%s", f1.to);
        }
        fprintf(fTemp, "%d %s %s %d %s %s\n", f1.ticket, f1.first_name, f1.last_name, f1.age, f1.from, f1.to);
    }

    fclose(fPtr);
    fclose(fTemp);
    remove("data.txt");
    rename("replace.tmp", "data.txt");

    if (found)
        printf("Ticket modified successfully.\n");
    else
        printf("Ticket not found.\n");
}

void delete() {
    int target_ticket;
    printf("Enter ticket number to delete: ");
    scanf("%d", &target_ticket);

    FILE *fPtr = fopen("data.txt", "r");
    FILE *fTemp = fopen("replace.tmp", "w");

    if (fPtr == NULL || fTemp == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    struct flight f1;
    int found = 0;

    while (fscanf(fPtr, "%d %s %s %d %s %s\n", &f1.ticket, f1.first_name, f1.last_name, &f1.age, f1.from, f1.to) == 6) {
        if (f1.ticket != target_ticket) {
            fprintf(fTemp, "%d %s %s %d %s %s\n", f1.ticket, f1.first_name, f1.last_name, f1.age, f1.from, f1.to);
        } else {
            found = 1;
        }
    }

    fclose(fPtr);
    fclose(fTemp);
    remove("data.txt");
    rename("replace.tmp", "data.txt");

    if (found) {
        tickets--;
        seats++;

        FILE* ft = fopen("tickets.txt", "w");
        FILE* fs = fopen("seats.txt", "w");
        if (ft) {
            fprintf(ft, "%d", tickets);
            fclose(ft);
        }
        if (fs) {
            fprintf(fs, "%d", seats);
            fclose(fs);
        }

        printf("Ticket deleted successfully.\n");
    } else {
        printf("Ticket not found.\n");
    }
}

int main()
{

int selection = 0;


    while (selection != 9) {
        printf("\nType 1 to book a ticket\n");
        printf("Type 2 to show recently booked tickets\n");
        printf("Type 3 to modify a ticket\n");
        printf("Type 4 to delete a ticket\n");
        printf("Type 9 to exit the program\n");
        scanf("%d",&selection);
        if(selection == 1){
        ticket();
        }
        if(selection == 2){
        show();
        }
        if(selection == 3){
        modify();
        }
        if(selection == 4){
        delete();
         }

    }

}
