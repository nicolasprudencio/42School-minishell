#include "libseas.h"

int	automaton_cmd_create(t_cmd_table **cmd_table, char *value);
static t_cmd_table	**st_find_last(t_cmd_table **cmd_table);

int	automaton_cmdt_create(t_pushdown_automaton *parse_bot,
		t_cmd_table **cmd_table, t_token *token)
{
	t_cmd_table	**temp;

	temp = st_find_last(cmd_table);
	if (parse_bot->current_state == 1)
	{
		if (!automaton_cmd_create(temp, token->value))
			return (FALSE);
	}
//	else if (parse_bot->current_state == 2)
		// add token to command
//	else if (parse_bot->current_state == 3)
		// create new pipe
//	else if (parse_bot->current_state == 4)
		// get input from heredoc
//	else if (parse_bot->current_state == 5)
		// input redirection
//	else if (parse_bot->current_state == 6)
		// output redirection
//	else if (parse_bot->current_state == 7)
		// output append
	return (TRUE);
}

int	automaton_cmd_create(t_cmd_table **cmd_table, char *value)
{
	if (!*cmd_table)
		*cmd_table = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
	else
	{
		(*cmd_table)->next = (t_cmd_table *)mem_calloc(1,
				sizeof(t_cmd_table));
		*cmd_table = (*cmd_table)->next;
	}
	if (!*cmd_table)
		return (FALSE);
	(*cmd_table)->command = (t_command *)mem_calloc(1, sizeof(t_command));
	if (!(*cmd_table)->command)
		return (FALSE);
	(*cmd_table)->command->parsed = (char **)mem_calloc(2, sizeof(char *));
	if (!(*cmd_table)->command->parsed)
		return (FALSE);
	(*cmd_table)->command->parsed[0] = str_dup(value);
	if (!(*cmd_table)->command->parsed[0])		
		return (FALSE);
	(*cmd_table)->command->io[0] = 0;
	(*cmd_table)->command->io[1] = 1;
	printf("\t\t  | -----\033[1m New Command \033[0m-----\n");
	printf("\t\t  | cmd:\t%s\n",
			(*cmd_table)->command->parsed[0]);
	printf("\t\t  | io :\t%-5i\t%-5i\n", (*cmd_table)->command->io[0],
			(*cmd_table)->command->io[1]);
	return (TRUE);
}

static t_cmd_table	**st_find_last(t_cmd_table **cmd_table)
{
	while  (*cmd_table && (*cmd_table)->next)
		*cmd_table = (*cmd_table)->next;
	return (&(*cmd_table));
}
