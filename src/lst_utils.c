/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:40:07 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/25 10:35:44 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstnew(unsigned int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	t_list	*first;
	
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

void	ft_lstdel_all(t_list **lst)
{
	t_list	*tmp;
	t_list	*first;

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
		printf("%d\n", tmp->data);
		return ;
	}
	while (1)
	{
		printf("%d\n", tmp->data);
		if (tmp->next == first)
			break ;
		tmp = tmp->next;
	}
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	t_list	*first;
	
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

int	ft_lstsize(t_list *lst)
{
	int		nb_element;
	t_list	*tmp;
	t_list	*first;

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

