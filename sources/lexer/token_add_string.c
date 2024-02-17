#include "libseas.h"

static char	*st_copy_no_quotes(char *line, int hold);

int	token_add_string(t_token **tokens, char *line)
{
	int		hold;
	char	*content;

	hold = -1;
	if (str_is_enclosed(line, '\"') != FALSE_INDEX)
		hold = str_is_enclosed(line, '\"');
	else if (str_is_enclosed(line, '\'') != FALSE_INDEX)
		hold = str_is_enclosed(line, '\'');
	else
		while (line[++hold] && !is_space(line[hold]))
			;
	content = st_copy_no_quotes(line, hold);
	if (!content)
		return (FALSE_INDEX);
	token_push_last(tokens, token_new(content, "<STRING>"));
	free(content);
	return (hold);
}

static char	*st_copy_no_quotes(char *line, int hold)
{
	char	*output;
	int		i;
	int		j;

	if (str_is_enclosed(line, '\'') != FALSE_INDEX || 
			str_is_enclosed(line, '\"') != FALSE_INDEX)
		hold -= 2;
	else if (line[0] == '\'' || line[0] == '\"')
		hold -= 1;
	else if (line[hold] == '\'' || line[hold] == '\"')
		hold -= 1;
	output = (char *)mem_calloc(hold + 1, sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	if (line[0] == '\'' || line[0] == '\"')
		i++;
	while (j < hold && line[i] != '\'' && line[i] != '\"')
		output[j++] = line[i++];
	return (output);
}
