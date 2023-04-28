/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:23:31 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/28 18:24:45 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_sleeping(t_philo  *philo)
{
    pthread_mutex_lock(&philo->sleep_mutex);
    printf(GREEN"%ld %d is sleeping...\n"DEFAULT, ft_elapsed_time(philo->time_start, ft_get_time()), philo->id);
    usleep(philo->data->sleep * 1000);
    pthread_mutex_unlock(&philo->sleep_mutex);
}