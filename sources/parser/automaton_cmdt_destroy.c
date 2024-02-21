#include "libseas.h"

static void	st_close_io(t_cmd_table **cmd);

void	cmdt_destroy(t_cmd_table **cmd_table)
{
	t_cmd_table	*aux1;
	t_cmd_table	*aux2;

	if (!(*cmd_table))
		return ;
	aux1 = (*cmd_table);
	while (aux1)
	{
		if (aux1->command)
			cmd_destroy(aux1);
		aux2 = aux1;
		aux1 = aux1->next;
		free(aux2);
	}
}

void	cmd_destroy(t_cmd_table *cmd)
{
	int			i;

	st_close_io(&cmd);
	i = -1;
	while (cmd->command->parsed[++i])
		free(cmd->command->parsed[i]);
	free(cmd->command->parsed);
	free(cmd->command);
}

static void	st_close_io(t_cmd_table **cmd)
{
	int	inp_fd;
	int	out_fd;

	inp_fd = (*cmd)->command->io[STDIN_FILENO];
	out_fd = (*cmd)->command->io[STDOUT_FILENO];
	if (inp_fd != STDIN_FILENO && inp_fd > 0)
		close(inp_fd);
	if (out_fd != STDOUT_FILENO && out_fd > 0)
		close(out_fd);
}
