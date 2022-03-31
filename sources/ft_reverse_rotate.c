/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:52:22 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/31 14:13:36 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_ps_pile	**pile)
{
	t_ps_pile	*tmp;
	t_ps_pile	*last;
	t_ps_pile	*ante;

	tmp = (*pile);
	last = ft_last_pile(*pile);
	ante = ft_ante_pile(*pile);
	(*pile) = last;
	(*pile)->next = tmp;
	ante->next = NULL;
}

void	ft_rra(t_ps_pile **pile_a)
{
	ft_reverse_rotate(pile_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_ps_pile **pile_b)
{
	ft_reverse_rotate(pile_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	ft_reverse_rotate(pile_a);
	ft_reverse_rotate(pile_b);
	ft_printf("rrr\n");
}
