/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:19:00 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/26 10:19:08 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*tmp;
	t_list	*first;

	if (!lst)
	{
		printf("Empty list\n");
		return ;
	}
	tmp = lst;
	first = lst;
	if (tmp->next == tmp)
	{
		
		printf("%d\n", tmp->philo);
		return ;
	}
	while (1)
	{
		
		printf("%d\n", tmp->philo);
		if (tmp->next == first)
			break ;
		tmp = tmp->next;
	}
}