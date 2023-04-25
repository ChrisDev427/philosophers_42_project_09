/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:47 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/25 10:31:48 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    ac =0;
    av = NULL;

    t_list  *list;
    t_list  *new;

    list = NULL;
    new = ft_lstnew(100);
    ft_lstadd_back(&list, new);
    new = ft_lstnew(200);
    ft_lstadd_back(&list, new);
    new = ft_lstnew(300);
    ft_lstadd_back(&list, new);
    new = ft_lstnew(400);
    ft_lstadd_back(&list, new);
    new = ft_lstnew(500);
    ft_lstadd_back(&list, new);

    
    ft_lstprint(list);
    printf("lst size = %d\n", ft_lstsize(list));
    ft_lstdel_all(&list);
    ft_lstprint(list);
    printf("lst size = %d\n", ft_lstsize(list));




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

    return (0);
}