/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:00 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/18 09:12:57 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_pile(t_ps_pile *pile_a, t_ps_pile *pile_b)
{
	(void)pile_b;
	ft_printf("PILE A:			PILE B:\n");
	while (pile_a)
	{
		ft_printf("%d\n", pile_a->value);
		pile_a = pile_a->next;
	}
}

t_ps_pile	*ft_get_pile(int argc, char **argv)
{
	t_ps_pile	*start_a;
	t_ps_pile	*tmp_a;
	int			i;

	i = 1;
	start_a = NULL;
	while (i < argc)
	{
		tmp_a = ft_new_pile(ft_atoi(argv[i]));
		if (start_a == NULL)
			start_a = tmp_a;
		else
			ft_pile_add_back(&start_a, tmp_a);
		i++;
	}
	return (start_a);
}

void	ft_check_args(int argc, char **argv)
{
	if (argc < 2 || argv == NULL)
		exit (0);
}

int	main(int argc, char **argv)
{
	t_ps_pile	*pile_a;

	ft_check_args(argc, argv);
	pile_a = ft_get_pile(argc, argv);
	ft_print_pile(pile_a, NULL);
	//ft_printf("%d\n", argc);
	return (0);
}
