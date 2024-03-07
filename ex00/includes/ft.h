/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:59:43 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/02/23 23:59:43 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

#define MAX 20

void	ft_putchar(char c);
void	ft_putstr(char *str);
unsigned long long int  ft_atoi(char *str);
int     ft_strlen(char *str);
int     ft_strlenln(char *str);
char    *ft_split(char *org);
char	*ft_itoa(unsigned long long int num);
char    *ft_get_num_split(char *num, char *dictstr);
char    *ft_get_number_dict_line(char *num, char *dictstr);
int     ft_num_size(unsigned long long int);
char    *ft_strcpy(char *fin, char *org);
char    *ft_strcat(char *fin, char *org);
char    *ft_strjoin(char **strings, int count, char *separator);
char    *ft_split_numbers(char *strnum, char *dictstr, int thousands);
char	*lower_case(char *str);
char    *huge_num(int thousands, char *dictstr);
int     count_dict_line(char *dictstr);
char    *ft_split_dict(char *dictstr);
int     is_numeric(char *str);
char    *ft_strsjoin(char *s1, char *s2, char *sep);

#endif