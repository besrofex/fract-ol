/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:37:45 by ylabser           #+#    #+#             */
/*   Updated: 2025/03/01 15:37:46 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	while (r == 0)
	{
		if (!(s1[i] || s2[i]))
			break ;
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (r);
}

void	ft_write(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write(1, str, len);
}

double	ft_atodouble(char *str)
{
	int		i;
	int		signe;
	double	pow;
	double	res;

	i = 0;
	res = 0;
	pow = 1;
	signe = 1;
	if ((str[i] == '-' || str[i] == '+' ))
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (('0' <= str[i] && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
	{
		pow = pow / 10;
		res = res + (str[i] - '0') * pow;
		i++;
	}
	return (res * signe);
}

int	valid_value(char *str)
{
	double	num;
	size_t	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
		i++;
	if (str[i] == '.')
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
		i++;
	if (ft_strlen(str) != i
		|| !ft_strcmp(str, "")
		|| !ft_strcmp(str, "-")
		|| !ft_strcmp(str, "-.")
		|| !ft_strcmp(str, "."))
		return (0);
	num = ft_atodouble(str);
	return (1);
}
