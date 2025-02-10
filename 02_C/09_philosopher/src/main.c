/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:55:49 by czhu              #+#    #+#             */
/*   Updated: 2025/02/08 16:18:34 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/* check if the input is only digits */
int	ft_only_digit(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* check if the program input is valid */
int	check_arg_valid(char **av)
{
	if (ft_atoi(av[1]) <= 0 || ft_only_digit(av[1]) == 0)
		return (printf("invalid philo number\n"), 1);
	if (ft_atoi(av[2]) <= 0 || ft_only_digit(av[2]) == 0)
		return (printf("invalid time to die\n"), 1);
	if (ft_atoi(av[3]) <= 0 || ft_only_digit(av[3]) == 0)
		return (printf("invalid time to eatr\n"), 1);
	if (ft_atoi(av[4]) <= 0 || ft_only_digit(av[4]) == 0)
		return (printf("invalid time to sleep\n"), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || ft_only_digit(av[5]) == 0))
		return (printf("invalid number of meals must each\n"), 1);
	return (0);
}

/* main function */
int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philo[300];
	pthread_mutex_t	fork[300];

	if (ac != 5 && ac != 6)
		return (printf("Wrong arg count\n"), 1);
	if (check_arg_valid(av))
		return (1);
	init_program(&program, philo);
	init_fork(fork, ft_atoi(av[1]));
	init_philo(philo, &program, fork, av);
	create_thread(&program, fork);
	destory_all(&program, fork);
	return (0);
}
