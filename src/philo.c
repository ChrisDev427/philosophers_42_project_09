/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:47 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/02 19:31:55 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// pthread_mutex_t mutex;

// static int  ft_check_eated_times(t_philo *tmp)
// {
//     static int  check = 0;

//     if (tmp->eated_times > tmp->need_to_eat)
//     {
//         pthread_mutex_lock(&tmp->data->check_mutex);
//         check++;
//         pthread_mutex_unlock(&tmp->data->check_mutex);

//     }
//     // printf("philo %d eated %d times\n", tmp->philo, tmp->eated_times);
//     if (check >= tmp->data->nb_philo)
//         return (1);
    
//     return (0);
// }

static void	*ft_routines(void *arg)
{   
    t_philo  *philo = (t_philo *)arg;
    
    if (philo->id % 2 == 1)
        ft_sleep(5000);
    while (1)
    {
    
        ft_check_my_fork(philo);
        ft_check_left_fork(philo);
        if (philo->fork_in_hands == 2)
        {
            ft_is_eating(philo);
            ft_is_sleeping(philo);
        }
        else{
            ft_is_thinking(philo);
        }
        // if (ft_check_eated_times(philo) == 1)
        // {
        //     puts("eated enough");
        //     break ;
        // }
        // if (ft_check_death(philo) == -1)
        //     break ;
    }
	return (NULL);
}

int main(int ac, char **av)
{
    int i;
    t_philo philo;

    i = 0;
    philo.data = malloc(sizeof(t_data));
    if (ac == 2 || ac == 5 || ac == 6)
    {
        if (ac == 2)
        {
            ft_split_arg(&philo, av[1]);
        }
        else
        {
            ft_parsing(av);
            ft_init(&philo, av, 1);
        }       
        ft_init_lst(&philo);
        // ft_lstprint(philo.table);
        t_philo  *tmp;
        tmp = philo.table;
        pthread_mutex_init(&philo.data->mic , NULL);
        pthread_mutex_init(&philo.data->check_mutex , NULL);
        philo.data->start_time = ft_get_time();
        while (i < philo.data->nb_philo)
        {
            pthread_mutex_init(&tmp->fork_mutex, NULL);
            pthread_create(&tmp->tid , NULL, &ft_routines, tmp);
            i++;
            tmp = tmp->next;
        }
        puts("AAAA");
        
        



        ft_join_destroy(&philo);
       

        // ft_lstprint(philo.table);
        // // printf("lst size = %d\n", ft_lstsize(philo.table_lst));
        // ft_lstdel_all(&philo.table);
    }
    else
        printf("error: five arguments is needed\n");
    return (0);
}