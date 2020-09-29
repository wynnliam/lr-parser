// Liam Wynn, 9/28/2020, LR Parser

#include <stdio.h>

#include "./grammar.h"

int main() {
	struct grammarsym* f;
	struct grammarsym *op, *e, *cp;

	struct production* f_prod;

	construct_grammarsym(&f, "F", TYPE_NONTERMINAL);
	construct_grammarsym(&op, "(", TYPE_TERMINAL);
	construct_grammarsym(&e, "E", TYPE_NONTERMINAL);
	construct_grammarsym(&cp, ")", TYPE_TERMINAL);

	construct_production(&f_prod, f);
	add_rightside(f_prod, op);
	add_rightside(f_prod, e);
	add_rightside(f_prod, cp);

	print_production(f_prod);

	destruct_production(f_prod);
	return 0;
}
