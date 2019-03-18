/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** get_argv
*/

#include "mysh.h"

int put_in_argv(char **argv, char *input, int i, int n)
{
    int ck_1 = 32;
    int ck_2 = 9;

    argv[n] = my_copycat(NULL, "", -1);
    if (input[i] == 34 || input[i] == 39) {
        ck_1 = 0;
        ck_2 = input[i];
        ++i;
    }
    while (input[i] && input[i] != ck_1 && input[i] != ck_2 && input[i] != 10) {
        argv[n] = my_copycat(argv[n], input + i, 1);
        ++i;
    }
    return (i);
}

int check_word(char *input, int i)
{
    if (input[i + 1] != '\0' && input[i + 1] != ' ' && input[i + 1] != '\t') {
        if (input[i] == ' ' || input[i] == '\t')
            return (1);
    }
    if ((input[i] != ' ' || input[i] != '\t') && i == 0)
        return (1);
    return (0);
}

int get_nb_arg(char *input)
{
    char c = 0;
    int i = 0;
    int tmp = 0;
    int nb = 0;

    while (tmp >= 0 && input[i] && input[i] != '\n') {
        if (input[i] == '"' || input[i] == '\'') {
            c = input[i];
            tmp = get_char_pos(input + i + 1, input[i]);
            i += tmp + 1;
            ++nb;
        } else if (check_word(input, i))
            ++nb;
        ++i;
    }
    if (tmp < 0) {
        my_putstr("Unmatched '");
        my_putchar(c);
        my_putstr("'.\n");
    }
    return (tmp < 0 ? -1 : nb);
}

char **get_argv(char *input)
{
    int nb_arg = get_nb_arg(input);
    char **argv = NULL;
    int i = 0;
    int n = 0;

    if (nb_arg <= 0)
        return (NULL);
    argv = malloc(sizeof(char *) * (nb_arg + 1));
    if (!argv)
        return (NULL);
    while (input[i] && i >= 0 && input[i] != '\n') {
        if (input[i] != ' ' && input[i] != '\t') {
            i = put_in_argv(argv, input, i, n);
            ++n;
        }
        ++i;
    }
    argv[n] = NULL;
    return (argv);
}