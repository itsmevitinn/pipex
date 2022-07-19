/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:14:39 by vsergio           #+#    #+#             */
/*   Updated: 2022/07/18 22:06:54 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

void    close_first_command(int **readwrite);
void	close_middle_commands(int **readwrite, int indexpipe);
void	close_last_command(int **readwrite, int argc);
void	runfirstcommand(char *argv, int **readwrite, char **env);
void	runmiddlecommands(char *argv, int **readwrite, int indexpipe, char **env);
void	runlastcommand(char *argv, int **readwrite, int indexpipe, int argc, char **env);
void	writecommand(char *argv, char **envp, int **readwrite);
void	doexecve(char **paths, char **arguments);
void	firstchild(char **argv, int **readwrite, char **envp);
void	secondchild(char **argv, int **readwrite, char **envp);
void	thirdchild(char **argv, int **readwrite, char **envp);
void	error_msg(char *msg, int errorstatus);
void	error_msg_errno(char *msg, int errorstatus, int iderrno);
void	pathfilter(char *argv, char **envp);
#endif
