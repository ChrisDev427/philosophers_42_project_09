/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:47 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/28 18:27:40 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// pthread_mutex_t mutex;

static int  ft_check_eated_times(t_philo *tmp)
{
    static int  check;

    if (tmp->eated_times > tmp->need_to_eat)
        check++;
    // printf("philo %d eated %d times\n", tmp->philo, tmp->eated_times);
    if (check >= tmp->data->nb_philo)
        return (1);
    
    return (0);
}

static void	*ft_routines(void *arg)
{   
    t_philo  *philo = (t_philo *)arg;
    // struct timeval  time_start;

    philo->time_start = ft_get_time();
    while (1)
    {
        // pthread_mutex_lock(&philo->data->mutex);
       printf("---------------------------philo %d\n", philo->id);
        if (philo->id % 2 == 1)
            usleep(50000);

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

        sleep(1);
        if (ft_check_eated_times(philo) == 1)
            break ;
        // pthread_mutex_unlock(&philo->data->mutex);
    }

	return (NULL);
}

int main(int ac, char **av)
{
    int i = 0;
    t_philo philo;
    philo.data = malloc(sizeof(t_data));
    // long long time = ft_time_stamp(ft_get_time());
    // printf("time = %lld\n", time);
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
        // printf("%p\n", &philo.data->mutex);
       
        pthread_mutex_init(&philo.data->mutex , NULL);
        while (i < philo.data->nb_philo)
        {
            pthread_mutex_init(&tmp->fork_mutex, NULL);
            pthread_mutex_init(&tmp->think_mutex, NULL);
            pthread_mutex_init(&tmp->sleep_mutex, NULL);
            // printf("fork_mutex init = %p\n", &tmp->fork_mutex);
            pthread_create(&tmp->tid , NULL, &ft_routines, tmp);
            usleep(1000);

            i++;
            tmp = tmp->next;
        }
        i = 0;
        tmp = philo.table;
        while (i < philo.data->nb_philo)
        {
            pthread_join(tmp->tid , NULL);
            i++;
            tmp = tmp->next;
        }

	    // printf("EATED -> %d\n", tmp->eated_times);

	   



        ft_lstprint(philo.table);
        // // printf("lst size = %d\n", ft_lstsize(philo.table_lst));
        // ft_lstdel_all(&philo.table_lst);
       

    }
    else
        printf("error: five arguments is needed\n");





    // struct timeval t1, t2;
    // long elapsed_time;
   
    // int i = 0;

    // // Mesurer le temps de début d'exécution
    // t1 = ft_get_time();
   
    // // Appeler la fonction dont on veut mesurer le temps d'exécution
    // while (i < 700)
    // {
    //     printf("Blublublublublublublublublublu !!!!!\n");
    //     i++;
    // }


    // // Mesurer le temps de fin d'exécution
    // t2 = ft_get_time();
    

    // // Calculer le temps écoulé en millisecondes
    // elapsed_time = ft_elapsed_time(t1, t2);

    // // Afficher le temps écoulé
    // printf("Temps d'exécution : %ld millisecondes.\n", elapsed_time);
    // system("leaks philo");
    return (0);
}