/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:49:08 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/14 14:49:08 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_num_size(unsigned long long int number)
{
	int	size;

	size = 0;
	if (number == 0)
		return (1);
	while (number > 999999)
	{
		number = number / 1000;
		size++;
	}
	return (size);
}

char	*ft_zeros(int zeros, char *join, char *dict)
{
	if (zeros > 0)
	{
		ft_strcat(join, " ");
		ft_strcat(join, ft_low(huge_num(zeros, dict)));
	}
	return (join);
}

char	*ft_line(int i, char *dictstr, char *ret)
{
	int	j;

	j = 0;
	while (dictstr[i] != '\n')
		ret[j++] = dictstr[i++];
	ret[j] = '\0';
	return (ret);
}
