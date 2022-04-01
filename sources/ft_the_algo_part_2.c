/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_algo_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:11:30 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 16:15:01 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_both_neg(t_ps_pile **pile_a, t_ps_pile **pile_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(pile_a, pile_b);
	}
}

void	ft_both_pos(t_ps_pile **pile_a, t_ps_pile **pile_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(pile_a, pile_b);
	}
}

void	ft_cost_left(t_ps_pile **pile, int *cost, char a_or_b)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ft_printf("r%c\n", a_or_b);
			ft_rotate(pile);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			ft_printf("rr%c\n", a_or_b);
			ft_reverse_rotate(pile);
		}
	}
}

void	ft_make_choice(t_ps_pile **pile_a, t_ps_pile **pile_b, int cost_a,
		int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_both_neg(pile_a, pile_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_both_pos(pile_a, pile_b, &cost_a, &cost_b);
	ft_cost_left(pile_a, &cost_a, 'a');
	ft_cost_left(pile_b, &cost_b, 'b');
	ft_pa(pile_a, pile_b);
}
