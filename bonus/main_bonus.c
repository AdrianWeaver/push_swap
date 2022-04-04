/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:15:23 by aweaver           #+#    #+#             */
/*   Updated: 2022/04/04 11:59:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	ft_nuke_pile(t_ps_pile *pile_a, t_ps_pile *pile_b)
{
	ft_destroy_pile(pile_a);
	ft_destroy_pile(pile_b);
}

void	ft_exit(t_ps_pile *pile_a, t_ps_pile *pile_b, char *input)
{
	ft_nuke_pile(pile_a, pile_b);
	free(input);
	get_next_line(GNL_FLUSH);
	write(2, "Error\n", 6);
	exit (1);
}

/* You may be wondering why this function is called like that.
 * Well let me tell you a story, a story of old age, blood and dragons
 * nah nevermind, this is just a private joke, "make_magic" functions
 * are only here to suit the need of norminette with functions longer
 * than 25 lines so this is just the rest of the following function.
 */

void	ft_make_dark_magic(t_ps_pile **pile_a, t_ps_pile **pile_b, char *input)
{
	if (ft_strcmp(input, "rb\n") == 0)
		ft_rotate(pile_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ft_rotate(pile_a);
	else if (ft_strcmp(input, "rr\n") == 0)
	{
		ft_rotate(pile_a);
		ft_rotate(pile_b);
	}
	else if (ft_strcmp(input, "rra\n") == 0)
		ft_reverse_rotate(pile_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		ft_reverse_rotate(pile_b);
	else if (ft_strcmp(input, "rrr\n") == 0)
	{
		ft_reverse_rotate(pile_a);
		ft_reverse_rotate(pile_b);
	}
	else
		ft_exit(*pile_a, *pile_b, input);
}

void	ft_do_operations(t_ps_pile **pile_a, t_ps_pile **pile_b, char *input)
{
	if (ft_strcmp(input, "sa\n") == 0)
		ft_swap_pile(*pile_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		ft_swap_pile(*pile_b);
	else if (ft_strcmp(input, "ss\n") == 0)
	{
		ft_swap_pile(*pile_a);
		ft_swap_pile(*pile_b);
	}
	else if (ft_strcmp(input, "pa\n") == 0)
		ft_push(pile_a, pile_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		ft_push(pile_b, pile_a);
	else
		ft_make_dark_magic(pile_a, pile_b, input);
}

int	main(int argc, char **argv)
{
	t_ps_pile	*pile_a;
	t_ps_pile	*pile_b;
	char		*input;
	int			loop;

	if (argc < 2)
		return (0);
	pile_a = ft_get_pile(argc, argv);
	pile_b = NULL;
	loop = 1;
	while (loop == 1)
	{
		input = get_next_line(0);
		if (input != NULL)
			ft_do_operations(&pile_a, &pile_b, input);
		else if (input == NULL)
			loop = 0;
		free(input);
	}
	get_next_line(GNL_FLUSH);
	if (ft_check_sort(pile_a) == 1 && ft_pile_size(pile_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_nuke_pile(pile_a, pile_b);
}
