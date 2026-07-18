/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:00:08 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/18 12:00:11 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H
# include <stdbool.h>
# include <pthread.h>

typedef struct s_cond
{
	bool				val;
	pthread_mutex_t		mutex;
}						t_cond;

#endif
