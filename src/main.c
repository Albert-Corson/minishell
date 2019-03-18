/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main
*/

#include "mysh.h"

int main(int argc, char **argv, char **envp)
{
    int rtn = 0;
    char *tmp = get_env_var(envp, "GROUP=");
    main_var_t *vars = NULL;

    argv = argv;
    if (argc != 1) {
        my_puterror("./mysh takes no arguments\n");
        return (84);
    }
    if (signal(SIGINT, SIG_IGN) != SIG_IGN)
        signal(SIGINT, SIG_IGN);
    vars = malloc(sizeof(*vars));
    vars->envp = my_tablendup(envp, -1, -1);
    vars->exit_status = 0;
    vars->do_exit = 0;
    vars->pwd = get_path();
    vars->group = my_strdup(tmp ? tmp + 6 : "");
    rtn = my_shell(vars);
    my_putchar('\n');
    free_var(vars);
    return (rtn);
}