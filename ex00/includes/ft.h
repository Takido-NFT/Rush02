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

void				ft_putstr(char *str);
unsigned long long	ft_atoi(char *str);
char				*ft_itoa(unsigned long long num);
int					ft_strlen(char *str);
char				*ft_num_split(char *strnum, char *dict, int thousands, \
						int zeros);
char				*ft_zeros(int zeros, char *join, char *dict);
char				*ft_line(int i, char *dictstr, char *ret);
char				*ft_dict_line(char *num, char *dictstr);
int					ft_num_size(unsigned long long number);
char				*ft_strcpy(char *fin, char *org);
char				*ft_strcat(char *fin, char *org);
char				*ft_split_numbers(char *strnum, char *dictstr);
char				*ft_low(char *str);
char				*huge_num(int thousands, char *dictstr, int org_thousands);
int					ft_is_numeric(char *str);
char				*ft_strjoin(char *s1, char *s2, char *sep);
char				*ft_split_dict(char *dictstr);

#endif