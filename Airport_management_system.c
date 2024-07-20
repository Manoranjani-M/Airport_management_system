#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 50
#define MAX_PASSENGERS_PER_FLIGHT 100

struct Flight {
    char flightNumber[20];
    char destination [50];
    int capacity;
    int numPassengers;
    char passengers [MAX_PASSENGERS_PER_FLIGHT][50];
};

void displayFlights (const struct Flight flights[],int numFlights) {
    printf("\n--- Flights Information--\n");
    for (int i = 0; i < numFlights; i++) {
        printf("Flight %s to %s (%d/%d passengers)\n",flights[i].flightNumber, flights[i] .destination,flights[i].numPassengers, flights[i].capacity);
        for (int j=0;j<flights[i].numPassengers;j++) {
        printf("Passenger %d: %s\n", j+1, flights[i] .passengers[j]);
        }
    printf("------------------------------");
    }
}

void addPassenger (struct Flight *flight,
const char *passengerName) {
    if (flight->numPassengers < flight->capacity) {
        strcpy(flight->passengers [flight->numPassengers],passengerName);
        flight->numPassengers++;
        printf("Passenger %s added to the flight %s.\n",passengerName, flight->flightNumber);
    } 

    else {
        printf("Flight %s is full.Cannot add more passengers.\n",flight->flightNumber);
    }
}

int main() {
struct Flight flights [MAX_FLIGHTS];
int numFlights = 0;
int choice;
    do {
        printf("\nAirport Management System\n");
        printf("1. Display Flights\n");
        printf("2. Add Flight\n");
        printf("3. Add Passenger to Flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlights (flights, numFlights); 
                break;
            case 2:
                if (numFlights < MAX_FLIGHTS) {
                    printf("Enter flight number: ");
                    scanf("%s", flights [numFlights].flightNumber);
                    printf("Enter destination: ");
                    scanf("%s", flights [numFlights].destination);
                    printf("Enter capacity: ");
                    scanf("%d", &flights [numFlights].capacity);
                    flights [numFlights].numPassengers = 0;
                    numFlights++;
                    printf("Flight added successfully!\n");
                } 
                else {
                    printf("Maximum number of flights reached.\n");
                }
                break;

            case 3:
                printf("Enter the flight number: ");
                char flightNumber[20];
                scanf("%s", flightNumber);

                int flightIndex = -1;
                for (int i = 0; i < numFlights; i++) {
                    if (strcmp(flights[i].flightNumber,flightNumber)==0){
                        flightIndex=i;
                        break;
                    }
                }
                if (flightIndex != -1) {
                    printf("Enter passenger name: ");
                    char passengerName [50];
                    scanf("%s", passengerName);

                    addPassenger (&flights [flightIndex], passengerName);
                }
                else {
                    printf("Flight not found.\n");
                }
                break;
            case 4:
                printf("Exiting the program. Thank you!\n"); 
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
        while (choice != 4);
    return 0;
}