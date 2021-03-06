/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/01 17:28:07 by aweaver          ###   ########.fr       */
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
	int					pos;
	int					aim_a;
	int					cost_a;
	int					cost_b;
}				t_ps_pile;

/****************************************************************************/
/*								CHECK FUNCTS								*/
/****************************************************************************/

void		ft_get_index(t_ps_pile *pile_a, int argc);
int			ft_check_sort(t_ps_pile *pile);
void		ft_check_double(t_ps_pile *pile, int value);

/****************************************************************************/
/*								PILE FUNCTS									*/
/****************************************************************************/

t_ps_pile	*ft_last_pile(t_ps_pile *pile);
t_ps_pile	*ft_ante_pile(t_ps_pile	*pile);
t_ps_pile	*ft_new_pile(int value);
t_ps_pile	*ft_get_pile(int argc, char **argv);
int			ft_pile_size(t_ps_pile *pile_a);
void		ft_pile_add_back(t_ps_pile **start, t_ps_pile *new);
void		ft_destroy_pile(t_ps_pile *pile);

/****************************************************************************/
/*								OPERATIONS									*/
/****************************************************************************/

void		ft_push(t_ps_pile **dest, t_ps_pile **srcs);
void		ft_pa(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_pb(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_swap_pile(t_ps_pile *pile);
void		ft_sa(t_ps_pile **pile_a);
void		ft_sb(t_ps_pile **pile_b);
void		ft_ss(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_rotate(t_ps_pile **pile);
void		ft_ra(t_ps_pile **pile_a);
void		ft_rb(t_ps_pile **pile_b);
void		ft_rr(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_reverse_rotate(t_ps_pile **pile);
void		ft_rra(t_ps_pile **pile_a);
void		ft_rrb(t_ps_pile **pile_b);
void		ft_rrr(t_ps_pile **pile_a, t_ps_pile **pile_b);

/****************************************************************************/
/*								VISUALIZER									*/
/****************************************************************************/

void		ft_print_pile(t_ps_pile *pile_a, t_ps_pile *pile_b);

/****************************************************************************/
/*								ALGO FUNCTS									*/
/****************************************************************************/

void		ft_the_algo(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_sort_three(t_ps_pile **pile);
void		ft_push_rest(t_ps_pile **p_a, t_ps_pile **p_b, int l_size, int s);
void		ft_push_half(t_ps_pile **p_a, t_ps_pile **p_b);
void		ft_get_aim_a(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_get_pos(t_ps_pile **pile);
int			ft_get_smallest_pos(t_ps_pile **pile);
void		ft_get_cost(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_get_cheapest(t_ps_pile **pile_a, t_ps_pile **pile_b);
void		ft_make_choice(t_ps_pile **p_a, t_ps_pile **p_b, int a, int b);
void		ft_both_pos(t_ps_pile **p_a, t_ps_pile **p_b, int *a, int *b);
void		ft_both_neg(t_ps_pile **p_a, t_ps_pile **p_b, int *a, int *b);
void		ft_cost_left(t_ps_pile **pile, int *cost, char a_or_b);
void		ft_order_list(t_ps_pile **pile_a);
#endif
