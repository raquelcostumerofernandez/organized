/*
** EPITECH PROJECT, 2023
** del.c
** File description:
** delate
*/

#include <stdlib.h>
#include "../shell/shell.h"

void remove_linked(inventory_t *inventory, int unsigned id)
{
    inventory_t *temp = inventory->next;
    inventory_t *prev = NULL;

    if (temp->ID == id && temp != NULL) {
        inventory = temp->next;
        free(inventory->name);
        free(inventory);
    }
    while (temp != NULL && temp->ID != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp->name);
    free(temp);
}

void freeinventory(inventory_t *inventory)
{
    free(inventory->name);
    free(inventory->type);
    free(inventory);
}

void printdel(inventory_t *inventory)
{
    my_printf("%s n°%u - %c%s%c %s\n",
    inventory->type, inventory->ID, '"', inventory->name, '"', "deleted.");
    return;
}

void delete_first(list_t *list)
{
    inventory_t *now = list->first;

    list->first = list->first->next;
    freeinventory(now);
}

void delete(list_t *list, unsigned int id)
{
    inventory_t *now;
    inventory_t *pre;

    if (list->first->ID == id) {
        printdel(list->first);
        delete_first(list);
        return;
    }
    now = list->first->next;
    pre = list->first;
    while (now != NULL) {
        if (now->ID == id) {
            printdel(now);
            pre->next = now->next;
            freeinventory(now);
            return;
        }
        pre = now;
        now = now->next;
    }
}

int check_type(char **args, int i)
{
    if (typeaproval(args[i]) == 0 && args[i + 1] == NULL)
        return (1);
    if (typeaproval(args[i]) == -1 && args[i + 1] == NULL)
        return (1);
    else
        return (0);
}

int del(void *data, char **args)
{
    list_t *list = data;
    int i = 0;

    if (list->first == NULL)
        return (1);
    while (args[i] != NULL && i != 500) {
        delete(data, my_getnbr(args[i]));
        i++;
    }
    return (0);
}
