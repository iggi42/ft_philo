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

// val is true if the fork is in use

bool	init_frk(t_frk *frk)
{
	if (!frk)
		return (false);
	frk->val = false;
	return (pthread_mutex_init(&frk->mutex, NULL) == 0);
}

bool	pickup(t_frk *frk)
{
	bool	result;

	result = false;
	if (!pthread_mutex_lock(&frk->mutex))
		return (false);
	if (!frk->val)
	{
		frk->val = true;
		result = true;
	}
	if (!pthread_mutex_unlock(&frk->mutex))
		return (false);
	return (result);
}

bool	putdown(t_frk *frk)
{
	bool	result;

	result = false;
	if (!pthread_mutex_lock(&frk->mutex))
		return (false);
	if(frk->val)
	{
		frk->val = false;
		result = true;
	}
	if (!pthread_mutex_unlock(&frk->mutex))
		return (false);
	return (result);
}
