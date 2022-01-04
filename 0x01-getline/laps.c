#include "laps.h"

/**
 * race_state - function that keeps track a race
 * @id: array with identifiers of the cars.
 * @size: size of the array.
 */
void race_state(int *id, size_t size)
{
	struct_car *car = NULL;
	struct_car *temp = NULL;
	static struct_car *head_race;

	if (size == 0)
	{
		free_cars(head_race);
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		temp = head_race;
		car = get_car(temp, id[i]);
		if (car)
			car->laps++;
		else
			add_car(&head_race, id[i]);
	}

	printf("Race state:\n");
	temp = head_race;
	while (temp)
	{
		printf("Car %d [%lu laps]\n", temp->id, temp->laps);
		temp = temp->next;
	}
}

/**
 * car_exist - function that check if a car exist in a list.
 * @head: pointer to the list of cars.
 * @id: id of the car.
 *
 * Return: true if exist, otherwise false.
 */
struct_car *get_car(struct_car *head, int id)
{
	while (head)
	{
		if (head->id == id)
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * add_car - function that add new car to a list.
 * @head_race: pointer of the list.
 * @id: the id of car.
 */
void add_car(struct_car **head_race, int id)
{
	struct_car *new_car;
	struct_car *head = NULL;

	new_car = malloc(sizeof(*new_car));
	if (!new_car)
		return;
	new_car->id = id;
	new_car->laps = 0;
	new_car->next = NULL;

	if (!*head_race || (*head_race)->id >= id)
	{
		new_car->next = *head_race;
		*head_race = new_car;
		printf("Car %d joined the race\n", id);
		return;
	}
	else if ((*head_race)->id < id && (*head_race)->next == NULL)
	{
		(*head_race)->next = new_car;
		printf("Car %d joined the race\n", id);
		return;
	}

	head = *head_race;
	while (head->next)
	{
		if (head->next->id >= id)
		{
			new_car->next = head->next;
			head->next = new_car;
			printf("Car %d joined the race\n", id);
			return;

		}
		head = head->next;
	}
	head->next = new_car;
	printf("Car %d joined the race\n", id);
}

/**
 * free_cars - function that free the list with cars
 * @head: pointer to a list.
 */
void free_cars(struct_car *head)
{
	struct_car *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
