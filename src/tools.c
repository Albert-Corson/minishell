/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** tools
*/

#include "mysh.h"

int readjust_nb(int nb, int min, int max)
{
    while (nb < min)
        nb -= (min - max) - 1;
    while (nb > max)
        nb += (min - max) - 1;
    return (nb);
}

int get_table_size(char **table)
{
    int i = 0;

    while (table && table[i])
        ++i;
    return (i);
}

char *get_env_var(char **envp, char *goal)
{
    int i = 0;
    int len = my_strlen(goal);

    while (envp[i]) {
        if (my_memcmp(envp[i], goal, len) == 0)
            return (envp[i]);
        ++i;
    }
    return (NULL);
}

int is_file(char *path)
{
    struct stat statbuf;

    if (lstat(path, &statbuf) != 0 || S_ISDIR(statbuf.st_mode))
        return (0);
    return (1);
}

int check_child_status(char *path, int child_status)
{
    if (!WIFEXITED(child_status)) {
        my_puterror(path);
        my_puterror(": exited with RC: ");
        my_put_err_nbr(child_status);
        my_puterror("\n");
    }
    return (WTERMSIG(child_status));
}