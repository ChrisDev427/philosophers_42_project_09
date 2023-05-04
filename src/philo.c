/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:42 by chris             #+#    #+#             */
/*   Updated: 2023/05/04 18:16:30 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_mutex_init(t_philo *philo)
{
    pthread_mutex_init(&philo->data->mic , NULL);
    pthread_mutex_init(&philo->data->check_mutex , NULL);
    pthread_mutex_init(&philo->data->eated_mutex , NULL);
    pthread_mutex_init(&philo->data->mutex , NULL);
}

static void	*ft_routines(void *arg)
{   
    t_philo  *philo = (t_philo *)arg;
    
    if (philo->id % 2 != 0)
        ft_sleep(20000);
    while (1)
    {
        ft_check_my_fork(philo);
        ft_check_left_fork(philo);
        if (philo->fork_in_hands == 2)
        {
            ft_is_eating(philo);
            ft_is_sleeping(philo);
            ft_is_thinking(philo);
        }
        else
        {
            ft_is_thinking(philo);
        }
    }
	return (NULL);
}
static void ft_threads_create(t_philo *philo)
{
    int      i;
    t_philo  *tmp;

    i = 0;
    tmp = philo->data->table;

    while (i < philo->data->nb_philo)
    {
        pthread_mutex_init(&philo->fork_mutex, NULL);
        pthread_create(&philo->tid , NULL, &ft_routines, tmp);
        i++;
        tmp = tmp->next;
    }
}

int main(int ac, char **av)
{
    t_philo philo;
   
    philo.data = malloc(sizeof(t_data));
    philo.data->args = ac;
    if (ac == 2 || ac == 5 || ac == 6)
    {
        if (ac == 2)
            ft_split_arg(&philo, av[1]);
        else
        {
            ft_parsing(av);
            ft_init(&philo, av, 1);
        }       
        ft_init_lst(&philo);
        ft_mutex_init(&philo);
        philo.data->start_time = ft_get_time();
        ft_threads_create(&philo);
        ft_waiter(&philo);
    }
    else
        printf("error: invalid arguments\n");
    // system("leaks philo");
    return (0);
}
