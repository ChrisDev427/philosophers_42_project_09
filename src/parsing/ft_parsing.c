/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:17:07 by chris             #+#    #+#             */
/*   Updated: 2023/05/06 09:05:21 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_strs_is_only_digits(char **s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][0] == '+')
				j++;
			if (s[i][0] == '-')
				return (2);
			if (ft_isdigit(s[i][j]) == 1)
				j++;
			else
				return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_parsing(char **av)
{
	if (av[1] == NULL)
	{
		printf("error: invalid arguments number\n");
		return (-1);
	}
	if (ft_strs_is_only_digits(av) == 1)
	{
		printf("error: numeric arguments is required\n");
		return (-1);
	}
	if (ft_strs_is_only_digits(av) == 2)
	{
		printf("error: negative number is forbidden\n");
		return (-1);
	}
	if (av[1][0] == '0')
	{
		printf("error: it needs to be at least one philosopher\n");
		return (-1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	return (nb);
}
