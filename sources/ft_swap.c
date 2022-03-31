/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:19:02 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/31 14:31:47 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_value_index(t_ps_pile *pile1, t_ps_pile *pile2)
{
	int	tmp;

	tmp = pile1->value;
	pile1->value = pile2->value;
	pile2->value = tmp;
	tmp = pile1->index;
	pile1->index = pile2->index;
	pile2->index = tmp;
}

void	ft_swap_pile(t_ps_pile *pile)
{
	if (pile == NULL || pile->next == NULL)
		return ;
	ft_swap_value_index(pile, pile->next);
}

void	ft_ss(t_ps_pile **pile_a, t_ps_pile **pile_b)
{
	ft_swap_pile(*pile_a);
	ft_swap_pile(*pile_b);
	ft_printf("ss\n");
}

void	ft_sa(t_ps_pile	**pile_a)
{
	ft_swap_pile(*pile_a);
	ft_printf("sa\n");
}

void	ft_sb(t_ps_pile	**pile_b)
{
	ft_swap_pile(*pile_b);
	ft_printf("sb\n");
}
