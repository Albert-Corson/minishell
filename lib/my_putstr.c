/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** task02
*/

#include "mysh.h"

unsigned long long my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (my_strlen(str));
}