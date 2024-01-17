#include "stdio.h"
#include "unistd.h"

int	main(void)
{
	printf("STDIN_FILENO: %i\n", STDIN_FILENO);
	printf("STDOUT_FILENO: %i\n", STDOUT_FILENO);
	return (0);
}
