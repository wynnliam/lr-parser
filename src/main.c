// Liam Wynn, 9/28/2020, LR Parser

#include <stdio.h>

#include "./globals.h"
#include "./grammar.h"
#include "./first.h"

int main() {
	struct grammarsym* e;
	construct_grammarsym(&e, "E", TYPE_NONTERMINAL);

	struct grammarsym* t;
	construct_grammarsym(&t, "T", TYPE_NONTERMINAL);

	struct grammarsym* e1;
	construct_grammarsym(&e1, "E'", TYPE_NONTERMINAL);

	struct grammarsym* plus;
	construct_grammarsym(&plus, "+", TYPE_TERMINAL);

	struct grammarsym* empty;
	construct_grammarsym(&empty, NULL, TYPE_EMPTY);

	struct grammarsym* f;
	construct_grammarsym(&f, "F", TYPE_NONTERMINAL);

	struct grammarsym* t1;
	construct_grammarsym(&t1, "T'", TYPE_NONTERMINAL);

	struct grammarsym* mult;
	construct_grammarsym(&mult, "*", TYPE_TERMINAL);

	struct grammarsym* open;
	construct_grammarsym(&open, "(", TYPE_TERMINAL);

	struct grammarsym* close;
	construct_grammarsym(&close, ")", TYPE_TERMINAL);

	struct grammarsym* id;
	construct_grammarsym(&id, "id", TYPE_TERMINAL);
	
	return 0;
}
