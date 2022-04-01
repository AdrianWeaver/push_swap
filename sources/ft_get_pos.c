/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:35 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 16:42:36 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_pos(t_ps_pile **pile)
{
	t_ps_pile	*tmp;
	int			i;

	i = 0;
	tmp = *pile;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_get_smallest_pos(t_ps_pile **pile)
{
	t_ps_pile	*tmp;
	int			smallest;
	int			smallest_pos;

	tmp = *pile;
	smallest = INT_MAX;
	ft_get_pos(pile);
	smallest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < smallest)
		{
			smallest = tmp->index;
			smallest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (smallest_pos);
}

void	ft_get_cost(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	t_ps_pile	*tmp_a;
	t_ps_pile	*tmp_b;
	int			pa_size;
	int			pb_size;

	tmp_a = *pile_a;
	tmp_b = *pile_b;
	pb_size = ft_pile_size(tmp_b);
	pa_size = ft_pile_size(tmp_a);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > (pb_size / 2))
			tmp_b->cost_b = - (pb_size - tmp_b->pos);
		tmp_b->cost_a = tmp_b->aim_a;
		if (tmp_b->aim_a > (pa_size / 2))
			tmp_b->cost_a = - (pa_size - tmp_b->aim_a);
		tmp_b = tmp_b->next;
	}
}

int	ft_get_aim_a_highest(t_ps_pile **pile_a, t_ps_pile *tmp, int cmp, int aim)
{
	t_ps_pile	*tmp_a;
	int			cmp_a;

	tmp_a = *pile_a;
	if (cmp == INT_MAX)
	{
		while (tmp_a)
		{
			if (tmp->index < cmp_a)
			{
				cmp_a = tmp->index;
				aim = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
	}
	return (aim);
}

void	ft_get_aim_a(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	t_ps_pile	*tmp_a;
	t_ps_pile	*tmp_b;
	int			cmp_a;
	int			index_aim;

	tmp_b = (*pile_b);
	ft_get_pos(pile_a);
	ft_get_pos(pile_b);
	while (tmp_b)
	{
		cmp_a = INT_MAX;
		tmp_a = (*pile_a);
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < cmp_a)
			{
				cmp_a = tmp_a->index;
				index_aim = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
		index_aim = ft_get_aim_a_highest(pile_a, tmp_b, cmp_a, index_aim);
		tmp_b->aim_a = index_aim;
		tmp_b = tmp_b->next;
	}
}
