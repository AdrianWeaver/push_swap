/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:18:35 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 14:33:17 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_biggest(t_ps_pile *pile)
{
	t_ps_pile	*tmp;
	int			biggest;

	tmp = pile;
	biggest = tmp->index;
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
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
	biggest = ft_get_biggest(*pile);
	if (tmp->index == biggest)
	{
		ft_ra(&tmp);
	}
	else if (tmp->next->index == biggest)
		ft_rra(&tmp);
	if (tmp->index > tmp->next->index)
		ft_sa(&tmp);
	*pile = tmp;
}
