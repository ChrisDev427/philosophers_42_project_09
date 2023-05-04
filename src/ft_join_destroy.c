/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:07:29 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/04 16:40:51 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_join_destroy(t_philo *philo)
{
    t_philo *tmp;
    t_philo *first;
    
    tmp = philo->data->table;
    first = philo->data->table;
    pthread_mutex_destroy(&philo->data->check_mutex);
    pthread_mutex_destroy(&philo->data->eated_mutex);
    pthread_mutex_destroy(&philo->data->mutex);
    while (1)
    {
        // pthread_detach(tmp->tid);
        pthread_join(tmp->tid , NULL);
        pthread_mutex_destroy(&tmp->fork_mutex);
        if (tmp->next == first)
            break ;
        tmp = tmp->next;
    }
    pthread_mutex_destroy(&philo->data->mic);
}
