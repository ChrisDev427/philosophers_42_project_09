/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:01:35 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/04 17:52:30 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_sleep(time_t sleep)
{
    struct timeval start_time; 
    struct timeval actual_time;
    time_t  time;

    time = 0;
    if (gettimeofday(&start_time, NULL) != 0)
    {
        printf("Error gettimeofday().\n");
        return ;
    }
    while (time < sleep)
    {
        usleep(50);
        if (gettimeofday(&actual_time, NULL) != 0)
        {
            printf("Error gettimeofday().\n");
            return ;
        }
        time = (actual_time.tv_sec - start_time.tv_sec) * 1000000
            + (actual_time.tv_usec - start_time.tv_usec);
    }
}
