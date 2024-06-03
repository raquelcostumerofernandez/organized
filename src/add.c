/*
** EPITECH PROJECT, 2023
** add.c
** File description:
** functions named on the shell make them function
*/

#include "../shell/shell.h"
#include <stdlib.h>
#include "../include/my.h"

void addlinked(list_t *list, char *name, unsigned int id, char *type)
{
    inventory_t *data = malloc(sizeof(inventory_t));

    data->ID = id;
    data->name = my_strdup(name);
    data->type = my_strdup(type);
    data->next = list->first;
    list->first = data;
}

int add(void *data, char **args)
{
    list_t *invent = data;
    int i = 0;
    static int id = 0;

    if (args[0] == NULL)
        return (1);
    while (args[i] != NULL && i != 500) {
        if (check_type(args, i) == 1)
            return (1);
        addlinked(invent, args[i + 1], id, args[i]);
        my_printf("%s n°%d - %c%s%c %s\n", args[i],
            id, '"', args[i + 1], '"', "added.");
        i += 2;
        id++;
    }
    return (0);
}

int disp(void *data, char **args)
{
    inventory_t *invent = ((list_t *)data)->first;

    while (invent != NULL) {
        my_printf("%s n°%d - \"%s\"\n", invent->type,
            invent->ID, invent->name);
        invent = invent->next;
    }
    return (0);
}