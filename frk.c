/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 04:02:18 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/13 05:52:20 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdbool.h>

bool	init_frk(t_frk *frk)
{
	if (!frk)
		return (false);
	frk->val = false;
	return (pthread_mutex_init(&frk->mutex, NULL) == 0);
}

bool	pickup(t_frk *frk)
{
	if (!pthread_mutex_lock(&frk->mutex))
		return (false);
	frk->val = true;
	return (pthread_mutex_unlock(&frk->mutex) == 0);
}

bool	putdown(t_frk *frk)
{
	if (!pthread_mutex_lock(&frk->mutex))
		return (false);
	frk->val = false;
	return (pthread_mutex_unlock(&frk->mutex) == 0);
}
