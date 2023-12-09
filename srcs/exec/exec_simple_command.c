/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbpa <jeongbpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:35:51 by seungwok          #+#    #+#             */
/*   Updated: 2023/12/10 01:23:12 by jeongbpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_path(char **path, char *command);
int		check_built_in(t_node *node, t_env *env);

// 정상종료시 0, 그 외 나머지 값 출력.
int	exec_command(t_node *node, t_env *env, char **path)
{
	int		status;

	status = check_built_in(node, env);
	if (status == -1)
		status = external_command(node, path);
	return (status);
}


int	external_command(t_node *node, char **path)
{
	char	*excutable_path;
	char	**command_option;
	int		status;
	pid_t	pid;

	excutable_path = find_path(path, node->data);
	if (excutable_path)
		return (1);
	command_option = node->argv;
	pid = fork();
	if (!pid)
	{
		if (execve(excutable_path, command_option, 0) == -1)	// execve함수를 통한 새로운 프로세서 생성 실패시 perror 에러출력
			perror("execve");
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);	// 부모 프로세서는 status에 자식프로세스의 종료상태를 담아서 반환.
		return (status);
	}
}

int	check_built_in(t_node *node, t_env *env)
{
	if (!ft_strcmp(node->data, "echo"))
		return (built_in_echo(node->argv));
	else if (!ft_strcmp(node->data, "cd"))
		return (built_in_cd(node->argv));
	else if (!ft_strcmp(node->data, "pwd"))
		return (built_in_pwd());
	else if (!ft_strcmp(node->data, "exit"))
		built_in_exit();
	else if (!ft_strcmp(node->data, "export"))
		return (built_in_export(node, env));
	else if (!ft_strcmp(node->data, "unset"))
		return (built_in_unset(node, env));
	else if (!ft_strcmp(node->data, "env"))
		return (built_in_env(env));
	return (-1);
}

char	*find_path(char **path, char *command)
{
	char	*command_path;
	char	*try_executable;
	
	while (*path)
	{
		command_path = ft_strjoin(*path, "/");
		try_executable = ft_strjoin(command_path, command);
		if (!access(try_executable, X_OK))
		{
			free(command_path);
			return(try_executable);
		}
		free(command_path);
		free(try_executable);
		path++;
	}
	return (command_path);
}