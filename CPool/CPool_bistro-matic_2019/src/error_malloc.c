/*
** EPITECH PROJECT, 2019
** error_malloc
** File description:
** Pour jeremy <3
*/

#include <stdlib.h>
#include "../include/bistromatic.h"
#include "../include/my.h"

void test_malloc(void const *ptr)
{
    if (ptr == NULL) {
        my_putstr2(ERROR_MSG);
        exit(84);
    }
}
