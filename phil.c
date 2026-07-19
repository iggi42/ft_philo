/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:59:58 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/18 12:00:01 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "time.h"
#include "utils.h"
#include <stdlib.h>

t_philo	*new_philos(t_philo_conf *c, t_frk *cutler)
{
	size_t	i;
	t_philo	*philos;

	if (!c || !cutler)
		return (NULL);
	philos = ft_calloc(c->n_phil, sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < c->n_phil)
	{
		if (pthread_mutex_init(&(philos[i].last_meal_mutex), NULL))
			return (free(philos), NULL);
		philos[i].id = (unsigned char)i + 1;
		philos[i].c = c;
		philos[i].left = &cutler[i];
		philos[i].right = &cutler[(i + 1) % c->n_phil];
		i++;
	}
	return (philos);
}

t_timespan	time_since_last_meal(t_philo *p)
{
	t_timespan	last_meal;
	t_timespan	now;

	now = read_timer();
	if (pthread_mutex_lock(&p->last_meal_mutex))
		return (-1);
	last_meal = p->last_meal;
	if (pthread_mutex_unlock(&p->last_meal_mutex))
		return (-1);
	return (now - last_meal);
}

void set_last_meal2now(t_philo *p)
{
	if (p == NULL || pthread_mutex_lock(&p->last_meal_mutex))
		return;
	p->last_meal = read_timer();
	pthread_mutex_unlock(&p->last_meal_mutex);
}

void turn_off_philo(t_philo *p)
{
	if (p == NULL || pthread_mutex_lock(&p->last_meal_mutex))
		return;
	p->last_meal = -1;
	pthread_mutex_unlock(&p->last_meal_mutex);
}
