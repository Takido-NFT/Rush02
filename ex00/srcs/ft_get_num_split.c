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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft.h"

#define BUFFER 1000
#define MAX 20

int ft_num_size(unsigned long long int number)
{
    int size;

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

char    *ft_get_num_split(char *strnum, char *dictstr)
{
	unsigned long long int	number;
	char					*join;
	int						chunk;
	char					*temp;
	char					*chunk_str;
	char					*huge_num_str;
	int						thousands;
	int						zeros;

    number = ft_atoi(strnum);
    if (number == 0)
		return ("zero");
	join = NULL;
	thousands = ft_num_size(number);
	zeros = 0;
	while (number > 0)
	{
		chunk = number % 1000;
		number /= 1000;
		if (chunk > 0)
		{
			chunk_str = ft_split_numbers(ft_itoa(chunk), dictstr);
			if (join == NULL)
			{
				join = chunk_str;
			}
			else
			{
				huge_num_str = huge_num(thousands, dictstr);
				temp = ft_strsjoin(lower_case(huge_num_str), join, " ");
				free(join);
				free(huge_num_str);
				join = ft_strsjoin(chunk_str, temp, " ");
				free(temp);
				free(chunk_str);
				thousands++;
			}
		}
		else
			zeros++;
	}
	if (zeros > 0)
	{
		ft_strcat(join, " ");
		ft_strcat(join, lower_case(huge_num(zeros, dictstr)));
		zeros = 0;
	}
	return (join);
}

char    *ft_get_number_dict_line(char *num, char *dictstr)
{
    int i;
    int j;
    int size;
    char *ret;

    i = 0;
    j = 0;
    size = ft_strlen(num);
    ret = (char *)malloc(BUFFER * sizeof(char));
	if (ret == NULL)
		return (NULL);
    while (dictstr[i] != '\0')
    {
        if (size == 2 && ((num[0] == dictstr[i]) && (num[1] == dictstr[i + 1])))
        {
            while(dictstr[i] != '\n')
				ret[j++] = dictstr[i++];
			ret[j] = '\0';
    		return (ret);
        }
        if (size == 1 && (num[0] == dictstr[i]))
        {
            while(dictstr[i] != '\n')
				ret[j++] = dictstr[i++];
			ret[j] = '\0';
    		return (ret);
        }
        i++;
    }
    return (ret);
}

char *ft_split_numbers(char *strnum, char *dictstr)
{
	int size;
	int temp;
	char numalt[MAX];
    char *join;

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
		join = lower_case(ft_get_number_dict_line(numalt, dictstr));
	}
	else if (size == 2)
	{
        if (ft_atoi(strnum) > 20)
        {
            numalt[0] = strnum[0];
            numalt[1] = '0';
            numalt[2] = '\0';
            join = lower_case(ft_get_number_dict_line(numalt, dictstr));
			if (strnum[1] != '0')
			{
				numalt[0] = strnum[1];
            	numalt[1] = '\0';
            	ft_strcat(join, " ");
            	ft_strcat(join, lower_case(ft_get_number_dict_line(numalt, dictstr)));
			}
        }
        else if (ft_atoi(strnum) <= 20)
		{
			numalt[0] = strnum[0];
			numalt[1] = strnum[1];
			numalt[2] = '\0';
			join = lower_case(ft_get_number_dict_line(numalt, dictstr));
		}
	}
    else if (size == 3)
	{
        numalt[0] = strnum[0];
        numalt[1] = '\0';
        join = lower_case(ft_get_number_dict_line(numalt, dictstr));
		ft_strcat(join, " hundred");
        numalt[0] = strnum[1];
        numalt[1] = strnum[2];
        numalt[2] = '\0';
        if (ft_atoi(numalt) > 20)
        {
            numalt[0] = strnum[1];
            numalt[1] = '0';
            numalt[2] = '\0';
            ft_strcat(join, " ");
            ft_strcat(join, lower_case(ft_get_number_dict_line(numalt, dictstr)));
		    numalt[0] = strnum[2];
            numalt[1] = '\0';
            ft_strcat(join, " ");
            ft_strcat(join, lower_case(ft_get_number_dict_line(numalt, dictstr)));
        }
        else if (ft_atoi(numalt) > 0)
        {
			if (ft_atoi(numalt) <= 20)
			{
				numalt[0] = strnum[0];
				numalt[1] = strnum[1];
				numalt[2] = '\0';
			}
            ft_strcat(join, " ");
            ft_strcat(join, lower_case(ft_get_number_dict_line(numalt, dictstr)));
        }
	}
    return (join);
}

char    *huge_num(int thousands, char *dictstr)
{
    int i;
	int j;
	int new_line;
    char *strnum;

	i = 0;
	j = 0;
	new_line = 1;
    strnum = (char *)malloc((MAX + thousands * 3 + 1) * sizeof(char));
	if (strnum == NULL)
		return (NULL);
	dictstr = ft_split_dict(dictstr);
	if (thousands > 12)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	while (new_line < thousands && dictstr[i] != '\0')
	{
		if (dictstr[i] == '\n')
			new_line++;
		i++;
	}
	while(dictstr[i] != '\n' && dictstr[i] != '\0')
    {
        strnum[j] = dictstr[i];
        j++;
        i++;
    }
    strnum[j] = '\0';
	return (strnum);
}

int main(int argc, char *argv[])
{
    char *num = argv[1];
    char dict[BUFFER];
    int		file;
	int		sz;

    if (argc > 1 && is_numeric(num) == 0)
    {
        file = open("en.dict", O_RDONLY);
	    if (file == -1)
	    {
		    ft_putstr ("Can't open the file.\n");
		    return (1);
	    }
	    sz = read(file, dict, BUFFER);
	    if (sz == -1)
	    {
		    ft_putstr("Can't read the file.\n");
		    close(file);
		    return (1);
	    }
	    dict[sz] = '\0';
	    close(file);
        char *str = ft_get_num_split(num, dict);
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
