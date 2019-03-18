/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Task07
*/

#include "mysh.h"

unsigned long long my_put_err_nbr(signed long long int nb)
{
    unsigned long long int nb_len = 1;

    if (nb < 10 && nb > -10) {
        if (nb < 0) {
            my_putchar_err(45);
            ++nb_len;
            my_putchar_err((nb * -1) + 48);
        } else
            my_putchar_err(nb + 48);
    } else if (nb < 0) {
        my_putchar_err('-');
        ++nb_len;
        nb_len += my_put_err_nbr((nb / 10) * -1);
        my_putchar_err(((nb % 10) * -1) + '0');
    } else {
        if (nb >= 10) {
            nb_len += my_put_err_nbr(nb / 10);
        }
        my_putchar_err((nb % 10) + '0');
    }
    return (nb_len);
}
