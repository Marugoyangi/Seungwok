/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbpa <jeongbpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:52:12 by jeongbpa          #+#    #+#             */
/*   Updated: 2023/12/18 15:52:14 by jeongbpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_subshell(t_node *node, t_arg *arg)
{
	pid_t	pid;
	int		status;
	char	**path;	

	pid = 0;
	status = 0;
	arg->fork_sign++;
	pid = fork();
	if (!pid)
	{
		path = set_path(arg->envp_head);
		set_subshell(node, arg);
		exec_check_path(node, arg, path);
	}
	else
	{
		waitpid(pid, &status, 0);
		arg->fork_sign--;
	}
	return (WEXITSTATUS(status));
}

void	set_subshell(t_node *node, t_arg *arg)
{
	int		i;

	node->data = modified_strtrim(node->data, " ()");
	i = -1;
	while (node->argv[++i])
		free(node->argv[i]);
	free(node->argv);
	node->argv = ft_malloc(sizeof(char **) * 4);
	node->argv[0] = arg->minishell_path;
	node->argv[1] = "\n";
	node->argv[2] = node->data;
	node->argv[3] = NULL;
	node->data = "./minishell";
}