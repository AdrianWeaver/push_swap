/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:00 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 20:19:04 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc <= 2 || argv == NULL)
		exit (1);
	while (i < argc)
	{
		j = 1;
		if (ft_is_int(argv[i]) == 0)
			ft_error();
		if (argv[i][0] == '-' || argv[i][0] == '+'
			|| ft_isdigit(argv[i][0]) == 1)
		{
			while (argv[i][j])
			{
				if (ft_isdigit(argv[i][j]) == 0)
					ft_error();
				j++;
			}
		}
		else
			ft_error();
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_ps_pile	*pile_a;
	t_ps_pile	*pile_b;
	int			pile_size;

	ft_check_args(argc, argv);
	pile_b = NULL;
	pile_a = ft_get_pile(argc, argv);
	pile_size = ft_pile_size(pile_a);
	if (pile_size == 3)
		ft_sort_three(&pile_a);
	else if (pile_size == 2 && ft_check_sort(pile_a) == 1)
		ft_sa(&pile_a);
	else
	{
		ft_get_index(pile_a, argc - 1);
		ft_the_algo(&pile_a, &pile_b);
		ft_get_aim_a(&pile_a, &pile_b);
		ft_get_cost(&pile_a, &pile_b);
	}
	ft_destroy_pile(pile_a);
	return (0);
}
