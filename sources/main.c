/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:20:00 by aweaver           #+#    #+#             */
/*   Updated: 2022/03/17 15:00:08 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_pile

t_ps_pile	*ft_get_pile(int argc, char **argv)
{
	t_ps_pile	start_a;
	t_ps_pile	start_b;
	t_ps_pile	tmp_a;
	t_ps_pile	tmp_b;

	start_a = NULL;
	while (i < argc)
	{
		tmp_a = ft_new_pile(ft_atoi(argv[i]));
		tmp_b = ft_new_pile(NULL);
		if (start_a == NULL)
		{
			start_a = tmp_a;
			start_b = tmp_b;
		}
		else
		{
			ft_lstadd_back(&start_a, tmp_a);
			ft_lstadd_back(&start_b, tmp_b);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	ft_check_args(argc, argv);
	ft_get_piles(argc, argv);
	ft_printf("%d\n", argc);
	return (0);
}
