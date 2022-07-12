#include "pipex.h"
#include <stdio.h>
void	pathexecv1(char *argv[])
{
	extern char **environ;
	char **paths;
	char **arguments;
	char *infile;
	int i;
	int params;
	int j;
	params = 0;
	j = 0;
	i = 0;
	infile = argv[1];
	arguments = ft_split(argv[2], ' ');
	while (arguments[params])
	{
		params++;
	}
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
			paths = ft_split(&environ[i][5], ':');
		i++;
	}
	while (paths[j])
	{
		paths[j] = ft_strjoin(paths[j], "/");
		paths[j] = ft_strjoin(paths[j], arguments[0]);
		if (!access(paths[j], F_OK | X_OK))
		{
			arguments[params] = infile; 
			execve(paths[j], arguments, NULL);	
		}
		j++;
	}
}
