/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:42 by chris             #+#    #+#             */
/*   Updated: 2023/05/06 09:17:04 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_routines(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
	{
		ft_is_thinking(philo);
		ft_sleep(10000);
	}
	while (1)
	{
		ft_check_my_fork(philo);
		ft_check_left_fork(philo);
		if (philo->fork_in_hands == 2)
		{
			ft_is_eating(philo);
			ft_is_sleeping(philo);
			ft_is_thinking(philo);
		}
		else
			ft_is_thinking(philo);
	}
	return (NULL);
}

static void	ft_threads_create(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = philo->data->table;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_init(&philo->fork_mutex, NULL);
		pthread_create(&philo->tid, NULL, &ft_routines, tmp);
		i++;
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_philo	philo;

	philo.data = malloc(sizeof(t_data));
	philo.data->args = ac;
	if (ac == 2 || ac == 5 || ac == 6)
	{
		if (ac == 2)
			if (ft_split_arg(&philo, av[1]) == -1)
				return (0);
		if (ac == 5 || ac == 6)
		{
			if(ft_parsing(av) == -1)
				return (0);
			ft_init(&philo, av, 1);
		}
		ft_init_lst(&philo);
		philo.data->start_time = ft_get_time();
		ft_threads_create(&philo);
		if (ft_waiter(&philo) == -1)
			return (0);
	}
	else
		printf("error: invalid arguments\n");
	return (0);
}
