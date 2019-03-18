/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** free
*/

#include "mysh.h"

void *free_table(char **table)
{
    int i = 0;

    if (!table)
        return (NULL);
    while (table[i]) {
        free(table[i]);
        ++i;
    }
    free(table);
    return (NULL);
}

void free_var(main_var_t *vars)
{
    free_table(vars->envp);
    free(vars->pwd);
    free(vars->group);
    free(vars);
}