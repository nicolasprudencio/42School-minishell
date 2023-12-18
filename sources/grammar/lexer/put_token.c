#include "libseas.h"

void	put_token(t_token *tokens)
{
	while (tokens)
	{
		fp_printf("%15s | %s\n", tokens->token_type,
				tokens->value);
		tokens = tokens->next;
	}
}
