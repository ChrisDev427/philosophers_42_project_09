/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:37:38 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/28 18:24:38 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_thinking(t_philo  *philo)
{
    // pthread_mutex_lock(&philo->think_mutex);
    if (philo->fork_in_hands == 0)
    printf(YELLOW"%ld %d is thinking...\n"DEFAULT,ft_elapsed_time(philo->time_start, ft_get_time()), philo->id);
    // while (1)
    // {
    //     if (philo->fork_in_hands == 1)
    //     {
    //         pthread_mutex_lock(&philo->think_mutex);
    //         break ;
    //     }
    // }
}