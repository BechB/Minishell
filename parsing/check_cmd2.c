/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:58:09 by bbousaad          #+#    #+#             */
/*   Updated: 2024/07/16 20:23:49 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	first_check_redir(char *cmd)
{
	if (cmd[0] == '<' || cmd[0] == '>')
		return (0);
	return (1);
}

int	check_redir(t_parse *p, char *cmd)
{
	if (!first_check_redir(cmd))
	{
		parse_error(p, RED "syntax error near `newline'" RESET);
		free_double_tab(p->cmd_table);
		return (0);
	}
	if (!check_redir1(p, cmd))
	{
		free_double_tab(p->cmd_table);
		return (0);
	}
	return (1);
}

int	check_redir1(t_parse *p, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			i++;
			if (cmd[i] == ' ')
			{
				while (cmd[i] && cmd[i] == ' ')
					i++;
				if (cmd[i] == '>' || cmd[i] == '<')
				{
					parse_error(p, RED "syntax error near redirection" RESET);
					return (0);
				}
			}
		}
		i++;
	}
	check_redir2(p, cmd);
	return (1);
}

void	check_redir3(t_parse *p)
{
	if (p->cmdtab_redir_l > 3)
		parse_error(p, RED "syntax error with `<'" RESET);
	if (p->cmdtab_redir_r > 2)
		parse_error(p, RED "syntax error with `>'" RESET);
}

void	check_redir2(t_parse *p, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != '>' && cmd[i] != '<' && cmd[i] != ' ')
		{
			p->cmdtab_redir_l = 0;
			p->cmdtab_redir_r = 0;
		}
		if (cmd[i] == '>' && cmd[i + 1] == '<')
			parse_error(p, RED "syntax error with `<'" RESET);
		else if (cmd[i] == '<' && cmd[i + 1] == '>')
			parse_error(p, RED "syntax error with `\\n'" RESET);
		else if (cmd[i] == '<' && cmd[i + 1] == '<' && cmd[i + 2] == '<')
			parse_error(p, RED "syntax error with `<'" RESET);
		else if (cmd[i] == '<')
			p->cmdtab_redir_l++;
		else if (cmd[i] == '>')
			p->cmdtab_redir_r++;
		i++;
	}
	check_redir3(p);
	redir_last_char(p, cmd);
}
