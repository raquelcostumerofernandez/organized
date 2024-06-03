/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main for proyect organized
*/

#include "../shell/shell.h"
#include <stdlib.h>
#include <stddef.h>
#include "../lib/my/include/my.h"

int typeaproval(char *args)
{
    if (my_strcmp(args, "WIRE") != 0 &&
    my_strcmp(args, "SENSOR") != 0 && my_strcmp(args,
    "PROCESSOR") != 0 && my_strcmp(args, "DEVICE") != 0
    && my_strcmp(args, "ACTUATOR") != 0){
        return (-1);
    }
    return (0);
}

int get_argc(char **args)
{
    int argc = 0;

    while (args[argc] != NULL) {
        argc ++;
    }
    if (argc <= 1){
        write(2, "Too few arguments\n", 18);
        return (84);
    }
    return (argc);
}

int main(int argc, char __attribute__((unused)) **argv)
{
    list_t l = {NULL};

    if (argc > 1){
        write(2, "Too many arguments\n", 20);
        return (84);
    }
    if (workshop_shell(&l) == 1)
        return (84);
    return (0);
}