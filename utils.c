/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroman-p <lroman-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:54 by lroman-p          #+#    #+#             */
/*   Updated: 2024/09/28 13:33:59 by lroman-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iferror(bool iferror, char *str)
{
	if (iferror)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

int	ft_strncmp(const char *str1, char *str2, int size)
{
	int	i;

	if (str1 == NULL || str2 == NULL || size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		sign;
	int		i;
	int		nbr;

	sign = 1;
	nbr = 0;
	i = 0;
	if ((str[i] >= 9 && str[i] <= 13) || str [i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

static	void	ft_putstr(char *str)
{
	int		i;

	if (!str)
		return ;
	if (*str != '\0')
	{
		i = write(1, str, 1);
		(void) i;
		ft_putstr(str + 1);
	}
}

void	perror_exit(void)
{
	ft_putstr(MSG_ERROR);
	exit(EXIT_FAILURE);
}
