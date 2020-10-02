// Liam Wynn, 10/2/2020, LR Parser

#include "./first.h"

int first_single_grammarsym(struct grammarsym* sym, struct grammarsym* result[MAX_FIRST]) {
	if(!sym)
		return 0;

	// Symbol type is a terminal of some kind. According to rule 1, we just add
	// sym to the result.
	if(sym->type == TYPE_TERMINAL || sym->type == TYPE_EMPTY || sym->type == TYPE_END) {
		result[0] = sym;
		return 1;
	}

	return 0;
}
