/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** get_cmd
*/

#include "mysh.h"

char *get_next_dir(char *path, int index)
{
    int i = 0;
    char *rtn = NULL;

    while (path[i] && index != 0) {
        if (path[i] == ':')
            --index;
        ++i;
    }
    if (path[i] == 0)
        return (NULL);
    rtn = my_copycat(NULL, path + i, get_char_pos(path + i, ':'));
    rtn = my_copycat(rtn, "/", 1);
    return (rtn);
}

static char *look_in_dir(char *dir, char *goal)
{
    DIR *dd = opendir(dir);
    struct dirent *drnt = dd ? readdir(dd) : NULL;

    while (dd && drnt) {
        if (drnt->d_name[0] != '.' && my_memcmp(drnt->d_name, goal, -1) == 0) {
            closedir(dd);
            dir = my_copycat(dir, "/", 1);
            return (my_copycat(dir, goal, -1));
        }
        drnt = readdir(dd);
    }
    closedir(dd);
    return (NULL);
}

char *find_cmd_path(char *env, char *goal)
{
    int i = 0;
    char *dir = env ? get_next_dir(env, 0) : NULL;
    char *rtn = NULL;

    while (dir) {
        rtn = look_in_dir(dir, goal);
        if (rtn)
            return (rtn);
        ++i;
        free(dir);
        dir = get_next_dir(env, i);
    }
    free(dir);
    return (NULL);
}

char *get_cmd_path(char **argv, main_var_t *vars)
{
    char *path = NULL;

    if (!argv)
        return (NULL);
    path = find_cmd_path(get_env_var(vars->envp, "PATH=") + 5, argv[0]);
    if (!path)
        path = get_char_pos(argv[0], '/') == -1 ? NULL : my_strdup(argv[0]);
    if (!path || access(path, F_OK) || access(path, X_OK)) {
        my_puterror(argv[0]);
        my_puterror(": Command not found.\n");
        return (NULL);
    }
    if (!is_file(path)) {
        my_puterror(argv[0]);
        my_puterror(": Permission denied.\n");
        return (NULL);
    }
    return (path);
}

void launch_cmd(char **argv, main_var_t *vars)
{
    int child_status = 0;
    int child_pid = 0;
    char *path = get_cmd_path(argv, vars);

    if (!path)
        return;
    child_pid = fork();
    if (child_pid == -1) {
        perror("");
    } else if (child_pid == 0) {
        if (execve(path, argv, vars->envp) == -1)
            perror("");
    } else {
        waitpid(child_pid, &child_status, 0);
        kill(child_pid, 0);
    }
    vars->exit_status = check_child_status(path, child_status);
    free(path);
}