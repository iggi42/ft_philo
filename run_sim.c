/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 03:39:12 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/14 20:51:11 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frk.h"
#include "philo.h"
#include "utils.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_frk	*bring_the_cutlery(size_t n)
{
	t_frk	*frks;
	size_t	i;

	frks = ft_calloc(n, sizeof(t_frk));
	i = 0;
	while (i < n)
		init_frk(&frks[i++]);
	return (frks);
}

void	philo_routine_eating(t_philo *me)
{
	t_frk	*fs[2];
	bool	has_eaten;

	has_eaten = false;
	fs[me->id % 2] = me->right;
	fs[(me->id + 1) % 2] = me->left;
	while (true)
	{
		if (pickup(fs[0]))
		{
			io_queue(log_forklift, me);
			if (pickup(fs[1]))
			{
				io_queue(log_forklift, me);
				set_last_meal2now(me);
				has_eaten = true;
				io_queue(log_eating, me);
				usleep(me->c->t2eat * 1000);
				putdown(fs[1]);
			}
			putdown(fs[0]);
			if (has_eaten)
				return ;
		}
		usleep(200);
	}
}

// writen from the ego perspective of the philospher
void	*philo_routine(void *s)
{
	t_philo	*me;
	int		meals;

	meals = 0;
	me = s;
	while (me->c->max_meals <= 0 || meals < me->c->max_meals)
	{
		philo_routine_eating(me);
		meals++;
		io_queue(log_sleeping, me);
		usleep(me->c->t2nap * 1000);
		io_queue(log_thinking, me);
	}
	turn_off_philo(me);
	return (NULL);
}

static void	ft_phil_void(t_philo *p)
{
	(void)p;
}

size_t	spawn_philos(t_philo_conf *c, t_philo *philos)
{
	size_t	i;

	i = 0;
	io_queue(ft_phil_void, NULL);
	start_timer();
	while (i < c->n_phil)
	{
		philos[i].last_meal = read_timer();
		if (pthread_create(&(philos[i].thread_id), NULL, philo_routine,
				&(philos[i])))
			return (i);
		i++;
	}
	return (i);
}

// these two functions check if a philo happy or starved
// it is it applyies the requires state change in the data
// and returns true.
// if handle_happy detectes an non happy philo it returns false and does nothing.
bool	handle_happy(t_philo *philo)
{
	if (philo->last_meal != -1)
		return (false);
	pthread_detach(philo->thread_id);
	philo->thread_id = 0;
	return (true);
}

// if handle_starved detectes an non starved philo it returns false and does nothing.
bool	handle_starved(t_philo *philo)
{
	if ((read_timer() - philo->last_meal) < philo->c->t2die)
		return (false);
	pthread_detach(philo->thread_id);
	philo->thread_id = 0;
	return (true);
}

typedef enum e_philo_event
{
	NO_EVENT = 0,
	DEAD = 1,
	ALL_HAPPY = -1
}				t_philo_event;

t_philo_event	phil_iterate(t_philo_conf *c, t_philo *philos)
{
	size_t			i;
	t_philo_event	result;

	result = ALL_HAPPY;
	i = 0;
	while (i < c->n_phil)
	{
		if (philos[i].thread_id != 0)
		{
			result = NO_EVENT;
			pthread_mutex_lock(&philos[i].last_meal_mutex);
				// TODO error handling
			if (handle_starved(&philos[i]))
				result = (io_queue(log_died, &philos[i]), DEAD);
			if (c->max_meals >= 0)
				handle_happy(&philos[i]);
			pthread_mutex_unlock(&philos[i].last_meal_mutex);
				// TODO error handling
			if (result == DEAD)
				return (result);
		}
		i++;
	}
	return (result);
}

// prototype version of the function waits for all started threads
void	wait4end(t_philo_conf *c, t_philo *philos)
{
	t_philo_event	result;

	result = NO_EVENT;
	while (result == NO_EVENT)
		result = phil_iterate(c, philos);
}

int	run_sim(t_philo_conf *c)
{
	t_philo	*philos;
	t_frk	*frks;

	if (!c)
		return (0);
	frks = bring_the_cutlery(c->n_phil);
	philos = new_philos(c, frks);
	if (!philos)
		return (free(frks), 0);
	spawn_philos(c, philos);
	wait4end(c, philos);
	free(philos);
	free(frks);
	return (1);
}
