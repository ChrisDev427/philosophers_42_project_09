/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:31:25 by chris             #+#    #+#             */
/*   Updated: 2023/05/04 19:16:27 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  ft_check_meals(t_philo *philo, t_philo *tmp)
{
    static int  check = 0;

    if (philo->data->args == 6)
    {
        pthread_mutex_lock(&philo->data->mutex);

        if (tmp->eated_times > tmp->need_to_eat)
        {
            pthread_mutex_unlock(&philo->data->mutex);
            pthread_mutex_lock(&tmp->data->check_mutex);
            check++;
            pthread_mutex_unlock(&tmp->data->check_mutex);
        }
        else
            pthread_mutex_unlock(&philo->data->mutex);

        if (check >= tmp->data->nb_philo)
        {
            pthread_mutex_lock(&philo->data->mic);
            printf(GREEN"%ld every philosophers has eaten at least %d times\n"DEFAULT, ft_elapsed_time(philo->data->start_time, ft_get_time()), philo->data->eat_times);
            // ft_print(ft_elapsed_time(philo->data->start_time, ft_get_time()), ((int)void *), GREEN"every philosophers has eaten enough times"DEFAULT);

            ft_join_destroy(philo);
            // ft_lstdel_all(&philo->data->table);
            return (-1);
        }
    }
    return (0);
}

int   ft_waiter(t_philo *philo)
{
    t_philo *tmp;

    tmp = philo->data->table;
    while (1)
    {
        pthread_mutex_lock(&philo->data->mutex);
        if (ft_elapsed_time(tmp->meal_time, ft_get_time()) > philo->data->die)
        {
            pthread_mutex_unlock(&philo->data->mutex);
            pthread_mutex_lock(&philo->data->mic);
            // printf(RED"%ld %d died\n"DEFAULT, ft_elapsed_time(tmp->data->start_time, ft_get_time()), tmp->id);
            ft_print(ft_elapsed_time(philo->data->start_time, ft_get_time()), tmp->id, RED"died"DEFAULT);

            ft_join_destroy(philo);
            return (-1);
        }
        else
            pthread_mutex_unlock(&philo->data->mutex);

        if (philo->data->args == 6)
        {
            if (ft_check_meals(philo, tmp) == -1)
                return (-1);
        }
        tmp = tmp->next;
        // pthread_mutex_unlock(&philo->data->mic);
    }
}
