/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:59:23 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/02/23 22:59:23 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft.h"

#define BUFFER 1000

char	*ft_file_check(char *dict);

int	main(int argc, char *argv[])
{
	char *str;
	char *dictstr;
	if (argc == 2)
	{
		if (is_numeric(argv[1]) == 1)
		{
			ft_putstr("Error\n");
			return (1);
		}
		dictstr = ft_file_check("en.dict");
		if (dictstr == NULL)
			return (1);
		str = ft_var_dispatch(argv[1], dictstr);
		ft_putstr(str);
		ft_putstr("\n");
	}
	else if (argc == 3)
	{
		if (is_numeric(argv[2]) == 1)
		{
			ft_putstr("Error\n");
			return (1);
		}
		dictstr = ft_file_check(argv[1]);
		if (dictstr == NULL)
			return (1);
		str = ft_var_dispatch(argv[2], dictstr);
		ft_putstr(str);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

char	*ft_file_check(char *dict)
{
	char	*str;
	int		file;
	int		sz;

	str = malloc(BUFFER * sizeof(char));
	file = open(dict, O_RDONLY);
	if (file == -1)
	{
		ft_putstr ("Dict Error\n");
		return (NULL);
	}
	sz = read(file, str, BUFFER);
	if (sz == -1)
	{
		ft_putstr("Dict Error\n");
		close(file);
		return (NULL);
	}
	str[sz] = '\0';
	close(file);
	return (str);
}

char	*ft_var_dispatch(char *strnum, char *dict)
{
	unsigned long long int	number;
	int						thousands;
	int						zeros;
	char					*join;

	number = ft_atoi(strnum);
	thousands = ft_num_size(number);
	zeros = 0;
	join = ft_num_split(strnum, dict, thousands, zeros);
	return (join);
}