/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:05:49 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/28 11:00:59 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_ps_pile *pile)
{
	t_ps_pile	*save;

	save = pile;
	while (pile->next != NULL)
	{
		if (pile->value > pile->next->value)
		{
			pile = save;
			return (0);
		}
		pile = pile->next;
	}
	pile = save;
	return (1);
}
