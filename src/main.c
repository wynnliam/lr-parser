// Liam Wynn, 9/28/2020, LR Parser

#include <stdio.h>

#include "./grammar.h"

int main() {
	printf("Hello, world.\n");

	struct grammarsym* sym;
	construct_grammarsym(&sym, "E'", TYPE_EMPTY);
	print_grammarsym(sym);
	destruct_grammarsym(sym);
	return 0;
}
