#include "so_long.h"

int main(void)
{
	char *twoDArray[] = {
   		"11111",
   		"11111",
   		"11111",
		NULL
	};
	printf("%d\n", has_walls(twoDArray));
}