/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:23:31 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/29 09:18:44 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_sleeping(t_philo  *philo)
{
    pthread_mutex_lock(&philo->data->mic);
    printf(BLUE"%ld %d is sleeping...\n"DEFAULT, ft_elapsed_time(philo->time_start, ft_get_time()), philo->id);
    pthread_mutex_unlock(&philo->data->mic);
    usleep(philo->data->sleep * 1000);
}