/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** env_func
*/

#include "mysh.h"

char **add_envp(char **envp, char **argv, int to_malloc)
{
    int i = 0;
    int check = 0;
    char *env_var = my_copycat(my_strdup(argv[1]), "=", -1);
    char **new = malloc(sizeof(char *) * to_malloc);

    env_var = argv[2] ? my_copycat(env_var, argv[2], -1) : env_var;
    while (envp[i]) {
        if (my_memcmp(envp[i], argv[1], my_strlen(argv[1])) == 0 && !check) {
            new[i] = env_var;
            check = 1;
        } else
            new[i] = my_strdup(envp[i]);
        ++i;
    }
    if (check == 0) {
        new[i] = env_var;
        ++i;
    }
    new[i] = NULL;
    free_table(envp);
    return (new);
}

char **remove_envp(char **envp, char *to_remove, int to_malloc)
{
    int i = 0;
    int n = 0;
    int len = my_strlen(to_remove);
    char **new = malloc(sizeof(char *) * to_malloc);

    while (envp && envp[i]) {
        if (my_memcmp(envp[i], to_remove, len) != 0) {
            new[n] = envp[i];
            ++n;
        } else
            free(envp[i]);
        ++i;
    }
    new[n] = NULL;
    return (new);
}

void new_env(char **argv, main_var_t *vars, int nb_arg)
{
    int env_size = get_table_size(vars->envp);

    if (get_table_size(argv) == 3 && my_memcmp(argv[2], "=", 1) == 0) {
        if (my_nisnum(argv[2] + 1, -1) && my_getnbr(argv[2] + 1) == 0) {
            free(argv[2]);
            argv[2] = getcwd(NULL, 0);
        } else if (my_nisnum(argv[2] + 1, -1) && my_getnbr(argv[2] + 1) != 0) {
            my_puterror("Directory stack not that deep.\n");
            return;
        }
    }
    add_var_to_env(nb_arg, env_size, argv, vars);
}

void rm_env(char **argv, main_var_t *vars, int nb_arg)
{
    int env_size = 0;
    int i = 1;

    if (nb_arg < 2) {
        my_puterror("unsetenv: Too few arguments.\n");
        return;
    }
    while (argv[i]) {
        if (get_env_var(vars->envp, argv[i]) != NULL) {
            env_size = get_table_size(vars->envp);
            vars->envp = remove_envp(vars->envp, argv[i], env_size);
        }
        ++i;
    }
}

void show_env(char **envp, int nb_arg)
{
    if (nb_arg != 1) {
        my_puterror("env: No arguments expected\n");
        return;
    }
    nb_arg = 0;
    while (envp && envp[nb_arg]) {
        my_putstr(envp[nb_arg]);
        my_putstr("\n");
        ++nb_arg;
    }
}