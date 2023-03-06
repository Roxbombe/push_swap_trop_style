/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:04:37 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/03/06 18:29:41 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int second_max_ok(t_stack *second_max, t_stack *max)
{
	if (((max->cost <= 0 && second_max->cost <= 0)
		|| (max->cost > 0 && second_max->cost > 0))
		&& abs(second_max->cost) < abs(max->cost))
		return (1);
	else
		return (0);
}

t_stack	*get_second_max(t_stack *stack, t_stack *max)
{
	t_stack	*curr;

	curr = stack;
	while (curr)
	{
		if (curr->content == (max->content) - 1)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void opti(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->next && (*b)->next 
		&& (*b)->content < (*b)->next->content
		&& (*a)->content > (*a)->next->content)
		ft_ss(a, b);
	if ((*b)->next && (*b)->content < (*b)->next->content)
		ft_s(b, 1);
}

void	move_bucket(t_stack **a, t_stack **b, int bucket_size, int n)
{
	int new_content;
	int	q;

	q = bucket_size;
	while (ft_lstsize(*a) > 0 && q)
	{
		new_content = (*a)->content;
		if (new_content <= bucket_size * (n + 1))
		{
			ft_p(b, a, 0);
			if (new_content < ft_lstsize(*b))
				ft_r(b, 1);
			opti(a, b);
			q--;
		}
		else
			ft_r(a, 0);
	}
}


				
// void	move_buckets(t_stack **a, t_stack **b)
// {
// 	int bucket;
// 	int	q;
// 	int	n;
// 	int new_content;

// 	bucket = ft_bucket(*a);
// 	n = 0;
// 	while (n < NB_BUCKETS)
// 	{
// 		q = bucket;
// 		while (ft_lstsize(*a) > 3 && q)
// 		{
// 			if ((*a)->content <= bucket * (n + 1))
// 			{
// 				new_content = (*a)->content;
// 				ft_p(b, a, 0);
// 				if (new_content < ft_lstsize(*b))
// 					ft_r(b, 1);
// 				q--;
// 			}
// 			else
// 			{
// 				ft_r(a, 0);
// 			}	
// 		}
// 		n++;
// 	}
// }

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
	

// int	*array(t_stack *stack)
// {
// 	int	i;
// 	int	*array;
// 	t_stack	*curr;

// 	array = (int *)malloc(sizeof(int) * ft_lstsize(stack) + 1);
// 	i = 0;
// 	curr = stack;
// 	while (i < ft_lstsize(stack) && curr)
// 	{
// 		array[i] = curr->content;
// 		i++;
// 	}
// 	return (array);
// }

// t_stack	*get_best_max(t_stack *stack)
// {
// 	t_stack	*max;
// 	t_stack	*second_max;
// 	t_stack	*curr;
// 	t_stack	*curr2;

// 	set_cost(&stack);
// 	curr = stack;
// 	max = stack;
// 	while (curr)
// 	{
// 		if (curr->content > max->content)
// 			max = curr;
// 		curr = curr->next;
// 	}
// 	curr2 = stack;
// 	second_max = max;
// 	while (curr2)
// 	{
// 		if (curr2->content < second_max->content)
// 		{
// 			second_max = curr2;
// 			break;
// 		}
// 		curr2 = curr2->next;
// 	}
// 	if (abs(max->cost) < abs(second_max->cost))
// 		return (max);
// 	else
// 		return (second_max);
// }