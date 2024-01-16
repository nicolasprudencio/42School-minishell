#include "libseas.h"

int	st_allocate_new(t_cmd_table **cmd_table, char *value);

int	automaton_cmd_create(t_cmd_table **cmd_table, char *value)
{
	t_cmd_table	*aux;
	t_cmd_table	*last_cmd;

	if (!*cmd_table)
	{
		*cmd_table = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
		if (!st_allocate_new(cmd_table, value))
			return (FALSE);
	}
	else
	{
		automaton_cmd_last(&last_cmd, cmd_table);
		aux = NULL;
		aux = (t_cmd_table *)mem_calloc(1, sizeof(t_cmd_table));
		if (!aux)
			return (FALSE);
		if (!st_allocate_new(&aux, value))
			return (FALSE);
		last_cmd->next = aux;
	}
	printf("\t\t  | -----\033[1m New Command \033[0m-----\n");
	printf("\t\t  | cmd:\t%s\n",
			(*cmd_table)->command->parsed[0]);
	printf("\t\t  | io :\t%-5i\t%-5i\n", (*cmd_table)->command->io[0],
			(*cmd_table)->command->io[1]);
	printf("\t\t  |\n");
	return (TRUE);
}

int	st_allocate_new(t_cmd_table **cmd_table, char *value)
{
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
	return (TRUE);
}
