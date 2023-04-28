/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:25:29 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/28 18:24:52 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_eating(t_philo  *philo)
{
    printf(GREEN"%ld %d is eating...\n"DEFAULT,ft_elapsed_time(philo->time_start, ft_get_time()), philo->id);
    usleep(philo->data->eat * 1000);
    philo->fork = 1;
    philo->prev->fork = 1;
    philo->eated_times++;
    philo->fork_in_hands = 0;
    pthread_mutex_unlock(&philo->prev->fork_mutex);
    pthread_mutex_unlock(&philo->fork_mutex);
    
}