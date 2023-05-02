/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:07:29 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/02 19:33:43 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_join_destroy(t_philo *philo)
{
    t_philo *tmp;
    t_philo *first;

    tmp = philo->table;
    first = philo->table;
    while (1)
    {
        pthread_join(tmp->tid , NULL);
        // pthread_mutex_destroy(&tmp->fork_mutex);
        if (tmp->next == first)
            break ;
        tmp = tmp->next;
    }
//     pthread_mutex_destroy(&philo->data->check_mutex);
//     pthread_mutex_destroy(&philo->data->mic);
}
