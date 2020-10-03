// Liam Wynn, 10/2/2020, LR Parser

#include "./first.h"
#include "./grammar.h"

// TODO: Does not handle recursion. May be a problem.

static int first_single_grammarsym_nonterm(struct grammarsym* sym, struct grammarsym* result[MAX_FIRST]) {
	int total_len = 0;

	// We need to search all productions where right side is sym:
	int i;
	for(i = 0; i < num_productions; i++) {
		if(!grammarsym_equals(sym, productions[i]->leftside))
			continue;

		// This will build FIRST(sym) according to rule 3.
		int j;
		for(j = 0; j < productions[i]->rightside_len; j++) {
			// Easy way to handle immediate recursion.
			if(grammarsym_equals(sym, productions[i]->rightside[j]))
				continue;

			struct grammarsym* curr_result[MAX_FIRST];
			int curr_len = first_single_grammarsym(productions[i]->rightside[j], curr_result);

			int k = 0;
			while(total_len < MAX_FIRST && k < curr_len) {
				// Only add the grammar sym if it is not in result
				int l;
				int should_add = 1;
				for(l = 0; l < total_len; l++) {
					if(grammarsym_equals(curr_result[k], result[l])) {
						should_add = 0;
						break;
					}
				}

				if(should_add) {
					result[total_len] = curr_result[k];
					total_len++;
				}

				k++;
			}

			int keep_going = 0;
			struct grammarsym empty;
			empty.type = TYPE_EMPTY;
			// Now, if at this point we find no empty symbol,
			// then don't go to the next symbol in the production
			// because there is no way it can be in FIRST(sym).
			for(k = 0; k < curr_len; k++) {
				if(grammarsym_equals(&empty, curr_result[k])) {
					keep_going = 1;
					break;
				}
			}

			if(!keep_going)
				break;
		}
	}

	return total_len;
}

int first_single_grammarsym(struct grammarsym* sym, struct grammarsym* result[MAX_FIRST]) {
	if(!sym)
		return 0;

	// Symbol type is a terminal of some kind. According to rule 1, we just add
	// sym to the result.
	if(sym->type == TYPE_TERMINAL || sym->type == TYPE_EMPTY || sym->type == TYPE_END) {
		result[0] = sym;
		return 1;
	}

	else if(sym->type == TYPE_NONTERMINAL) {
		return first_single_grammarsym_nonterm(sym, result);
	}

	return 0;
}
