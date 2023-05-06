/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:39:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/05/06 09:11:49 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include "structs.h"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;36m"
# define NBLUE "\033[1;34m"
# define DEFAULT "\033[0m"

//****** linked list ************************************************
t_philo	*ft_lstnew(int id, t_philo *ptr);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_lstprint(t_philo *lst);
void	ft_lstdel_all(t_philo **lst);
t_philo	*ft_lstlast(t_philo *lst);
int		ft_lstsize(t_philo *lst);
void	ft_init_lst(t_philo *philo);
//****** parsing ****************************************************
int     ft_parsing(char **av);
int		ft_atoi(const char *str);
int	    ft_split_arg(t_philo *philo, char *s);
char	**ft_split(char const *s, char c);
void	ft_init(t_philo *philo, char **av, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	ft_free_str_tab(char **tab);
//****** pthread functions ******************************************
void	ft_join_destroy(t_philo *philo);
//****** time *******************************************************
time_t	ft_get_time(void);
time_t	ft_elapsed_time(time_t t1, time_t t2);
void	ft_sleep(time_t sleep);
int		ft_check_death(t_philo *philo);
int		ft_waiter(t_philo *philo);
//****** forks *******************************************************
void	ft_check_my_fork(t_philo *philo);
void	ft_check_left_fork(t_philo *philo);
//****** routines ****************************************************
void	ft_is_eating(t_philo *philo);
void	ft_is_thinking(t_philo *philo);
void	ft_is_sleeping(t_philo *philo);
void	ft_print(time_t time, int philo, char *s);
#endif
