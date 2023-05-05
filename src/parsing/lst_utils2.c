/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:19:00 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/05 14:13:36 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstprint(t_philo *lst)
{
	t_philo	*tmp;
	t_philo	*first;

	if (!lst)
	{
		printf("Empty list\n");
		return ;
	}
	tmp = lst;
	first = lst;
	if (tmp->next == tmp)
	{
		printf("%d\n", tmp->id);
		return ;
	}
	while (1)
	{
		printf("philo       [%d]\n", tmp->id);
		printf("philo       [%p]\n", &tmp->id);
		printf("fork        [%d]\n", tmp->fork);
		if (tmp->next == first)
			break ;
		tmp = tmp->next;
	}
}
