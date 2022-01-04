#ifndef LAPS_H
#define LAPS_H

/* System header*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * cars - struct of a car
 * @id: id of car.
 * @laps: number of laps completed by the car.
 * @next: pointer to the next car (node).
 */
typedef struct cars
{
        int id;
        size_t laps;
        struct cars *next;
} struct_car;

void race_state(int *id, size_t size);
struct_car *get_car(struct_car *head_race, int id);
void add_car(struct_car **head_race, int id);
void free_cars(struct_car *head);

#endif /* End of LAPS_H*/
