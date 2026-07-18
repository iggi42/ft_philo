/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:57:59 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/18 11:58:08 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRK_H
# define FRK_H
# include "mutex.h"

/// THEIR MOST SACRED CUTLERY
typedef t_cond			t_frk;

// set default values really
bool					init_frk(t_frk *frk);

// ...
bool					pickup(t_frk *frk);
bool					putdown(t_frk *frk);
#endif
