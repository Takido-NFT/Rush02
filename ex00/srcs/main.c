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
#include "../includes/ft.h"

#define BUFFER 1000

int	ft_file_check(char *argv1, char *argv2);

int	main(int argc, char *argv[])
{
	char *str;
	if (argc == 2)
	{
		if (ft_atoi(argv[1]) < 0)
		{
			ft_putstr("Error\n");
			return (1);
		}
		printf ("%d\n", ft_atoi(argv[1])); //only for test reasons
	}
	else if (argc == 3)
	{
		if (ft_atoi(argv[2]) < 0)
		{
			ft_putstr("Error\n");
			return (1);
		}
		if (ft_file_check(argv[1], argv[2]) == 1)
			return (1);
		str = ft_get_num_split(argv[2], argv[1]);
	}
	return (0);
}

int	ft_file_check(char *argv1, char *argv2)
{
	char	str[BUFFER];
	int		file;
	int		sz;

	file = open(argv1, O_RDONLY);
	if (file == -1)
	{
		ft_putstr ("Can't open the file.\n");
		return (1);
	}
	sz = read(file, str, BUFFER);
	if (sz == -1)
	{
		ft_putstr("Can't read the file.\n");
		close(file);
		return (1);
	}
	str[sz] = '\0';
	ft_putstr(str);
	close(file);
	return (0);
}
