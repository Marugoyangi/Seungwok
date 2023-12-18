/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_logical_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbpa <jeongbpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:54:16 by seungwok          #+#    #+#             */
/*   Updated: 2023/12/17 10:54:03 by jeongbpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_logical_operator(t_node *node, t_arg *arg)
{
	if (!strcmp(node->data, "&&"))
	{
		if (!start_exec(node->left, arg))
		{
			if (!start_exec(node->right, arg))
				return (0);
			else
				return (1);
		}
		else
			return (1);
	}
	else if (!strcmp(node->data, "||"))
	{
		if (start_exec(node->left, arg))
		{
			if (!start_exec(node->right, arg))
				return (0);
			else
				return (1);
		}
		else
			return (0);
	}
	return (1);
}