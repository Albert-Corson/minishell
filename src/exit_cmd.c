/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** exit_cmd
*/

#include "mysh.h"

int check_synthax(char **argv, int nb_arg)
{
    char *num = my_copycat(NULL, argv[1], -1);
    int i = 1;

    num = (nb_arg == 3) ? my_copycat(num, argv[2], -1) : num;
    if (num[0] != 43 && num[0] != 45 && num[0] < 48 && num[0] > 57) {
        my_puterror("exit: Expression Syntax.\n");
        free(num);
        return (0);
    }
    while (num[i]) {
        if (num[0] < 48 && num[0] > 57) {
            my_puterror("exit: Expression Syntax.\n");
            free(num);
            return (0);
        }
        ++i;
    }
    free(num);
    return (1);
}

int check_exit(char **argv)
{
    int i = 0;

    if (my_memcmp(argv[0], "exit", -1) != 0)
        return (0);
    while (argv[i])
        ++i;
    if (i > 3) {
        my_puterror("exit: Expression Syntax.\n");
        return (0);
    }
    return (i > 1 ? check_synthax(argv, i) : 1);
}

int exit_sh(char **argv, main_var_t *vars)
{
    int i = 0;
    char *num = NULL;

    while (argv && argv[i])
        ++i;
    if (!argv)
        return (vars->exit_status);
    if (i == 1)
        return (0);
    num = my_copycat(NULL, argv[1], -1);
    num = (i == 3) ? my_copycat(num, argv[2], -1) : num;
    i = my_getnbr(num);
    i = readjust_nb(i, 0, 255);
    free(num);
    return (i);
}