/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:49:07 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/18 17:20:39 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_ps_pile **dest, t_ps_pile **srcs)
{
	t_ps_pile	*tmp;

	tmp = (*srcs)->next;
	(*srcs)->next = *dest;
	*dest = *srcs;
	(*srcs) = tmp;
}
