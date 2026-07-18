/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:10:02 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/13 03:20:14 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <stddef.h>

bool	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// check if input is valid
bool	ft_aisi(char *input)
{
	if (input == NULL || *input == '\0')
		return (false);
	while (*input)
	{
		if (!ft_isdigit(*input))
			return (false);
		input++;
	}
	return (true);
}

// parse input
int	ft_atoi(char *input)
{
	long	result;

	result = 0;
	while (ft_isdigit(*input))
	{
		result = (result * 10) + (*input - 48);
		input++;
	}
	return (result);
}
