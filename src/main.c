// Liam Wynn, 9/28/2020, LR Parser

#include <stdio.h>

#include "./globals.h"
#include "./grammar.h"
#include "./first.h"

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

	printf("FIRST('(') = { ");
	struct grammarsym* first_open[MAX_FIRST];
	int result_first = first_single_grammarsym(op, first_open);

	int i;
	for(i = 0; i < result_first; i++) {
		print_grammarsym(first_open[i]);
	}

	printf(" }\n");

	destruct_production(f_prod);
	return 0;
}
