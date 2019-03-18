/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** find_cmd
*/

#include "mysh.h"

int env_cmd(char **argv, main_var_t *vars)
{
    int nb_arg = get_table_size(argv);

    if (!argv)
        return (0);
    if (my_memcmp(argv[0], "env", -1) == 0) {
        show_env(vars->envp, nb_arg);
        return (1);
    } else if (my_memcmp(argv[0], "setenv", -1) == 0 && nb_arg == 1) {
        show_env(vars->envp, nb_arg);
        return (1);
    }
    if (my_memcmp(argv[0], "setenv", -1) == 0) {
        new_env(argv, vars, nb_arg);
        return (1);
    } else if (my_memcmp(argv[0], "unsetenv", -1) == 0) {
        rm_env(argv, vars--, nb_arg);
        return (1);
    }
    return (0);
}

void get_cmd(char **argv, main_var_t *vars)
{
    if (!argv)
        return;
    if (env_cmd(argv, vars))
        return;
    if (my_memcmp(argv[0], "cd", -1) == 0) {
        launch_cd(argv, vars);
        return;
    }
    if (argv)
        launch_cmd(argv, vars);
}