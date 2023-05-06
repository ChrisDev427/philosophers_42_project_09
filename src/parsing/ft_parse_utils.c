/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:40:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/06 09:11:03 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_philo *philo, char **av, int i)
{
	philo->data->nb_philo = ft_atoi(av[i++]);
	philo->data->die = ft_atoi(av[i++]);
	philo->data->eat = ft_atoi(av[i++]);
	philo->data->sleep = ft_atoi(av[i++]);
	if (philo->data->args == 6)
		philo->data->eat_times = ft_atoi(av[i++]);
	philo->data->table = NULL;
	pthread_mutex_init(&philo->data->mic, NULL);
	pthread_mutex_init(&philo->data->mutex, NULL);
}

int	ft_split_arg(t_philo *philo, char *s)
{
	char	**ret;

	ret = ft_split(s, ' ');
	if (!ret)
		return (-1);
	if (ft_parsing(ret) == -1)
		return (-1);
	ft_init(philo, ret, 0);
	ft_free_str_tab(ret);
	return (0);
}

void	ft_free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_init_lst(t_philo *philo)
{
	t_philo	*new;
	int		i;

	i = 0;
	while (i != philo->data->nb_philo)
	{
		i++;
		new = ft_lstnew(i, philo);
		ft_lstadd_back(&philo->data->table, new);
	}
}
