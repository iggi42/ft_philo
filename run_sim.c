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
#include "utils.h"
#include <stdlib.h>

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

void	*philo_routine(void *s)
{
	//	t_philo *my_star = s;
	log_animated(s);
	while (true)
		;
}

size_t	spawn_philos(t_philo_conf *c, t_philo *philos)
{
	size_t	i;

	i = 0;
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

// prototype version of the function waits for all started threads
void	wait4end(t_philo_conf *c, t_philo *philos)
{
	size_t	i;

	i = 0;
	// just wait until 1 philo has not eaten long enough
	while (true)
	{
		if ((read_timer() - philos[i].last_meal) >= c->t2die)
			return (log_died(&philos[i]));
		i = (i + 1) % c->n_phil;
	}
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
	free(frks);
	free(philos);
	return (1);
}
