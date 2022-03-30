/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:16:29 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/30 10:38:57 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_pile(t_ps_pile *p_a, t_ps_pile *p_b)
{
	ft_printf("%-14s	%-14s\n", "PILE A:", "PILE B:");
	while (p_a || p_b)
	{
		if (p_a == NULL || p_a->index == 0)
		{
			ft_printf("%-14s	%d:%11d\n", "empty", p_b->index, p_b->value);
			p_b = p_b->next;
		}
		else if (p_b == NULL || p_b->index == 0)
		{
			ft_printf("%d:%11d	%14s\n", p_a->index, p_a->value, "empty");
			p_a = p_a->next;
		}
		else
		{
			ft_printf("%d:%11d	%d:%11d\n", p_a->index, p_a->value,
				p_b->index, p_b->value);
			p_a = p_a->next;
			p_b = p_b->next;
		}
	}
}
