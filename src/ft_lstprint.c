/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:32:06 by chris             #+#    #+#             */
/*   Updated: 2023/04/25 19:02:13 by chris            ###   ########.fr       */
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