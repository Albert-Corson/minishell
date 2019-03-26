/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** cd_func
*/

#include "mysh.h"

void update_pwd(main_var_t *vars, char *pwd)
{
    char **argv = malloc(sizeof(char *) * 4);
    char *new_pwd = getcwd(NULL, 0);

    argv[0] = "setenv";
    argv[1] = "OLDPWD";
    argv[2] = pwd;
    argv[3] = NULL;
    new_env(argv, vars, 3);
    argv[1] = "PWD";
    argv[2] = new_pwd;
    new_env(argv, vars, 3);
    free(new_pwd);
    free(pwd);
    free(argv);
    free(vars->pwd);
    vars->pwd = get_path();
}

void launch_cd(char **argv, main_var_t *vars)
{
    int nb = get_table_size(argv);
    char *pwd = getcwd(NULL, 0);

    if (nb == 1 || (nb == 2 && my_memcmp(argv[1], "~", -1) == 0)) {
        nb = chdir(get_env_var(vars->envp, "HOME=") + 5);
    } else if (nb == 2) {
        if (my_memcmp(argv[1], "-", -1) != 0)
            nb = chdir(argv[1]);
        else
            nb = chdir(get_env_var(vars->envp, "OLDPWD") + 7);
    } else {
        my_puterror("cd: Too many arguments.\n");
        free(pwd);
        return;
    }
    if (nb == -1) {
        perror(argv[1]);
        free(pwd);
        return;
    }
    update_pwd(vars, pwd);
}