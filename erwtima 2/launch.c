//#include "ipc_utils.h"
#include "passenger.c"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_PASSENGERS 100

typedef struct {
    Lifeboat *lifeboat;
    int id;
} PassengerArgs;

void *passenger_thread(void *args) {
    PassengerArgs *p_args = (PassengerArgs *)args;
    passenger(p_args->lifeboat);
    free(p_args);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Χρήση: %s <συνολικοί επιβάτες> <λέμβοι> <χωρητικότητα λέμβου>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int total_passengers = atoi(argv[1]);
    int total_lifeboats = atoi(argv[2]);
    int lifeboat_capacity = atoi(argv[3]);

    if (total_passengers > MAX_PASSENGERS) {
        fprintf(stderr, "Το μέγιστο πλήθος επιβατών είναι %d.\n", MAX_PASSENGERS);
        return EXIT_FAILURE;
    }

    // Δημιουργία λέμβων
    Lifeboat *lifeboats = malloc(total_lifeboats * sizeof(Lifeboat));
    for (int i = 0; i < total_lifeboats; i++) {
        lifeboat_init(&lifeboats[i], lifeboat_capacity);
    }

    // Δημιουργία νημάτων για τους επιβάτες
    pthread_t threads[MAX_PASSENGERS];
    for (int i = 0; i < total_passengers; i++) {
        PassengerArgs *args = malloc(sizeof(PassengerArgs));
        args->lifeboat = &lifeboats[i % total_lifeboats];
        args->id = i + 1;

        pthread_create(&threads[i], NULL, passenger_thread, args);
    }

    // Αναμονή για την ολοκλήρωση όλων των νημάτων
    for (int i = 0; i < total_passengers; i++) {
        pthread_join(threads[i], NULL);
    }

    // Καθαρισμός πόρων
    for (int i = 0; i < total_lifeboats; i++) {
        lifeboat_destroy(&lifeboats[i]);
    }
    free(lifeboats);

    printf("Όλοι οι επιβάτες ολοκλήρωσαν τη διαδικασία.\n");
    return EXIT_SUCCESS;
}
