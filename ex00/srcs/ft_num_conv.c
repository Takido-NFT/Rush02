/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:00:43 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/02/26 23:00:43 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft.h"

#define BUFFER 1000
#define MAX 20

char	*ft_get_num(char *chunkstr, char *join, int thousands, char *dict)
{
	static int	org_thousands;

	if (join == NULL)
	{
		join = chunkstr;
		org_thousands = thousands;
	}
	else
	{
		join = ft_strjoin(chunkstr, \
			ft_strjoin(ft_low(huge_num(thousands, dict, org_thousands)), \
				join, " "), " ");
		free(chunkstr);
	}
	return (join);
}

char	*ft_num_split(char *strnum, char *dict, int thousands, int zeros)
{
	unsigned long long int	number;
	char					*chunkstr;
	char					*join;
	int						chunk;

	number = ft_atoi(strnum);
	if (number == 0)
		return ("zero");
	if (ft_strlen(strnum) > 19)
		return ("Error");
	join = NULL;
	while (number > 0)
	{
		chunk = number % 1000;
		number /= 1000;
		if (chunk > 0)
		{
			chunkstr = ft_split_numbers(ft_itoa(chunk), dict);
			join = ft_get_num(chunkstr, join, thousands, dict);
			thousands++;
		}
		else
			zeros++;
	}
	join = ft_zeros(zeros, join, dict);
	return (join);
}

char	*ft_dict_line(char *num, char *dictstr)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	size = ft_strlen(num);
	ret = malloc(BUFFER * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (dictstr[i] != '\0')
	{
		if (size == 1 && (num[0] == dictstr[i]))
		{
			ret = ft_line(i, dictstr, ret);
			return (ret);
		}
		else if (size == 2 && ((num[0] == dictstr[i]) \
			&& (num[1] == dictstr[i + 1])))
		{
			ret = ft_line(i, dictstr, ret);
			return (ret);
		}
		i++;
	}
	return (ret);
}

char	*huge_num(int thousands, char *dictstr, int org_thousands)
{
	int		i;
	int		j;
	int		new_line;
	char	*strnum;

	i = 0;
	j = 0;
	new_line = org_thousands + 1;
	strnum = (char *)malloc((MAX + thousands * 3 + 1) * sizeof(char));
	if (strnum == NULL)
		return (NULL);
	dictstr = ft_split_dict(dictstr);
	while (new_line < thousands && dictstr[i] != '\0')
	{
		if (dictstr[i++] == '\n')
			new_line++;
	}
	while (dictstr[i] != '\n' && dictstr[i] != '\0')
		strnum[j++] = dictstr[i++];
	strnum[j] = '\0';
	return (strnum);
}
