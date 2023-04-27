/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:47 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/27 19:17:16 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// pthread_mutex_t mutex;

static int  ft_check_eated_times(t_list *tmp)
{
    static int  check;
    if (tmp->eated_times >= tmp->need_to_eat)
        check++;
    if (check >= tmp->tot_philo)
        return (1);
    // printf("philo %d eated %d times\n", tmp->philo, tmp->eated_times);
    
    return (0);
}

static void	*ft_routines(void *arg)
{   
    t_list  *lst = (t_list *)arg;
    // t_philo  *philo = (t_philo *)arg;
    while (1)
    {
        // pthread_mutex_lock(&mutex);
        // printf("*_philo -> %d\n", lst->philo);
        // printf("fork_mutex routine = %p\n", &lst->fork_mutex);
        if (lst->philo % 2 == 0)
            usleep(100000);
        if (lst->fork == 1){
            pthread_mutex_lock(&lst->fork_mutex);
            printf("%lld %d has taken a fork...\n",ft_time_stamp(ft_get_time()), lst->philo);
            lst->fork = 0;
        }
        if (lst->prev->fork == 1){
            printf("%lld %d is eating...\n",ft_time_stamp(ft_get_time()), lst->philo);
            pthread_mutex_lock(&lst->prev->fork_mutex);
            lst->prev->fork = 0;
            usleep(600000);
            lst->fork = 1;
            lst->prev->fork = 1;
            lst->eated_times++;
            pthread_mutex_unlock(&lst->fork_mutex);
            pthread_mutex_unlock(&lst->prev->fork_mutex);

        }
        else if (lst->prev->fork == 0){
            // printf("philo %d fork unavailable\n", lst->prev->philo);
            lst->prev->fork = 1;


        }

        if (ft_check_eated_times(lst) == 1)
            break ;
        usleep(600000);
        // pthread_mutex_unlock(&mutex);
    }

	return (NULL);
}

int main(int ac, char **av)
{
    int i = 0;
    t_philo philo;
    
    // long long time = ft_time_stamp(ft_get_time());
    // printf("time = %lld\n", time);
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
        t_list  *tmp;
        tmp = philo.table_lst;
        // pthread_mutex_init(&mutex, NULL);
        while (i < philo.nb_philo)
        {
            pthread_mutex_init(&tmp->fork_mutex, NULL);
            // printf("fork_mutex init = %p\n", &tmp->fork_mutex);
            pthread_create(&tmp->tid , NULL, &ft_routines, tmp);
            // usleep(1000);

            i++;
            tmp = tmp->next;
        }
        i = 0;
        tmp = philo.table_lst;
        while (i < philo.nb_philo)
        {
            pthread_join(tmp->tid , NULL);
            i++;
            tmp = tmp->next;
        }

	    // printf("EATED -> %d\n", tmp->eated_times);

	   



        ft_lstprint(philo.table_lst);
        // printf("lst size = %d\n", ft_lstsize(philo.table_lst));
        ft_lstdel_all(&philo.table_lst);
       

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