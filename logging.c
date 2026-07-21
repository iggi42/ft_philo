/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:40:08 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/19 19:50:09 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

void	io_queue(void (*print_smth)(t_philo *p), t_philo *p)
{
	static bool				is_init;
	static pthread_mutex_t	io_mut;

	if (!is_init)
	{
		if (!pthread_mutex_init(&io_mut, NULL))
			is_init = true;
		else
			return ;
	}
	if (pthread_mutex_lock(&io_mut))
		return ;
	print_smth(p);
	pthread_mutex_unlock(&io_mut);
}

void	log_forklift(t_philo *philo)
{
	printf("%10ld: [%d] has taken a fork\n", read_timer(), (int)philo->id);
}

void	log_eating(t_philo *philo)
{
	printf("%10ld: [%d] is eating\n", read_timer(), (int)philo->id);
}

void	log_sleeping(t_philo *philo)
{
	printf("%10ld: [%d] is sleeping\n", read_timer(), (int)philo->id);
}

void	log_thinking(t_philo *philo)
{
	printf("%10ld: [%d] is thinking\n", read_timer(), (int)philo->id);
}

void	log_animated(t_philo *philo)
{
	printf("%ld: [%d] was born. left(%p) right(%p)\n", read_timer(),
		(int)philo->id, philo->left, philo->right);
}

void	log_died(t_philo *philo)
{
	printf("%10ld: [%d] died\n", read_timer(), (int)philo->id);
}
