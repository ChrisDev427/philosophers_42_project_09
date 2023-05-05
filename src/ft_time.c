/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:27:04 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/05 14:06:09 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_get_time(void)
{
	struct timeval	t;
	time_t			time;

	if (gettimeofday(&t, NULL) != 0)
		printf("Error gettimeofday().\n");
	time = (long)(t.tv_sec) *1000 + (long)(t.tv_usec) / 1000;
	return (time);
}

time_t	ft_elapsed_time(time_t t1, time_t t2)
{
	return (t2 - t1);
}
