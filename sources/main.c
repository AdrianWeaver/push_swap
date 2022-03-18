/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:00 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/18 10:52:25 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_pile(t_ps_pile *p_a, t_ps_pile *p_b)
{
	ft_printf("PILE A:			PILE B:\n");
	while (p_a || p_b)
	{
		if (p_a == NULL)
		{
			ft_printf("empty			%d:%3d\n", p_b->index, p_b->value);
			p_b = p_b->next;
		}
		else if (p_b == NULL)
		{
			ft_printf("%d:%3d			empty\n", p_a->index, p_a->value);
			p_a = p_a->next;
		}
		else
		{
			ft_printf("%3d:%3d			%3d:%3d\n", p_a->index, p_a->value,
				p_b->index, p_b->value);
			p_a = p_a->next;
			p_b = p_b->next;
		}
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

void	ft_get_index(t_ps_pile *pile_a, int argc)
{
	t_ps_pile	*max;
	t_ps_pile	*save;
	int			cmp;

	argc--;
	save = pile_a;
	while (argc > 0)
	{
		pile_a = save;
		cmp = INT_MIN;
		while (pile_a)
		{
			if (pile_a->value > cmp && pile_a->index == 0)
			{
				cmp = pile_a->value;
				max = pile_a;
				pile_a = save;
			}
			else
				pile_a = pile_a->next;
		}
		max->index = argc;
		argc--;
	}
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
	ft_get_index(pile_a, argc);
	ft_print_pile(pile_a, NULL);
	return (0);
}
