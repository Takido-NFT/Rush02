/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_dict_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:52:39 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/05 20:52:39 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/ft.h"

int count_dict_line(char *dictstr)
{
    int i;
    int new_line;

    i = 0;
    new_line = 0;
    while (dictstr[i] != '\0')
    {
        if (dictstr[i] == '\n')
            new_line++;
        i++;
    }
    return (new_line);
}
