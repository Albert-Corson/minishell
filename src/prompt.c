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

char *get_input(main_var_t *vars)
{
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
    return (input);
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

void add_cmd_to_list(main_var_t *vars, char *str)
{
    cmd_list_t *new = NULL;
    cmd_list_t *tmp = vars->cmd_list;

    FAIL_IF_VOID(!str);
    new = malloc(sizeof(*new));
    new->next = NULL;
    new->cmd = str;
    if (!tmp) {
        vars->cmd_list = new;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void fill_cmd_list(main_var_t *vars)
{
    char *str = NULL;
    int stop = 0;
    int start = 0;

    FAIL_IF_VOID(vars->cmd_list);
    str = get_input(vars);
    while (stop != -1 && str && str[start]) {
        stop = get_char_pos(str + start, ';');
        add_cmd_to_list(vars, my_copycat(NULL, str + start, stop));
        start = stop;
        while (start != -1 && (str[start] == ';' || str[start] == ' '))
            ++start;
    }
}