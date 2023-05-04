/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:39:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/04 15:48:08 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "philo.h"

typedef struct  s_data
{
    int             nb_philo;
    int             die;
    int             eat;
    int             sleep;
    int             eat_times;
    int             args;
    time_t          start_time;
    time_t          act_time;
    struct s_philo  *table;
    pthread_mutex_t mic;
    pthread_mutex_t eated_mutex;
    pthread_mutex_t check_mutex;   
    pthread_mutex_t mutex;   
}               t_data;

typedef struct  s_philo
{
    int             id;
    int             fork;
    int             fork_in_hands;
    int             is_thinking;
    int             eated_times;
    int             need_to_eat;
    time_t          meal_time;
    
    pthread_t       tid;
    pthread_mutex_t fork_mutex;
   
    struct s_philo   *next;
    struct s_philo   *prev;
    t_data           *data;
}               t_philo;
#endif
