/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:37:38 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/05 13:56:19 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_thinking(t_philo *philo)
{
	if (philo->is_thinking == 0 && philo->fork_in_hands == 0)
	{
		pthread_mutex_lock(&philo->data->mic);
		ft_print(ft_elapsed_time(philo->data->start_time, ft_get_time()),
			philo->id, YELLOW"is thinking"DEFAULT);
		philo->is_thinking = 1;
		pthread_mutex_unlock(&philo->data->mic);
	}
}
