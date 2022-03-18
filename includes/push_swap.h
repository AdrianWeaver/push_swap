/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/18 13:33:00 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"
# include "libftprintf.h"

typedef struct s_ps_pile
{
	int					value;
	int					index;
	struct s_ps_pile	*next;
}				t_ps_pile;

t_ps_pile	*ft_last_pile(t_ps_pile *pile);
t_ps_pile	*ft_new_pile(int value);
void		ft_pile_add_back(t_ps_pile **start, t_ps_pile *new);
t_ps_pile	*ft_get_pile(int argc, char **argv);
void		ft_get_index(t_ps_pile *pile_a, int argc);
void		ft_push(t_ps_pile **dest, t_ps_pile **srcs);
void		ft_print_pile(t_ps_pile *pile_a, t_ps_pile *pile_b);
#endif
