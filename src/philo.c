/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:47 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/26 10:17:24 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_init_lst(t_philo *philo)
{
    t_list  *new;
    int     i;

    i = 0;
    while (i != philo->nb_philo)
    {
        i++;
        new = ft_lstnew(i);
        ft_lstadd_back(&philo->table_lst, new);
    }
}

int main(int ac, char **av)
{
    t_philo philo;
    // t_list  *new;
    // int     i;

    // i = 0;
    if (ac == 2 || ac == 6)
    {
        if (ac == 2)
            ft_split_arg(&philo, av[1]);
        else
        {
            ft_parsing(av);
            ft_init(&philo, av, 1);
        }
        ft_init_lst(&philo);
        
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