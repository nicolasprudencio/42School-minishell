#include "libseas.h"

static int	st_allocate_new(t_cmd_table **cmd_table, t_token *input);
static int	st_find_size(t_token *input);
static void	st_fill_command(t_cmd_table **cmd_table, t_token *input, 
		int lenght);

int	cmd_create(t_cmd_table **cmd_table, t_token *input)
{
	t_cmd_table	*aux;
	t_cmd_table	*last_cmd;

	if (!*cmd_table)
	{
		*cmd_table = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
		if (!st_allocate_new(cmd_table, input))
			return (FALSE);
	}
	else
	{
		cmd_last(&last_cmd, cmd_table);
		aux = NULL;
		aux = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
		if (!aux)
			return (FALSE);
		if (!st_allocate_new(&aux, input))
			return (FALSE);
		last_cmd->next = aux;
	}
	return (TRUE);
}

static int	st_allocate_new(t_cmd_table **cmd_table, t_token *input)
{
	int	lenght;

	if (!*cmd_table)
		return (FALSE);
	(*cmd_table)->command = (t_command *)mem_calloc(1, sizeof(t_command));
	if (!(*cmd_table)->command)
		return (FALSE);
	lenght = st_find_size(input);
	(*cmd_table)->command->parsed = (char **)mem_calloc(lenght + 1,
			sizeof(char *));
	if (!(*cmd_table)->command->parsed)
		return (FALSE);
	st_fill_command(cmd_table, input, lenght);
	(*cmd_table)->command->io[0] = 0;
	(*cmd_table)->command->io[1] = 1;
	return (TRUE);
}

static int	st_find_size(t_token *input)
{
	int	i;

	i = 0;
	while (input)
	{
		if (!str_comp(input->token_type, "<PIPE>"))
			break ;
		if (!str_comp(input->token_type, "<SPECIAL>"))
			break ;
		input = input->next;
		i++;
	}
	return (i);
}

static void	st_fill_command(t_cmd_table **cmd_table, t_token *input, 
		int lenght)
{
	int	i;

	i = -1;
	while (++i < lenght)
	{
		(*cmd_table)->command->parsed[i] = str_dup(input->value);
		input = input->next;
	}
}
