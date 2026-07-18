# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 01:51:41 by fkruger           #+#    #+#              #
#    Updated: 2026/07/17 19:37:38 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = philo
CC = cc
CFLAGS += -MD -Wall -Wextra -Werror
CFLAGS += -g

SRCS = frk.c ft_calloc.c ft_atoi.c logging.c ph_main.c run_sim.c time.c phil.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

# normal targets
.PHONY: fclean clean re all
all: $(NAME)
re: clean all
fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) $(OBJS) $(DEPS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread -o $@ $+
