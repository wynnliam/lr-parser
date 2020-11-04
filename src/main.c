// Liam Wynn, 9/28/2020, LR Parser

#include <stdio.h>

#include "./globals.h"
#include "./grammar.h"
#include "./first.h"
#include "./items.h"

int main() {
	// Construct the grammar symbols
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

	// Now construct the productions
	struct production* e_prod;
	construct_production(&e_prod, e);
	add_rightside(e_prod, t);
	add_rightside(e_prod, e1);
	productions[num_productions] = e_prod;
	num_productions++;

	struct production *e1_prod1, *e1_prod2;
	construct_production(&e1_prod1, e1);
	add_rightside(e1_prod1, plus);
	add_rightside(e1_prod1, t);
	add_rightside(e1_prod1, e1);
	productions[num_productions] = e1_prod1;
	num_productions++;
	construct_production(&e1_prod2, e1);
	add_rightside(e1_prod2, empty);
	productions[num_productions] = e1_prod2;
	num_productions++;

	struct production* t_prod;
	construct_production(&t_prod, t);
	add_rightside(t_prod, f);
	add_rightside(t_prod, t1);
	productions[num_productions] = t_prod;
	num_productions++;

	struct production *t1_prod1, *t1_prod2;
	construct_production(&t1_prod1, t1);
	add_rightside(t1_prod1, mult);
	add_rightside(t1_prod1, f);
	add_rightside(t1_prod1, t1);
	productions[num_productions] = t1_prod1;
	num_productions++;
	construct_production(&t1_prod2, t1);
	add_rightside(t1_prod2, empty);
	productions[num_productions] = t1_prod2;
	num_productions++;

	struct production *f_prod1, *f_prod2;
	construct_production(&f_prod1, f);
	add_rightside(f_prod1, open);
	add_rightside(f_prod1, e);
	add_rightside(f_prod1, close);
	productions[num_productions] = f_prod1;
	num_productions++;
	construct_production(&f_prod2, f);
	add_rightside(f_prod2, id);
	productions[num_productions] = f_prod2;
	num_productions++;

	// Print productions
	printf("GRAMMAR: \n");
	print_production(e_prod);
	print_production(e1_prod1);
	print_production(e1_prod2);
	print_production(t_prod);
	print_production(t1_prod1);
	print_production(t1_prod2);
	print_production(f_prod1);
	print_production(f_prod2);

	struct grammarsym* grammar_str[2];
	grammar_str[0] = t;
	grammar_str[1] = e1;

	struct grammarsym* result[MAX_FIRST];
	int result_count = first_string_grammarsym(grammar_str, 2, result);
	printf("FIRST(TE) = ");
	int i;
	for(i = 0; i < result_count; i++)
		print_grammarsym(result[i]);

	printf("\n");

	struct item* my_item;
	construct_item(3, 2, e, &my_item);
	display_item(my_item);
	
	return 0;
}
