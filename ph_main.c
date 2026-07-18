/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 01:56:46 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/13 09:12:37 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

// return true if all parameters were successfully parsed
// return false on parsing errors and so on.
// only do the required args in this function
bool	parse_req_args(char **args, t_philo_conf *c)
{
	if (!ft_aisi(args[0]) || !ft_aisi(args[1]) || !ft_aisi(args[2])
		|| !ft_aisi(args[3]))
		return (false);
	c->n_phil = ft_atoi(args[0]);
	c->t2die = ft_atoi(args[1]);
	c->t2eat = ft_atoi(args[2]);
	c->t2nap = ft_atoi(args[3]);
	return (true);
}

int	endless_feast(char **args)
{
	t_philo_conf	c;

	if (!parse_req_args(args, &c))
		return (-1);
	c.max_meals = -1;
	return (run_sim(&c));
}

int	limited_feast(char **args)
{
	t_philo_conf	c;

	if (!parse_req_args(args, &c) || !ft_aisi(args[4]))
		return (-1);
	c.max_meals = ft_atoi(args[4]);
	return (run_sim(&c));
}

int	main(int argc, char **argv)
{
	if (argc == 5)
		return (endless_feast(argv + 1));
	else if (argc == 6)
		return (limited_feast(argv + 1));
	return (-1);
}
