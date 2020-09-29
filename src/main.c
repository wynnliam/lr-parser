// Liam Wynn, 9/28/2020, LR Parser

#include <stdio.h>

#include "./grammar.h"

int main() {
	struct grammarsym* f;
	struct production* f_prod;

	construct_grammarsym(&f, "F", TYPE_NONTERMINAL);

	construct_production(&f_prod, f);
	return 0;
}
