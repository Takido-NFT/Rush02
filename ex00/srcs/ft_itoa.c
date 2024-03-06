/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:02:15 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/02/28 15:02:15 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <stdlib.h>

char	*ft_itoa(unsigned long long int num)
{
	char	*array;
	int		temp;
	int		i;
	int		size;

	size = 0;
	temp = num;
	array = (char *)malloc(sizeof(char) * size + 1);
	if (array == NULL)
		return (NULL);
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	array[size - 1] = '\0';
	num = temp;
	i = size;
	if (num == 0)
		array[0] = '0';
	while (num > 0)
	{
		temp = num % 10;
		num = num / 10;
		array[i - 1] = temp + '0';
		i--;
	}
	return (array);
}
