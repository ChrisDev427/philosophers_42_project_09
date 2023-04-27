/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:39:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/27 19:06:09 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>


typedef struct  s_list
{
    int             philo;
    int             tot_philo;
    pthread_t       tid;
    int             fork;
    int             need_to_eat;
    int             eated_times;
    pthread_mutex_t fork_mutex;
    struct s_list   *next;
    struct s_list   *prev;
}               t_list;

typedef struct  s_philo
{
    int             nb_philo;
    int             die;
    int             eat;
    int             sleep;
    int             eat_times;
    pthread_mutex_t mutex;
    t_list          *table_lst;
}               t_philo;



//****** linked list ************************************************
t_list	*ft_lstnew(int philo, int tot_philo, int need_to_eat);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstprint(t_list *lst);
void	ft_lstdel_all(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int	    ft_lstsize(t_list *lst);
void    ft_init_lst(t_philo *philo);

//****** parsing ****************************************************

void    ft_parsing(char **av);
int	    ft_atoi(const char *str);
void    ft_split_arg(t_philo *philo, char *s);
char	**ft_split(char const *s, char c);
void    ft_init(t_philo *philo, char **av, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	ft_free_str_tab(char **tab);

//****** pthread functions ******************************************




//****** time *******************************************************

struct timeval  ft_get_time(void);
long long       ft_time_stamp(struct timeval t);

long            ft_elapsed_time(struct timeval t1, struct timeval t2);


// int ft_strs_is_only_digits(char **s);

#endif
