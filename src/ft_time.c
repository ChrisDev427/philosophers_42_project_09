/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:27:04 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/27 08:55:31 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long   ft_time_stamp(struct timeval t)
{
   long long time = (long long)(t.tv_sec) * 1000 +
        (long long)(t.tv_usec) / 1000;
    return (time);
}

struct timeval  ft_get_time(void)
{
    struct timeval  time;
    int             ret;

    ret = gettimeofday(&time, NULL);
    if (ret != 0) 
        printf("Error gettimeofday().\n");
    return (time);
}

long    ft_elapsed_time(struct timeval t1, struct timeval t2)
{
    long    time;

    time = (t2.tv_sec - t1.tv_sec) * 1000L + (t2.tv_usec - t1.tv_usec) / 1000L;
    return (time);
}
