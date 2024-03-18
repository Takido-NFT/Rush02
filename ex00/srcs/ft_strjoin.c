/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:47:55 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/03 00:47:55 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <stdlib.h>

#define MAX 20

char	*ft_strjoin(char *s1, char *s2, char *sep)
{
	int		len_s1;
	int		len_s2;
	int		len_sep;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_sep = ft_strlen(sep);
	result = (char *)malloc((len_s1 + len_s2 + len_sep + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcat(result, sep);
	ft_strcat(result, s2);
	return (result);
}

char	*ft_strcpy(char *fin, char *org)
{
	int	i;

	i = 0;
	while (org[i] != '\0')
	{
		fin[i] = org[i];
		i++;
	}
	fin[i] = '\0';
	return (fin);
}

char	*ft_strcat(char *fin, char *org)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (fin[i] != '\0')
	{
		start++;
		i++;
	}
	i = 0;
	while (org[i] != '\0')
	{
		fin[start] = org[i];
		i++;
		start++;
	}
	fin[start] = '\0';
	return (fin);
}
