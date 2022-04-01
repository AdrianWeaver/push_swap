/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:16:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 17:31:23 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_double(t_ps_pile *pile, int value)
{
	t_ps_pile	*tmp;

	tmp = pile;
	while (tmp->next)
	{
		if (tmp->value == value)
		{
			ft_destroy_pile(pile);
			ft_printf("Error\n");
			exit (1);
		}
		tmp = tmp->next;
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
		{
			ft_pile_add_back(&start_a, tmp_a);
			ft_check_double(start_a, tmp_a->value);
		}
		i++;
	}
	return (start_a);
}

void	ft_get_index(t_ps_pile *pile_a, int argc)
{
	t_ps_pile	*max;
	t_ps_pile	*save;
	int			cmp;

	save = pile_a;
	while (argc > 0)
	{
		pile_a = save;
		cmp = INT_MIN;
		while (pile_a)
		{
			if (pile_a->value == INT_MIN && pile_a->index == 0)
				pile_a->index = 1;
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

void	ft_destroy_pile(t_ps_pile *pile)
{
	t_ps_pile	*to_free;

	while (pile)
	{
		to_free = pile;
		pile = pile->next;
		free(to_free);
	}
}
