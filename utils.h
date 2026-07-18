/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:04:00 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/18 12:04:59 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include <stdbool.h>
// util functions
void	*ft_calloc(size_t n_el, size_t el_size);

/// argument parings
bool	ft_isdigit(int c);

// check if a cli arg is valid
bool	ft_aisi(char *arg);

// parse a cli arg
int		ft_atoi(char *arg);
#endif
