#include "libseas.h"

static int	st_allocate_new(t_cmd_table **cmd_table, t_token *input);
static int	st_find_size(t_token *input);
static int	st_fill_command(t_cmd_table **cmd_table, t_token *input);
static int	st_special_case(t_cmd_table **cmd_table, t_token *input);

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
	if (!*cmd_table)
		return (FALSE);
	(*cmd_table)->command = (t_command *)mem_calloc(1, sizeof(t_command));
	if (!(*cmd_table)->command)
		return (FALSE);
	if (!str_comp(input->token_type, "<SPECIAL>"))
		return (st_special_case(cmd_table, input));
	return (st_fill_command(cmd_table, input));
}

static int	st_special_case(t_cmd_table **cmd_table, t_token *input)
{
	int	len;

	input = input->next;
	len = st_find_size(input);
	if (len == 2)
	{
		input = input->next;
		return (st_fill_command(cmd_table, input));
	}
	else
	{
		(*cmd_table)->command->parsed = (char **)mem_calloc(2,
				sizeof(char *));
		if (!(*cmd_table)->command->parsed)
			return (FALSE);
		(*cmd_table)->command->parsed[0] = str_dup("(Invalid)");
		if (!(*cmd_table)->command->parsed[0])
			return (FALSE);
	}
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

static int	st_fill_command(t_cmd_table **cmd_table, t_token *input)
{
	int	i;
	int	len;

	len = st_find_size(input);
	(*cmd_table)->command->parsed = (char **)mem_calloc(len + 1, sizeof(char *));
	if (!(*cmd_table)->command->parsed)
		return (FALSE);
	i = -1;
	while (++i < len)
	{
		(*cmd_table)->command->parsed[i] = str_dup(input->value);
		input = input->next;
	}
	(*cmd_table)->command->io[0] = 0;
	(*cmd_table)->command->io[1] = 1;
	return (TRUE);
}
