/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:07:29 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/05 14:08:36 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_destroy(t_philo *philo)
{
	t_philo	*tmp;
	t_philo	*first;

	tmp = philo->data->table;
	first = philo->data->table;
	while (1)
	{
		pthread_join(tmp->tid, NULL);
		if (tmp->next == first)
			break ;
		tmp = tmp->next;
	}
}
