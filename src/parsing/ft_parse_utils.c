/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:40:57 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/02 19:16:56 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_init(t_philo *philo, char **av, int i)
{
    
    philo->data->nb_philo = ft_atoi(av[i++]);
    philo->data->die = ft_atoi(av[i++]);
    philo->data->eat = ft_atoi(av[i++]);
    philo->data->sleep = ft_atoi(av[i++]);
    philo->data->eat_times = ft_atoi(av[i++]);


     
    philo->table = NULL;  
}

void    ft_split_arg(t_philo *philo, char *s)
{
    char    **ret;

    ret = ft_split(s, ' ');
    if (!ret)
        return ;
    ft_parsing(ret);
    ft_init(philo, ret, 0);
    ft_free_str_tab(ret);
}

void	ft_free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void ft_init_lst(t_philo *philo)
{
    t_philo  *new;
    int     i;

    i = 0;
   

    while (i != philo->data->nb_philo)
    {
        i++;
        new = ft_lstnew(i, philo);
        
        ft_lstadd_back(&philo->table, new);
    }
    // printf("mutex 1 = %p\n", &philo->table_lst->mutex);

}