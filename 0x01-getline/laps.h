#ifndef LAPS_H
#define LAPS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct car_race-linked list of int value
 * @id: int value
 * @laps: laps
 * @next: pointer of the  next node
 */

typedef struct car_race
{
	int id;
	size_t laps;
	struct car_race *next;
} car_race;

void race_state(int *id, size_t size);
void check_list(car_race **head, int *id, size_t size);
void insert(car_race **head, car_race *newnode);
car_race *addnode(int id);
void print(car_race **head);
#endif
