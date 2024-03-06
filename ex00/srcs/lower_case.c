/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:06:24 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/04 11:06:24 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/ft.h"

char	*lower_case(char *str)
{
	int		i;
	int		j;
	char	*fin;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			j++;
		i++;
	}
	fin = (char *)malloc((j + 1) * sizeof(char));
	if (fin == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			fin[j++] = str[i];
		i++;
	}
	fin[j] = '\0';
	return (fin);
}
