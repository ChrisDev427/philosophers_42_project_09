/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:39:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/28 18:23:40 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# define RED "\033[3;31m"
# define GREEN "\033[3;32m"
# define YELLOW "\033[3;33m"
# define DEFAULT "\033[0m"



typedef struct  s_data
{
    int             nb_philo;
    int             die;
    int             eat;
    int             sleep;
    int             eat_times;
    pthread_mutex_t mutex;
    
    
}               t_data;

typedef struct  s_philo
{
    int             id;
    int             fork;
    int             fork_in_hands;
    int             go_sleep;
    struct timeval  time_start;
    
    int             eated_times;
    int             need_to_eat;
    
    pthread_t       tid;
    pthread_mutex_t fork_mutex;
    pthread_mutex_t think_mutex;
    pthread_mutex_t sleep_mutex;
   

    struct s_philo   *next;
    struct s_philo   *prev;
    struct s_philo   *table;
    t_data           *data;
}               t_philo;




//****** linked list ************************************************
t_philo	*ft_lstnew(int id, t_philo *ptr);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_lstprint(t_philo *lst);
void	ft_lstdel_all(t_philo **lst);
t_philo	*ft_lstlast(t_philo *lst);
int	    ft_lstsize(t_philo *lst);
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
//****** forks *******************************************************

void    ft_check_my_fork(t_philo  *philo);
void    ft_check_left_fork(t_philo  *philo);

void    ft_is_eating(t_philo  *philo);
void    ft_is_thinking(t_philo  *philo);
void    ft_is_sleeping(t_philo  *philo);

// int ft_strs_is_only_digits(char **s);

#endif
