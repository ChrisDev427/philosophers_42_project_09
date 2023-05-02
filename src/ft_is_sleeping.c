/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:23:31 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/02 14:06:23 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_sleeping(t_philo  *philo)
{
    pthread_mutex_lock(&philo->data->mic);
    printf(BLUE"%ld %d is sleeping...\n"DEFAULT, ft_elapsed_time(philo->data->start_time, ft_get_time()), philo->id);
    pthread_mutex_unlock(&philo->data->mic);
    ft_sleep(philo->data->sleep * 1000);
}