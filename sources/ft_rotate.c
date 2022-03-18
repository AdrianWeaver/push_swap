/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:19:31 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/18 17:19:45 by aweaver          ###   ########.fr       */
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
