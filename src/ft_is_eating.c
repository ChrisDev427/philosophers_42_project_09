/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:25:29 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/05 14:10:11 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mic);
	ft_print(ft_elapsed_time(philo->data->start_time, ft_get_time()),
		philo->id, GREEN"is eating"DEFAULT);
	pthread_mutex_unlock(&philo->data->mic);
	pthread_mutex_lock(&philo->data->mutex);
	philo->meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->data->mutex);
	ft_sleep(philo->data->eat * 1000);
	pthread_mutex_lock(&philo->data->mutex);
	philo->fork = 1;
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->mutex);
	philo->prev->fork = 1;
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->mutex);
	philo->eated_times++;
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->mutex);
	philo->fork_in_hands = 0;
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_unlock(&philo->prev->fork_mutex);
	pthread_mutex_unlock(&philo->fork_mutex);
}
