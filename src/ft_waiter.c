/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:31:25 by chris             #+#    #+#             */
/*   Updated: 2023/05/03 18:39:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int   ft_waiter(t_philo *philo)
{
    t_philo *tmp;
    static int  check = 0;

    tmp = philo->data->table;
    while (1)
    {
        if (ft_elapsed_time(tmp->meal_time, ft_get_time()) > philo->data->die)
        {
            pthread_mutex_lock(&philo->data->mic);
            printf(RED"%1ld   %2d   died\n"DEFAULT, ft_elapsed_time(tmp->data->start_time, ft_get_time()), tmp->id);
            ft_lstdel_all(&philo->data->table);
            return (-1);
        }
        if (philo->data->args == 6)
        {
            if (tmp->eated_times > tmp->need_to_eat)
            {
                pthread_mutex_lock(&tmp->data->check_mutex);
                check++;
                pthread_mutex_unlock(&tmp->data->check_mutex);
            }
            if (check >= tmp->data->nb_philo)
            {
                pthread_mutex_lock(&philo->data->mic);
                printf(GREEN"%1ld   every philosophers has eaten at least %d times...\n"DEFAULT, ft_elapsed_time(philo->data->start_time, ft_get_time()), philo->data->eat_times);
                ft_lstdel_all(&philo->data->table);
                return (-1);
            }
        }
        tmp = tmp->next;
    }
}