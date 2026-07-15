/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:04:33 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/15 07:28:42 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>

/// op can be
// 0 to start the timer from zero
// 1 to get the time passed since it was started
static long timer(int op)
{
	static unsigned long long	start;
	struct timeval				tv;
	long						now;

	if (gettimeofday(&tv, NULL))
		return (-1);
	now = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	if(op == 0)
		return (start = now, start);
	else if(op == 1)
		return (now - start);
	return (-1);
}

void start_timer(void)
{
	timer(0);
}

long read_timer(void)
{
	return timer(1);
}
