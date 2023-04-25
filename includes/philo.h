/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:39:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/25 10:39:23 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct  s_list
{
    unsigned int    data;
    struct s_list   *first;
    struct s_list   *next;
    struct s_list   *prev;
}               t_list;



int	            ft_atoi(const char *str);
long            ft_elapsed_time(struct timeval t1, struct timeval t2);
struct timeval  ft_get_time(void);

t_list	*ft_lstnew(unsigned int data);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstprint(t_list *lst);
void	ft_lstdel_all(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

#endif
