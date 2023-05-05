/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:09:53 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/05 14:11:38 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_my_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->fork == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		pthread_mutex_lock(&philo->fork_mutex);
		pthread_mutex_lock(&philo->data->mutex);
		philo->fork = 0;
		philo->fork_in_hands++;
		philo->is_thinking = 0;
		pthread_mutex_unlock(&philo->data->mutex);
		pthread_mutex_lock(&philo->data->mic);
		ft_print(ft_elapsed_time(philo->data->start_time, ft_get_time()),
			philo->id, NBLUE"has taken a fork"DEFAULT);
		pthread_mutex_unlock(&philo->data->mic);
	}
	else
		pthread_mutex_unlock(&philo->data->mutex);
}

void	ft_check_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->prev->fork == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		pthread_mutex_lock(&philo->data->mutex);
		philo->prev->fork = 0;
		pthread_mutex_unlock(&philo->data->mutex);
		pthread_mutex_lock(&philo->data->mutex);
		philo->fork_in_hands++;
		pthread_mutex_unlock(&philo->data->mutex);
		pthread_mutex_lock(&philo->data->mic);
		ft_print(ft_elapsed_time(philo->data->start_time, ft_get_time()),
			philo->id, NBLUE"has taken a fork"DEFAULT);
		pthread_mutex_unlock(&philo->data->mic);
	}
	else
		pthread_mutex_unlock(&philo->data->mutex);
}
