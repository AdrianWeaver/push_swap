/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 08:21:09 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/18 17:04:17 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_pile	*ft_last_pile(t_ps_pile *pile)
{
	while (pile)
	{
		if (pile->next == NULL)
			return (pile);
		pile = pile->next;
	}
	return (pile);
}

t_ps_pile	*ft_ante_pile(t_ps_pile *pile)
{
	while (pile->next)
	{
		if (pile->next->next == NULL)
			return (pile);
		pile = pile->next;
	}
	return (pile);
}

t_ps_pile	*ft_new_pile(int value)
{
	t_ps_pile	*new;

	new = malloc(sizeof(*new) * 1);
	if (new == 0)
		return (0);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	ft_pile_add_back(t_ps_pile **start, t_ps_pile *new)
{
	t_ps_pile	*last;

	if (start == 0)
	{
		*start = new;
		return ;
	}
	last = ft_last_pile(*start);
	last->next = new;
}
