/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:35 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 10:29:13 by aweaver          ###   ########.fr       */
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
		tmp_b->cost_b = tmp_b->pos + 1;
		if (tmp_b->pos > (pb_size / 2))
			tmp_b->cost_b = - (pb_size - tmp_b->pos + 1);
		tmp_b->cost_a = tmp_b->aim_a;
		if (tmp_b->aim_a > (pa_size / 2))
			tmp_b->cost_a = - (pa_size - tmp_b->aim_a + 1);
		tmp_b = tmp_b->next;
	}
}

void	ft_get_aim_a(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	t_ps_pile	*tmp_a;
	t_ps_pile	*tmp_b;
	int			cmp_a;
	int			index_aim;

	cmp_a = INT_MAX;
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
		tmp_b->aim_a = index_aim;
		tmp_b = tmp_b->next;
	}
}
