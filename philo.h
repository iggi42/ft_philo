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
# include "frk.h"
# include "time.h"
# include <stdbool.h>
# include <stddef.h>

// 0 is not a valid philo id btw
typedef unsigned char	t_philo_id;
# define NO_PHILO 0

// if max_meals is -1, the simulation should run endless / till one dies
typedef struct s_philo_conf
{
	size_t				n_phil;
	t_timespan			t2die;
	t_timespan			t2eat;
	t_timespan			t2nap;
	int					max_meals;
}						t_philo_conf;

typedef struct s_philo
{
	t_frk				*left;
	t_frk				*right;
	t_timespan			last_meal;
	pthread_mutex_t		last_meal_mutex;
	t_philo_id			id;
	pthread_t			thread_id;
	t_philo_conf		*c;
}						t_philo;

t_philo					*new_philos(t_philo_conf *c, t_frk *cutler);

// run a round
int						run_sim(t_philo_conf *c);

void					log_animated(t_philo *philo);
void					log_forklift(t_philo *philo);
void					log_eating(t_philo *philo);
void					log_thinking(t_philo *philo);
void					log_died(t_philo *philo);

#endif
