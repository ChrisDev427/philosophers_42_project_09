/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:47 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/25 19:07:30 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_init(t_philo *philo, char **av)
{
    philo->nb_philo = ft_atoi(av[1]);
    philo->die = ft_atoi(av[2]);
    philo->eat = ft_atoi(av[3]);
    philo->sleep = ft_atoi(av[4]);
    philo->eat_times = ft_atoi(av[5]);
    philo->table_lst = NULL;
}

int main(int ac, char **av)
{
    t_philo philo;
    t_list  *new;
    int     i;

    i = 0;
    if (ac == 6)
    {
        ft_parsing(av);
        ft_init(&philo, av);
        while (i != philo.nb_philo)
        {
            i++;
            new = ft_lstnew(i);
            ft_lstadd_back(&philo.table_lst, new);
        }
    

        ft_lstprint(philo.table_lst);
        printf("lst size = %d\n", ft_lstsize(philo.table_lst));
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