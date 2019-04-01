/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <errno.h>


#define FAIL_IF(cond, ret) if (cond) return (ret)
#define FAIL_IF_VOID(cond) if (cond) return

typedef struct main_var {
    char **envp;
    char *pwd;
    char *group;
    int exit_status;
    int do_exit;
} main_var_t;

// LIB:
int my_puterror(char const *str);
char *my_copycat(char *dest, char *src, int lim);
int get_char_pos(char const *str, char goal);
unsigned long long my_strlen(char const *str);
unsigned long long my_putstr(char const *str);
char *my_strdup(char *src);
int my_memcmp(void *m1, void *m2, long n);
int my_putchar(char c);
char *my_strcpy(char *dest, char *src);
long long my_getnbr(char const *str);
char **my_tablendup(char **table, int lim, int to_malloc);
unsigned long long my_put_err_nbr(signed long long int nb);
int my_putchar_err(char c);
int my_nisnum(char *str, int lim);

// MINISHELL:
int my_shell(main_var_t *vars);
char *get_path(void);
char **get_argv(char *input);
char *get_env_var(char **envp, char *goal);
void go_launch(char **argv, char **envp);
int is_file(char *path);
int env_cmd(char **argv, main_var_t *vars);
void show_env(char **envp, int nb_arg);
void *free_table(char **table);
void rm_env(char **argv, main_var_t *vars, int nb_arg);
void new_env(char **argv, main_var_t *vars, int nb_arg);
void free_var(main_var_t *vars);
void show_prompt(main_var_t *vars);
int check_exit(char **argv);
void launch_cd(char **argv, main_var_t *vars);
void get_cmd(char **argv, main_var_t *vars);
char **get_input(main_var_t *vars);
int exit_sh(char **argv, main_var_t *vars);
int get_table_size(char **table);
int readjust_nb(int nb, int min, int max);
void launch_cmd(char **argv, main_var_t *vars);
int check_child_status(char *path, int child_status);

#endif /* !MYSH_H_ */