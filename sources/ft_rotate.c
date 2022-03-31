/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:19:31 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/31 14:33:21 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_ps_pile **pile)
{
	t_ps_pile	*tmp;
	t_ps_pile	*last;

	tmp = (*pile);
	*pile = (*pile)->next;
	last = ft_last_pile(*pile);
	last->next = tmp;
	last->next->next = NULL;
}

void	ft_ra(t_ps_pile **pile_a)
{
	ft_rotate(pile_a);
	ft_printf("ra\n");
}

void	ft_rb(t_ps_pile **pile_b)
{
	ft_rotate(pile_b);
	ft_printf("rb\n");
}

void	ft_rr(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	ft_rotate(pile_a);
	ft_rotate(pile_b);
	ft_printf("rr\n");
}
