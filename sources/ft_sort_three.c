/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:18:35 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/28 11:39:32 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_biggest(t_ps_pile pile)
{
	int			biggest;

	biggest = pile.index;
	while (pile.next != NULL)
	{
		if (pile.index > biggest)
			biggest = pile.index;
		pile = *(pile.next);
	}
	return (biggest);
}

void	ft_sort_three(t_ps_pile **pile)
{
	int			biggest;
	t_ps_pile	*tmp;

	tmp = *pile;
	if (ft_check_sort(tmp) == 1)
		return ;
	biggest = ft_get_biggest(*tmp);
	if (tmp->index == biggest)
	{
		ft_rotate(&tmp);
	}
	else if (tmp->next->index == biggest)
		ft_reverse_rotate(&tmp);
	if (tmp->index > tmp->next->index)
		ft_swap_pile(tmp);
	*pile = tmp;
}
