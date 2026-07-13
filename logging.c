/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:40:08 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/13 07:24:35 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

long long current_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (long long) tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void log_forklift(t_philo *philo)
{
	printf("%lld: [%d] has taken a fork\n", current_ms(), (int) philo->id);
}

void log_eating(t_philo *philo)
{
	printf("%lld: [%d] is sleeping\n", current_ms(), (int) philo->id);
}

void log_thinking(t_philo *philo)
{
	printf("%lld: [%d] is thinking\n", current_ms(), (int) philo->id);
}

void log_died(t_philo *philo)
{
	printf("%lld: [%d] died\n", current_ms(), (int) philo->id);
}
