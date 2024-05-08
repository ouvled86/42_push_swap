/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:33:47 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/08 14:52:57 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rot(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*holder;

	if (!*stack || !(*stack)->next)
		exit(1);
	temp = *stack;
	holder = last_node(*stack);
	holder->prev->next = NULL;
	holder->prev = NULL;
	holder->next = temp;
	temp->prev = holder;
	*stack = holder;
	(*stack)->size = stack_size_setpos(stack);
}

void	rra(t_stack **a, int f)
{
	rev_rot(a);
	if (f == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int f)
{
	rev_rot(b);
	if (f == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int f)
{
	rev_rot(a);
	rev_rot(b);
	if (f == 0)
		ft_printf("rrr\n");
}
