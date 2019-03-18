/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** miniloop
*/

#include "mysh.h"

int my_shell(main_var_t *vars)
{
    char **argv = NULL;

    while (!vars->do_exit) {
        argv = get_input(vars);
        vars->do_exit = argv ? check_exit(argv) : vars->do_exit;
        if (vars->do_exit)
            vars->exit_status = exit_sh(argv, vars);
        else if (!vars->do_exit && argv && my_memcmp(argv[0], "exit", -1) != 0)
            get_cmd(argv, vars);
        argv = free_table(argv);
    }
    my_puterror("exit");
    return (vars->exit_status);
}