/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopinbell <woopinbell@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:34:44 by seungwok          #+#    #+#             */
/*   Updated: 2023/12/19 21:21:27 by woopinbell       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					check_built_in(t_node *node, t_arg *arg);
int					built_in_echo(char **argv);
int					built_in_pwd(t_arg *arg);
int					built_in_exit(t_node *node, t_arg *arg);
unsigned long long	check_exit_arg(char **argv);

int	check_built_in(t_node *node, t_arg *arg)
{
	if (!ft_strcmp(node->data, "echo"))
		return (built_in_echo(node->argv));
	else if (!ft_strcmp(node->data, "cd"))
		return (built_in_cd(node, arg, node->argv));
	else if (!ft_strcmp(node->data, "pwd"))
		return (built_in_pwd(arg));
	else if (!ft_strcmp(node->data, "exit"))
		return (built_in_exit(node, arg));
	else if (!ft_strcmp(node->data, "export"))
		return (built_in_export(node, arg->envp_head));
	else if (!ft_strcmp(node->data, "unset"))
		return (built_in_unset(node, arg));
	else if (!ft_strcmp(node->data, "env"))
		return (built_in_env(arg->envp_head));
	return (-1);
}

int	built_in_echo(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] && !strncmp(argv[i], "-n", 2))
	{
		j = 1;
		while (argv[i][j] == 'n')
			j++;
		if (argv[i][j])
			break ;
		i++;
	}
	if (i > 1)
		j = 0;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (j)
		printf("\n");
	return (0);
}

int	built_in_pwd(t_arg *arg)
{
	char	*current_path;

	current_path = getcwd(0, 0);
	if (!current_path)
		printf("%s\n", arg->pwd);
	else
	{
		printf("%s\n", current_path);
		free(current_path);
	}
	return (0);
}

int	built_in_exit(t_node *node, t_arg *arg)
{
	unsigned long long	exit_num;
	unsigned long long	max;

	max = 9223372036854775808ULL;
	if (!node->argv[1])
		exit (arg->last_exit_status);
	exit_num = check_exit_arg(node->argv);
	if (exit_num > max || (exit_num == max && node->argv[1][0] != '-'))
	{
		printf("minishell: exit: numeric argument required");
		exit (255);
	}
	if (node->argv[1] && node->argv[2])
	{
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	if (node->argv[1][0] == '-')
		exit (256 - (exit_num % 256));
	else
		exit (exit_num % 256);
}

unsigned long long	check_exit_arg(char **argv)
{
	unsigned long long	return_value;
	int					i;

	i = 0;
	if (argv[1][0] == '-')
		i++;
	return_value = 0;
	while ('0' <= argv[1][i] && argv[1][i] <= '9' && i < 20)
	{
		return_value = return_value * 10 + (argv[1][i] - '0');
		i++;
	}
	if (argv[1][i] || i == 19)
		return (9223372036854775809ULL);
	return (return_value);
}
