/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:20:17 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/02/28 11:20:17 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER 1000

char	*ft_split_dict(char *dictstr)
{
	int		i;
	int		j;
	int		new_line;
	char	*newdict;

	i = 0;
	j = 0;
	new_line = 0;
	newdict = (char *)malloc(BUFFER * sizeof(char));
	if (newdict == NULL)
		return (NULL);
	while (dictstr[i] != '\0')
	{
		if (dictstr[i] == '\n' && new_line <= 29)
			new_line++;
		i++;
		if (new_line == 29)
		{
			while (dictstr[i] != '\0')
				newdict[j++] = dictstr[i++];
		}
	}
	newdict[j] = '\0';
	return (newdict);
}
