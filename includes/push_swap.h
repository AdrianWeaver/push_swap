/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/30 10:17:22 by aweaver          ###   ########.fr       */
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

void		ft_get_index(t_ps_pile *pile_a, int argc);
int			ft_check_sort(t_ps_pile *pile);
void		ft_sort_three(t_ps_pile **pile);
void		ft_the_algo(t_ps_pile **pile_a, t_ps_pile **pile_b);

/****************************************************************************/
/*								PILE FUNCT									*/
/****************************************************************************/
t_ps_pile	*ft_last_pile(t_ps_pile *pile);
t_ps_pile	*ft_ante_pile(t_ps_pile	*pile);
t_ps_pile	*ft_new_pile(int value);
t_ps_pile	*ft_get_pile(int argc, char **argv);
int			ft_pile_size(t_ps_pile *pile_a);
void		ft_pile_add_back(t_ps_pile **start, t_ps_pile *new);

/****************************************************************************/
/*								OPERATIONS									*/
/****************************************************************************/

void		ft_push(t_ps_pile **dest, t_ps_pile **srcs);
void		ft_swap_pile(t_ps_pile *pile);
void		ft_rotate(t_ps_pile **pile);
void		ft_reverse_rotate(t_ps_pile **pile);

/****************************************************************************/
/*								VISUALIZER									*/
/****************************************************************************/

void		ft_print_pile(t_ps_pile *pile_a, t_ps_pile *pile_b);
#endif
