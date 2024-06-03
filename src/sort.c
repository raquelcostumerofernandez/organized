/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort.c
*/

#include "../shell/shell.h"
#include <stdlib.h>
#include "../include/my.h"

int swapid(inventory_t *now, inventory_t *next)
{
    inventory_t *c = malloc(sizeof(inventory_t));
    int swap = 0;

    if (now->ID > next->ID) {
        c->name = now->name;
        c->ID = now->ID;
        c->type = now->type;
        now->name = next->name;
        now->ID = next->ID;
        now->type = next->type;
        next->name = c->name;
        next->ID = c->ID;
        next->type = c->type;
        swap++;
    }
    return (swap);
}

int sort(void *data, char **args)
{
    inventory_t *invent = ((list_t *)data)->first;
    inventory_t *now = invent;
    inventory_t *next = NULL;
    int swap = 1;

    while (swap != 0) {
        swap = 0;
        next = now;
        while (next != NULL) {
            swap = swap + swapid(now, next);
            next = next->next;
        }
        now = now->next;
    }
    return (0);
}
