/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** env_check_var
*/

#include "mysh.h"

static int check_char(char c)
{
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
        if ((c < '0' || c > '9') && c != '_')
            return (0);
    }
    return (1);
}

int check_env_var(char *new)
{
    int i = 1;

    if (!((new[0] >= 'A' && new[0] <= 'Z') || (new[0] >= 'a' && new[0] <= 'z')))
        return (0);
    while (new[i]) {
        if (!check_char(new[i]))
            return (0);
        ++i;
    }
    return (1);
}

void add_var_to_env(int nb_arg, int env_size, char **argv, main_var_t *vars)
{
    if (nb_arg > 3)
        my_puterror("setenv: Too many arguments.\n");
    else {
        ++env_size;
        if (!check_env_var(argv[1])) {
            my_puterror("setenv: Variable name must");
            my_puterror(" contain alphanumeric characters.\n");
            return;
        } else if (get_env_var(vars->envp, argv[1]) == NULL)
            ++env_size;
        vars->envp = add_envp(vars->envp, argv, env_size);
    }
}