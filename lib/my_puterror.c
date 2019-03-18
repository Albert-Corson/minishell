/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** task02
*/

#include "mysh.h"

int my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
    return (84);
}