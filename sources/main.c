/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:00 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/18 17:14:54 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_pile(t_ps_pile *p_a, t_ps_pile *p_b)
{
	ft_printf("PILE A:			PILE B:\n");
	while (p_a || p_b)
	{
		if (p_a == NULL || p_a->index == 0)
		{
			ft_printf("empty			%d:%5d\n", p_b->index, p_b->value);
			p_b = p_b->next;
		}
		else if (p_b == NULL || p_b->index == 0)
		{
			ft_printf("%d:%5d			empty\n", p_a->index, p_a->value);
			p_a = p_a->next;
		}
		else
		{
			ft_printf("%d:%5d			%d:%5d\n", p_a->index, p_a->value,
				p_b->index, p_b->value);
			p_a = p_a->next;
			p_b = p_b->next;
		}
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2 || argv == NULL)
		exit (1);
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-' || ft_isdigit(argv[i][0]) == 1)
		{
			while (argv[i][j])
			{
				if (ft_isdigit(argv[i][j]) == 0)
					ft_error();
				j++;
			}
		}
		else
			ft_error();
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_ps_pile	*pile_a;
	t_ps_pile	*pile_b;

	ft_check_args(argc, argv);
	pile_b = NULL;
	pile_a = ft_get_pile(argc, argv);
	ft_get_index(pile_a, argc);
	ft_reverse_rotate(&pile_a);
	ft_print_pile(pile_a, pile_b);
	return (0);
}
