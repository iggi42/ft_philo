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

#include "philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// bool	init_frk(t_frk *frk);

static void	*ft_calloc(size_t n_el, size_t el_size)
{
	void	*result;

	if (n_el == 0 || el_size == 0 || (SIZE_MAX / n_el) < el_size)
		return (NULL);
	el_size *= n_el;
	result = malloc(el_size);
	memset(result, 0, el_size);
	return (result);
}

static t_frk	*bring_the_cutlery(size_t n)
{
	t_frk *frks = ft_calloc(n, sizeof(t_frk));
	size_t i = 0;
	while(i < n)
		init_frk(&frks[i++]);
	return frks;
}

void *philo_routine(void *s)
{
//	t_philo *my_star = s;
	log_animated(s);
	while(true);
	return s;
}

// we could construct all the philo structs first and the start the timer, but fuck it
size_t	spawn_philos(t_philo_conf *c, t_frk *cutler, pthread_t **philos)
{
	size_t i = 0;
	t_philo *new_philo;

	if(!c) return 0;
	pthread_t	*threads = ft_calloc(c->n_phil, sizeof(pthread_t));
	if(!threads || !cutler) return 0;
	*philos = threads;
	start_timer();
	while(i < c->n_phil)
	{
		new_philo = malloc(sizeof(t_philo));
		if(!new_philo) return (i);
		new_philo->id = (unsigned char) i;
		new_philo->left = &cutler[i];
		new_philo->right = &cutler[(i + 1) % c->n_phil];
		if (pthread_create(&threads[i], NULL, philo_routine, new_philo))
			return (free(new_philo), i);
		i++;
	}
	return (i);
}

t_philo_id	find_starved(size_t n, pthread_t *philos)
{
	while(n--)
	{
		pthread_join(philos[n], NULL);
	}
}

int		run_sim(t_philo_conf *c)
{
	if(!c) return 0;
	pthread_t *arr_philos;
	t_frk *frks = bring_the_cutlery(c->n_phil);
	int living = spawn_philos(c, frks, &arr_philos);
	join_philos(living, arr_philos);
	free(arr_philos);
	return 1;
}
