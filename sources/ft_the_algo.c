/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:37 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/28 18:28:43 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_the_algo(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	int	i;
	int	list_size;
	int	med;

	i = 0;
	list_size = ft_pile_size(*pile_a);
	ft_printf("size = %d\n", list_size);
	med = list_size / 2;
	while (i < list_size - 1 && (list_size - i) >= 3)
	{
		ft_printf("Debug de la honte\n");
		if ((*pile_a)->index <= med)
			ft_push(pile_b, pile_a);
		else
			ft_rotate(pile_a);
		i++;
	}
	ft_printf("OUT Debug de la honte\n");
}
