/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:40:08 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/14 20:34:06 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdio.h>

void log_forklift(t_philo *philo)
{
	printf("%ld: [%d] has taken a fork\n", read_timer(), (int) philo->id);
}

void log_eating(t_philo *philo)
{
	printf("%ld: [%d] is sleeping\n", read_timer(), (int) philo->id);
}

void log_thinking(t_philo *philo)
{
	printf("%ld: [%d] is thinking\n", read_timer(), (int) philo->id);
}

void log_animated(t_philo *philo)
{
	printf("%ld: [%d] has awoken. left(%p) right(%p)\n",
		read_timer(), (int) philo->id, philo->left, philo->right
	);
}

void log_died(t_philo *philo)
{
	printf("%ld: [%d] died\n", read_timer(), (int) philo->id);
}
