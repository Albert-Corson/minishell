/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** miniloop
*/

#include "mysh.h"

void pop_cmd(main_var_t *vars)
{
    cmd_list_t *tmp = NULL;

    FAIL_IF_VOID(!vars->cmd_list);
    tmp = vars->cmd_list;
    vars->cmd_list = vars->cmd_list->next;
    free(tmp->cmd);
    free(tmp);
}

int my_shell(main_var_t *vars)
{
    char **argv = NULL;

    while (!vars->do_exit) {
        fill_cmd_list(vars);
        if (vars->cmd_list)
            argv = get_argv(vars->cmd_list->cmd);
        vars->do_exit = argv ? check_exit(argv) : vars->do_exit;
        if (vars->do_exit)
            vars->exit_status = exit_sh(argv, vars);
        else if (!vars->do_exit && argv && my_memcmp(argv[0], "exit", -1) != 0)
            get_cmd(argv, vars);
        argv = free_table(argv);
        pop_cmd(vars);
    }
    my_puterror("exit");
    return (vars->exit_status);
}