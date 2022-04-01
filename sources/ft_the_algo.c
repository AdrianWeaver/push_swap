/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:37 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 12:15:10 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_rest(t_ps_pile **pile_a, t_ps_pile **pile_b, int list_size,
	int swapped)
{
	while (list_size - swapped > 3)
	{
		ft_pb(pile_a, pile_b);
		swapped++;
	}
}

void	ft_push_half(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	int	i;
	int	swapped;
	int	list_size;
	int	med;

	i = 0;
	swapped = 0;
	list_size = ft_pile_size(*pile_a);
	med = list_size / 2;
	while (list_size > 6 && i < list_size && swapped < list_size / 2)
	{
		if ((*pile_a)->index <= med)
		{
			ft_pb(pile_a, pile_b);
			swapped++;
		}
		else
			ft_ra(pile_a);
		i++;
	}
	ft_push_rest(pile_a, pile_b, list_size, swapped);
}

void	ft_get_cheapest_b(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	t_ps_pile	*tmp;
	int			cmp;
	int			cost_a;
	int			cost_b;

	tmp = *pile_b;
	cmp = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a) < ft_abs(cmp))
		{
			cmp = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_make_choice(pile_a, pile_b, cost_a, cost_b);
}

void	ft_the_algo(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	ft_push_half(pile_a, pile_b);
	ft_sort_three(pile_a);
}
