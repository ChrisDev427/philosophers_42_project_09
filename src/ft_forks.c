/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:09:53 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/28 18:25:04 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_check_my_fork(t_philo  *philo)
{
    if (philo->fork == 1)
    {
        pthread_mutex_lock(&philo->fork_mutex);
        philo->fork = 0;
        philo->fork_in_hands++;
        printf(RED"%ld %d has taken a fork...\n"DEFAULT,ft_elapsed_time(philo->time_start, ft_get_time()), philo->id);
    }
}

void    ft_check_left_fork(t_philo  *philo)
{
    if (philo->prev->fork == 1)
    {
        pthread_mutex_lock(&philo->prev->fork_mutex);
        philo->prev->fork = 0;
        philo->fork_in_hands++;
        printf(RED"%ld %d has taken a fork...\n"DEFAULT,ft_elapsed_time(philo->time_start, ft_get_time()), philo->id);
    }
}