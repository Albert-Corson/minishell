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

void free_cmd_list(cmd_list_t *list)
{
    cmd_list_t *tmp = list;
    cmd_list_t *next = NULL;

    FAIL_IF_VOID(!list);
    next = list->next;
    while (next) {
        free(tmp->cmd);
        free(tmp);
        tmp = next;
        next = next->next;
    }
    free(tmp);
}

void free_var(main_var_t *vars)
{
    free_table(vars->envp);
    free(vars->pwd);
    free(vars->group);
    free_cmd_list(vars->cmd_list);
    free(vars);
}