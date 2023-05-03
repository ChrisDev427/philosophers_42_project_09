/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:37:38 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/03 17:34:22 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_is_thinking(t_philo  *philo)
{
    if (philo->is_thinking == 0 && philo->fork_in_hands == 0)
    {
        pthread_mutex_lock(&philo->data->mic);
        philo->is_thinking = 1;
        printf(YELLOW"%ld   %4d   is thinking...\n"DEFAULT,ft_elapsed_time(philo->data->start_time, ft_get_time()), philo->id);
        pthread_mutex_unlock(&philo->data->mic);
    }
    
    // while (1)
    // {
    //     if (philo->fork_in_hands == 1)
    //     {
    //         pthread_mutex_lock(&philo->think_mutex);
    //         break ;
    //     }
    // }
}