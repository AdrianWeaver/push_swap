/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:49:07 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/31 14:29:11 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_ps_pile **dest, t_ps_pile **srcs)
{
	t_ps_pile	*tmp;

	if (*srcs == NULL)
		return ;
	tmp = (*srcs)->next;
	(*srcs)->next = *dest;
	*dest = *srcs;
	(*srcs) = tmp;
}

void	ft_pa(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	ft_push(pile_a, pile_b);
	ft_printf("pa\n");
}

void	ft_pb(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	ft_push(pile_b, pile_a);
	ft_printf("pb\n");
}
