/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopinbell <woopinbell@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:35:51 by seungwok          #+#    #+#             */
/*   Updated: 2023/12/17 22:14:06 by woopinbell       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	exec_command(t_node *node, t_arg *arg)
{
	int		status;
	char	**path;

	status = 0;
	status = check_built_in(node, arg);
	if (status == -1)
	{
		path = set_path(arg->envp_head);
		if (!path && node->data && (!(!ft_strncmp(node->data, "./", 2)
			|| !ft_strncmp(node->data, "../", 3)
			|| !ft_strncmp(node->data, "/", 1))))
		{
			write(2, "minishell: ", 11);
			write(2, node->data, ft_strlen(node->data));
			write(2, ": command not found\n", 20);
			return (127);
		}
		status = external_command(node, arg, path);
		free_split(path);
	}
	else if (!(status == -1) && arg->fork_sign == 1)
		exit(status);
	return (status);
}

int	external_command(t_node *node, t_arg *arg, char **path)
{
	int		status;
	pid_t	pid;

	status = 0;
	if (!arg->fork_sign)
	{
		pid = fork();
		if (!pid)
			external_command_child(node, arg, path);
		else if (node->data && ft_strstr(node->data, "/minishell\0"))
			signal_ignore();
		else if (node->data && !ft_strstr(node->data, "/minishell\0"))
		{
			signal(SIGINT, sig_handler_exec);
			signal(SIGQUIT, sig_handler_exec);
		}
		waitpid(pid, &status, 0);
		terminal_interactive(arg);
		return (WEXITSTATUS(status));
	}
	else
		exec_check_path(node, arg, path);
	return (1);
}

void	external_command_child(t_node *node, t_arg *arg, char **path)
{
	arg->term.c_lflag |= ECHOCTL;
	tcsetattr(STDOUT_FILENO, TCSANOW, &arg->term);
	signal(SIGINT, sig_handler_waiting);
	signal(SIGQUIT, sig_handler_waiting);
	exec_check_path(node, arg, path);
	exit (0);
}

void	exec_check_path(t_node *node, t_arg *arg, char **path)
{
	char	*excutable_path;
	char	**envp;

	envp = make_envp(arg->envp_head);
	if (!path && node->data && (!(!ft_strncmp(node->data, "./", 2)
		|| !ft_strncmp(node->data, "../", 3)
		|| !ft_strncmp(node->data, "/", 1))))
	{
		execve(node->argv[0], node->argv, envp);
		excutable_path = find_path(path, node->data);
		if (!excutable_path)
			exec_perror("execve");
		execve(excutable_path, node->argv, envp);
		exec_perror("execve");
	}
	else
	{
		excutable_path = find_path(path, node->data);
		if (!excutable_path)
			exec_perror("execve");
		execve(excutable_path, node->argv, envp);
		exec_perror("execve");
	}
	if (excutable_path)
		free(excutable_path);
	free_split(envp);
}
