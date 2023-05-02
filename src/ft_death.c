/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:30:10 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/02 19:22:20 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



static void    ft_death(t_philo *lst)
{
    t_philo *tmp;
    t_philo *first;

    tmp = lst;
    first = tmp;
    while (1)
    {
      
        printf("philo %d\n", tmp->id);
        pthread_detach(tmp->tid);
        // pthread_mutex_destroy(&tmp->fork_mutex);
        if (tmp->next == first)
            break ;
        tmp = tmp->next;
    }
    puts("AAAAA");
    // pthread_mutex_unlock(&philo->data->mic);
    pthread_mutex_destroy(&tmp->data->check_mutex);
    pthread_mutex_destroy(&tmp->data->mic);
}

int ft_check_death(t_philo *philo)
{
    t_philo *tmp;
    t_philo *first;

    tmp = philo;
    first = tmp;
    while (tmp->next != first)
    {
        if (ft_elapsed_time(philo->data->start_time, ft_get_time()) > philo->data->die)
        {
            pthread_mutex_lock(&philo->data->mic);
            printf("%ld philo %d died\n", ft_elapsed_time(philo->data->start_time, ft_get_time()), tmp->id);
            pthread_mutex_unlock(&philo->data->mic);
            // pthread_mutex_unlock(&philo->data->exit);


            ft_death(tmp);
            return (-1);   
        }

        tmp = tmp->next;
    }
    return (0);
    
}