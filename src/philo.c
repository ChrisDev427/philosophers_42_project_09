/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:42 by chris             #+#    #+#             */
/*   Updated: 2023/05/03 18:46:30 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_mutex_init(t_philo *philo)
{
    pthread_mutex_init(&philo->data->mic , NULL);
    pthread_mutex_init(&philo->data->check_mutex , NULL);
    pthread_mutex_init(&philo->data->eated_mutex , NULL);
}

static void	*ft_routines(void *arg)
{   
    t_philo  *philo = (t_philo *)arg;
    
    if (philo->id % 2 == 0)
        ft_sleep(22000);
    while (1)
    {
        ft_check_my_fork(philo);
        ft_check_left_fork(philo);
        if (philo->fork_in_hands == 2)
        {
            ft_is_eating(philo);
            ft_is_sleeping(philo);
        }
        else
            ft_is_thinking(philo);
    }
	return (NULL);
}

int main(int ac, char **av)
{
    int i;
    t_philo philo;
    t_philo  *tmp;

    i = 0;
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
        tmp = philo.data->table;
        ft_mutex_init(&philo);
        philo.data->start_time = ft_get_time();
        while (i < philo.data->nb_philo)
        {
            pthread_mutex_init(&tmp->fork_mutex, NULL);
            pthread_create(&tmp->tid , NULL, &ft_routines, tmp);
            i++;
            tmp = tmp->next;
        }
        if (ft_waiter(&philo) == -1)
            return (0);
        
        // ft_join_destroy(&philo);
        // ft_lstprint(philo.table);
        // // printf("lst size = %d\n", ft_lstsize(philo.table_lst));
        // ft_lstdel_all(&philo.data->table);
    }
    else
        printf("error: five arguments is needed\n");
    return (0);
}
