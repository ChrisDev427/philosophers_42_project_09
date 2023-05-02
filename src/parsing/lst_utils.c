/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:40:07 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/29 09:27:24 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int id, t_philo *ptr)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (new == NULL)
		return (NULL);
	new->id = id;
	new->eated_times = 0;
	new->fork = 1;
	new->fork_in_hands = 0;
	new->need_to_eat = ptr->data->eat_times;
	new->is_thinking = 0;
	new->data = ptr->data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;
	t_philo	*first;
	
	if (!(*lst))
	{
		*lst = new;
		tmp = *lst;
		tmp->next = tmp;
		tmp->prev = tmp;
		return ;
	}
	first = *lst;
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
	new->next = first;
	first->prev = new;
}

t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*tmp;
	t_philo	*first;
	
	if (!lst)
		return (NULL);
	tmp = lst;
	first = lst;
	if (tmp->next == first)
		return (tmp);
	while (1)
	{
		if (tmp->next == first)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_lstsize(t_philo *lst)
{
	int		nb_element;
	t_philo	*tmp;
	t_philo	*first;

	if (!lst)
		return (0);
	tmp = lst;
	first = lst;
	nb_element = 0;
	while (1)
	{
		nb_element++;
		if (tmp->next == first)
			break ;
		tmp = tmp->next;
	}
	return (nb_element);
}
void	ft_lstdel_all(t_philo **lst)
{
	t_philo	*tmp;
	t_philo	*first;

	if (!(*lst))
		return ;
	first = *lst;
	while (1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->next == first)
		{
			free(tmp);
			break ;
		}
		free(tmp);
	}
	*lst = NULL;
}


