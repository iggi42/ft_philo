/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:10:02 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/14 20:52:41 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdbool.h>

// 0 is not a valid philo id btw
typedef unsigned char	t_philo_id;
# define NO_PHILO 0

/// argument parings
bool					ft_isdigit(int c);

// check if a cli arg is valid
bool					ft_aisi(char *arg);

// parse a cli arg
int						ft_atoi(char *arg);

// time related things
typedef long			t_timespan;
void					start_timer(void);
t_timespan				read_timer(void);

// if max_meals is -1, the simulation should run endless / till one dies
typedef struct s_philo_conf
{
	size_t				n_phil;
	t_timespan			t2die;
	t_timespan			t2eat;
	t_timespan			t2nap;
	int					max_meals;
}						t_philo_conf;

// run a round
int						run_sim(t_philo_conf *c);

typedef struct s_cond
{
	bool				val;
	pthread_mutex_t		mutex;
}						t_cond;

/// THEIR MOST SACRED CUTLERY
typedef t_cond			t_frk;

// set default values really
bool					init_frk(t_frk *frk);

// ...
bool					pickup(t_frk *frk);
bool					putdown(t_frk *frk);

typedef struct s_philo
{
	t_frk				*left;
	t_frk				*right;
	t_timespan			last_meal;
	t_philo_id			id;
	pthread_t			thread_id;
	t_philo_conf		*c;
}						t_philo;

/// Logging
void					log_animated(t_philo *philo);
void					log_forklift(t_philo *philo);
void					log_eating(t_philo *philo);
void					log_thinking(t_philo *philo);
void					log_died(t_philo *philo);

#endif
