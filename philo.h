/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:10:02 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/13 07:28:14 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <pthread.h>

// if max_meals is -1, the simulation should run endless / till one dies
typedef struct s_philo_conf
{
	size_t n_phil;
	size_t t2die;
	size_t t2eat;
	size_t t2nap;
	int max_meals;
}	t_philo_conf;

// 0 is not a valid philo id btw
typedef unsigned char t_philo_id;
#define NO_PHILO 0

/// argument parings
bool	ft_isdigit(int c);

// check if a cli arg is valid
bool	ft_aisi(char *arg);

// parse a cli arg
int		ft_atoi(char *arg);

// run a round
int		run_sim(t_philo_conf *c);

/// THEIR MOST SACRED CUTLERY
typedef struct s_frk
{
	bool	in_use;
	pthread_mutex_t	mutex;
} t_frk;

// set default values really
bool	init_frk(t_frk *frk);

// ...
bool	pickup(t_frk *frk);
bool	putdown(t_frk *frk);

/// the PHILOS themselves
// spawn an philosopher
//int		spawn_philo(t_philo_id id, t_frk *left, t_frk *right);
typedef struct s_philo {
	t_frk	*left;
	t_frk	*right;
	t_philo_id	id;
}	t_philo;

/// Logging
void log_forklift(t_philo *philo);
void log_eating(t_philo *philo);
void log_thinking(t_philo *philo);
void log_died(t_philo *philo);

#endif
