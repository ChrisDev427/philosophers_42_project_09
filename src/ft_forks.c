/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:09:53 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/03 17:39:02 by chris            ###   ########.fr       */
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
        philo->is_thinking = 0;
        pthread_mutex_lock(&philo->data->mic);
        printf(NBLUE"%ld   %4d   has taken a fork...\n"DEFAULT,ft_elapsed_time(philo->data->start_time, ft_get_time()), philo->id);
        pthread_mutex_unlock(&philo->data->mic);

    }
}

void    ft_check_left_fork(t_philo  *philo)
{
    if (philo->prev->fork == 1)
    {
        pthread_mutex_lock(&philo->prev->fork_mutex);
        philo->prev->fork = 0;
        philo->fork_in_hands++;
        pthread_mutex_lock(&philo->data->mic);
        printf(NBLUE"%ld   %4d   has taken a fork...\n"DEFAULT,ft_elapsed_time(philo->data->start_time, ft_get_time()), philo->id);
        pthread_mutex_unlock(&philo->data->mic);

    }
}