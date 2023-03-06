/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:54:36 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/06 18:29:20 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_stack **a, t_stack **b)
{
    int n;
    int bucket_size;

	bucket_size = ft_bucket_size(*a);
    n = 0;
    while (n < NB_BUCKETS)
    {
        move_bucket(a, b, bucket_size, n);
        n++;
    }
	sort_n(a, b);
}

void	sort_n(t_stack **a, t_stack **b)
{
	t_stack	*parent;
	t_stack	*max;
	t_stack	*second_max;
	int	m;

	m = 1;
	while (*b)
	{
		set_cost(b);
		max = get_max(*b);
		second_max = get_second_max(*b, max);
		if (second_max && second_max_ok(second_max, max))
		{
			up_node(b, second_max, 1);
			ft_p(a, b, 1);
			max = get_max(*b);
		}
		up_node(b, max, 1);
		ft_p(a, b, 1);
		if ((*a) && (*a)->next && (*a)->content > (*a)->next->content)
			ft_s(a, 0);
	}
	// t_stack *tmp_a = *a;
	// t_stack *tmp_b = *b;
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
}

//monter un node en haut de pile
void	up_node(t_stack **stack, t_stack *node, int n)
{
	int	i;

	set_cost(stack);
	i = abs(node->cost);
	while (i > 0)
	{		
		if (node->cost < 0)
			ft_r(stack, n);
		else if (node->cost > 0)
			ft_rr(stack, n);
		i--;
	}
}

