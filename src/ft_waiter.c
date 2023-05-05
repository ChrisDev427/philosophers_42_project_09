/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:31:25 by chris             #+#    #+#             */
/*   Updated: 2023/05/05 14:01:51 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_meals(t_philo *philo, t_philo *tmp)
{
	static int	check = 0;

	if (philo->data->args == 6)
	{
		pthread_mutex_lock(&philo->data->mutex);
		if (tmp->eated_times > tmp->need_to_eat)
		{
			pthread_mutex_unlock(&philo->data->mutex);
			pthread_mutex_lock(&tmp->data->mutex);
			check++;
			pthread_mutex_unlock(&tmp->data->mutex);
		}
		else
			pthread_mutex_unlock(&philo->data->mutex);
		if (check >= tmp->data->nb_philo)
		{
			pthread_mutex_lock(&philo->data->mic);
			printf(GREEN"%ld every philosophers has eaten at least %d times\n"
				DEFAULT, ft_elapsed_time(philo->data->start_time,
					ft_get_time()), philo->data->eat_times);
			return (-1);
		}
	}
	return (0);
}

int	ft_waiter(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo->data->table;
	while (1)
	{
		pthread_mutex_lock(&philo->data->mutex);
		if (ft_elapsed_time(tmp->meal_time, ft_get_time()) > philo->data->die)
		{
			pthread_mutex_unlock(&philo->data->mutex);
			pthread_mutex_lock(&philo->data->mic);
			ft_print(ft_elapsed_time(philo->data->start_time,
					ft_get_time()), tmp->id, RED"died"DEFAULT);
			return (-1);
		}
		else
			pthread_mutex_unlock(&philo->data->mutex);
		if (philo->data->args == 6)
		{
			if (ft_check_meals(philo, tmp) == -1)
				return (-1);
		}
		tmp = tmp->next;
	}
}
