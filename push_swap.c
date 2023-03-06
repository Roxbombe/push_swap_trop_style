/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:42:55 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/06 18:29:12 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a, t_stack **b)
{
	if ((*a)->content > (*a)->next->next->content)
		ft_r(a, 0);
	if ((*a)->content > (*a)->next->next->content)
		ft_r(a, 0);
	if (ft_is_sort(*a))
		return ;
	if ((*a)->content < (*a)->next->next->content
		&& (*a)->content > (*a)->next->content)
		ft_s(a, 0);
	else
	{
		ft_p(b, a, 0);
		ft_r(a, 0);
		ft_p(a, b, 1);
	}
	return ;
}

void	sort_small_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
	{
		if (!(ft_is_sort(*a)))
			ft_r(a, 0);
	}
	if (ft_lstsize(*a) == 3)
		sort_3(a, b);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*nb;
	t_stack	*max;
	t_stack	*second_max;

	if (!(parse(argc, argv)))
		return (0);
	a = create_a(argv);
	if (!a)
		return (0);
	if (ft_is_sort(a))
		return (0);
	put_index(&a);
	b = NULL;
	if (ft_lstsize(a) <= 3)
		sort_small_stack(&a, &b);
	else
		sort_big_stack(&a, &b);	
	// t_stack *tmp_a = a;
	// t_stack *tmp_b = b;
	// ft_printf("\n");
	// while (tmp_a)
	// {
	// 	ft_printf("%d ", tmp_a->content);
	// 	tmp_a = tmp_a->next;
	// }
	// ft_printf("\n");
	// while (tmp_b)
	// {
	// 	ft_printf("%d ", tmp_b->content);
	// 	tmp_b = tmp_b->next;
	// }

	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
