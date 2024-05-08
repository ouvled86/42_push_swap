/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:54:26 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/08 14:53:16 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*temp;
	int		v;

	if (!*a)
	{
		ft_printf("KO\n");
		exit(0);
	}
	temp = *a;
	while (temp->next)
	{
		v = temp->next->value;
		if (v < temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	locate_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b)
	{
		temp = *b;
		while (temp && temp->tarpos != (*a)->tarpos - 1)
			temp = temp->next;
		return (temp->first_half);
	}
	return (-1);
}

int	bottom_a(t_stack **a)
{
	t_stack	*temp;

	temp = last_node(*a);
	return (temp->tarpos);
}

void	rot_push(t_stack **a, t_stack **b, int a_bot)
{
	while (*b && (*b)->tarpos != (*a)->tarpos - 1)
	{
		if (a_bot == bottom_a(a) || (*b)->tarpos > bottom_a(a))
		{
			pa(a, b, 0);
			ra(a, 0);
		}
		else if (a_bot == bottom_a(a) || (*b)->tarpos < bottom_a(a))
			rb(b, 0);
	}
}

void	revrot_push(t_stack **a, t_stack **b, int a_bot)
{
	while (*b && (*b)->tarpos != (*a)->tarpos - 1)
	{
		if (a_bot == bottom_a(a) || (*b)->tarpos > bottom_a(a))
		{
			pa(a, b, 0);
			ra(a, 0);
		}
		else if (a_bot == bottom_a(a) || (*b)->tarpos < bottom_a(a))
			rrb(b, 0);
	}
}
