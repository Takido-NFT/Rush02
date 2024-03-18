/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:15:32 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/14 16:15:32 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <stdlib.h>

#define MAX 20

char	*sizelittle(char *numalt, char *strnum)
{
	if (numalt[0] == '0')
	{
		numalt[0] = strnum[2];
		numalt[1] = '\0';
	}
	else
	{
		numalt[0] = strnum[1];
		numalt[1] = strnum[2];
		numalt[2] = '\0';
	}
	return (numalt);
}

char	*highnumalt(char *numalt, char *strnum, char *join, char *dictstr)
{
	numalt[0] = strnum[1];
	numalt[1] = '0';
	numalt[2] = '\0';
	ft_strcat(join, " ");
	ft_strcat(join, \
		ft_low(ft_dict_line(numalt, dictstr)));
	numalt[0] = strnum[2];
	numalt[1] = '\0';
	ft_strcat(join, " ");
	ft_strcat(join, \
		ft_low(ft_dict_line(numalt, dictstr)));
	return (join);
}

char	*sizetwo(char *strnum, char *numalt, char *join, char *dictstr)
{
	if (ft_atoi(strnum) > 20)
	{
		numalt[0] = strnum[0];
		numalt[1] = '0';
		numalt[2] = '\0';
		join = ft_low(ft_dict_line(numalt, dictstr));
		if (strnum[1] != '0')
		{
			numalt[0] = strnum[1];
			numalt[1] = '\0';
			ft_strcat(join, " ");
			ft_strcat(join, \
				ft_low(ft_dict_line(numalt, dictstr)));
		}
	}
	else if (ft_atoi(strnum) <= 20)
	{
		numalt[0] = strnum[0];
		numalt[1] = strnum[1];
		numalt[2] = '\0';
		join = ft_low(ft_dict_line(numalt, dictstr));
	}
	return (join);
}

char	*sizethree(char *strnum, char *numalt, char *join, char *dictstr)
{
	numalt[0] = strnum[0];
	numalt[1] = '\0';
	join = ft_low(ft_dict_line(numalt, dictstr));
	ft_strcat(join, " hundred");
	numalt[0] = strnum[1];
	numalt[1] = strnum[2];
	numalt[2] = '\0';
	if (ft_atoi(numalt) > 20)
		highnumalt(numalt, strnum, join, dictstr);
	else if (ft_atoi(numalt) > 0)
	{
		if (ft_atoi(numalt) <= 20)
			numalt = sizelittle(numalt, strnum);
		ft_strcat(join, " ");
		ft_strcat(join, \
			ft_low(ft_dict_line(numalt, dictstr)));
	}
	return (join);
}

char	*ft_split_numbers(char *strnum, char *dictstr)
{
	int		size;
	int		temp;
	char	numalt[MAX];
	char	*join;

	temp = ft_atoi(strnum);
	size = 0;
	while (temp > 0)
	{
		temp = temp / 10;
		size++;
	}
	join = (char *)malloc((MAX * size + 1) * sizeof(char));
	if (size == 1)
	{
		numalt[0] = strnum[0];
		numalt[1] = '\0';
		join = ft_low(ft_dict_line(numalt, dictstr));
	}
	else if (size == 2)
		join = sizetwo(strnum, numalt, join, dictstr);
	else if (size == 3)
		join = sizethree(strnum, numalt, join, dictstr);
	return (join);
}
