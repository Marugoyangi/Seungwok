/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_set_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbpa <jeongbpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:25:08 by seungwok          #+#    #+#             */
/*   Updated: 2023/12/13 15:37:33 by jeongbpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		start_exec(t_node *node, t_arg *arg);

void	set_exec(t_arg *arg)
{
		set_heredoc(arg->ast_head, arg);
		arg->fork_sign = 0;
		start_exec(arg->ast_head, arg);
}

char	*set_heredoc_filename()
{
	int		fd;
	int		i;
	char	*filename;

	i = 1;
	while(1)
	{
		filename = ft_strjoin(".", ft_itoa(i));
		fd = open(filename, O_RDONLY);	// open 성공 = filename 파일 존재
		if (fd == -1)
			return (filename);
		free(filename);
		i++;
	}
}

void	init_file_for_heredoc(t_node *node)
{
	int		fd;
	char	*line;

	node->filename = set_heredoc_filename();
	fd = open(node->filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	while (1)
	{
		line = readline("환경변수 처리");	
	   if (!ft_strcmp(line, node->argv[0]))
		{
			free(line);
			break;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
}

// heredoc 찾아서 입력값 받은 후 파일에 저장하기
void	set_heredoc(t_node *node, t_arg *arg)
{
	int		pid;
	int		status;
	
	if (!node)
		return ;
	if (node->type == L_REDIRECTION && !ft_strcmp(node->data, "<<"))
	{
		pid = fork();
		if (!pid)
		{
			signal(SIGINT, sig_handler_heredoc);
			signal(SIGQUIT, sig_handler_heredoc);
			init_file_for_heredoc(node);
			exit (0);
		}
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			waitpid(pid, &status, 0);
			terminal_interactive(arg);
		}
	}
	set_heredoc(node->left, arg);
	set_heredoc(node->right, arg);
}



int	start_exec(t_node *node, t_arg *arg)
{
	if (!node)
		return (0);
	if (node->type == L_SUBSHELL)
		return (exec_subshell(node, arg));
	else if (node->type == L_LOGICAL_OPERATOR)
		return (exec_logical_operator(node, arg));
	else if (node->type == L_PIPELINE)
		return (exec_pipeline(node, arg));
	else if (node->type == L_REDIRECTION)
		return (exec_redirection(node, arg));
	else if (node->type == L_SIMPLE_COMMAND)
		return (exec_command(node, arg));
	else
		return (1);	// 노드가 비어있지않은데 위 분기에 없다면 오류.
}
