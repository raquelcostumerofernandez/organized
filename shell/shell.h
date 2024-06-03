/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

// To be implemented

int add(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);
int del(void *data, char **args);
int typeaproval(char *args);
int errorhandling(char *type, char *name);

// Already implemented
int workshop_shell(void *data);

typedef enum type {
    ACTUATOR,
    DEVICES,
    PROCESSORS,
    SENSORS,
    WIRES
} type_t;

typedef struct inventory {
    char *name;
    unsigned int ID;
    char *type;
    struct inventory *next;
} inventory_t;

typedef struct list {
    inventory_t *first;
} list_t;

void remove_linked(inventory_t *inventory, int unsigned id);
void addlinked(list_t *list, char *name, unsigned int id, char *type);
void printdel(inventory_t *inventory);
void delete_first(list_t *list);
void delete(list_t *list, unsigned int id);
void freeinventory(inventory_t *inventory);
#endif /* SHELL_H */
