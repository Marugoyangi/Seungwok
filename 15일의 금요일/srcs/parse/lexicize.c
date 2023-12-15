/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongbpa <jeongbpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:10:34 by jeongbpa          #+#    #+#             */
/*   Updated: 2023/12/15 15:52:52 by jeongbpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*redirection(int *i, t_line *line)
{
	int		position[2];
	char	*red;

	position[0] = *i;
	red = NULL;
	if (line->data[*i] == '>' && line->data[*i + 1] == '>' && \
	line->info[*i + 1] == T_OPERATOR)
		red = ft_strdup(">>");
	else if (line->data[*i] == '<' && line->data[*i + 1] == '<' && \
	line->info[*i + 1] == T_OPERATOR)
		red = ft_strdup("<<");
	else if (line->data[*i] == '>' && line->data[*i + 1] != '>')
		red = ft_strdup(">");
	else if (line->data[*i] == '<' && line->data[*i + 1] != '<')
		red = ft_strdup("<");
	*i = *i + ft_strlen(red);
	free(red);
	while (line->info[*i] == T_SPACE)
		(*i)++;
	while (line->info[*i] != T_SPACE && line->info[*i] != T_OPERATOR && \
	line->info[*i] != T_PARENTHESIS && line->info[*i] != '\0')
		(*i)++;
	return (create_node(ft_substr(line->data, position[0], *i - position[0]), \
	subline(line, position[0], *i), L_REDIRECTION));
}

t_node	*subshell(int *i, t_line *line)
{
	int	position[2];

	position[0] = *i;
	*i = *i + 1;
	while (line->info[*i] && line->info[*i] != T_PARENTHESIS)
		(*i)++;
	if (line->info[*i] != T_PARENTHESIS)
		return (NULL);
	*i = *i + 1;
	position[1] = *i;
	return (create_node(ft_substr(line->data, position[0], \
	position[1] - position[0]), subline(line, position[0], position[1]) \
	, L_SUBSHELL));
}

t_node	*simple_cmd(int *i, t_line *line)
{
	int		position[2];

	position[0] = *i;
	while (line->info[*i] == T_WORD || line->info[*i] == T_LITERAL || \
	line->info[*i] == T_DOUBLE_QUOTE || line->info[*i] == T_SINGLE_QUOTE || \
	line->info[*i] == T_ENV || \
	line->info[*i] == T_ASTERISK)
		(*i)++;
	position[1] = *i;
	return (create_node(ft_substr(line->data, position[0], \
	position[1] - position[0]), subline(line, position[0], position[1]) \
	, L_SIMPLE_COMMAND));
}

t_node	*check_type(t_line *line, int *i)
{
	if (line->info && line->info[*i] == T_OPERATOR && \
	(line->data[*i] == '&' && line->data[*i + 1] == '&'))
	{
		*i = *i + 2;
		return (create_node("&&", NULL, L_LOGICAL_OPERATOR));
	}
	else if (line->info && line->info[*i] == T_OPERATOR && \
	(line->data[*i] == '|' && line->data[*i + 1] == '|'))
	{
		*i = *i + 2;
		return (create_node("||", NULL, L_LOGICAL_OPERATOR));
	}
	else if (line->info && line->info[*i] == T_OPERATOR && \
	(line->data[*i] == '|' && line->data[(*i)++ + 1] != '|'))
		return (create_node("|", NULL, L_PIPELINE));
	else if (line->info && (line->info[*i] == T_WORD || line->info[*i] == T_LITERAL \
	|| line->info[*i] == T_DOUBLE_QUOTE || line->info[*i] == T_SINGLE_QUOTE \
	|| line->info[*i] == T_ENV || line->info[*i] == T_ASTERISK))
		return (simple_cmd(i, line));
	else if (line->info && line->info[*i] == T_PARENTHESIS)
		return (subshell(i, line));
	else if (line->info && line->info[*i] == T_OPERATOR && \
		(line->data[*i] == '>' || line->data[*i] == '<'))
		return (redirection(i, line));
	return (NULL);
}

void	lexicize(t_arg *arg)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (!arg->line.data || !arg->line.info || !arg->line.info[i] || \
	!arg->line.data[i])
		return ;
	arg->ast_head = check_type(&arg->line, &i);
	tmp = arg->ast_head;
	while (tmp && arg->line.data && arg->line.info && arg->line.info[i])
	{
		while (arg->line.info[i] == T_SPACE)
			i++;
		if (arg->line.info[i])
			tmp->right = check_type(&arg->line, &i);
		if (tmp->right)
		{
			tmp->right->left = tmp;
			tmp = tmp->right;
		}
	}
}
