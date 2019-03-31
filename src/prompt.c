/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** prompt
*/

#include "mysh.h"

void show_prompt(main_var_t *vars)
{
    my_putstr("[");
    if (vars && vars->group)
        my_putstr(vars->group);
    my_putstr(" ");
    if (vars && vars->pwd)
        my_putstr(vars->pwd);
    my_putstr("]$ ");
}

char **get_input(main_var_t *vars)
{
    char **argv = NULL;
    char *input = NULL;
    size_t len = 0;
    int check = 0;

    show_prompt(vars);
    check = getline(&input, &len, stdin);
    if (check == -1) {
        free(input);
        vars->do_exit = 1;
        return (NULL);
    }
    argv = get_argv(input);
    free(input);
    return (argv);
}

char *get_path(void)
{
    char *rtn = getcwd(NULL, 0);
    int i = my_strlen(rtn);
    char *tmp = NULL;

    while (i >= 0 && rtn[i] != '/')
        --i;
    tmp = my_copycat(tmp, rtn + i, -1);
    free(rtn);
    return (tmp);
}