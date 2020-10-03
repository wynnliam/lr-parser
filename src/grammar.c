// Liam Wynn, 9/29/2020, LR Parser

#include "./grammar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct production* productions[MAX_PRODUCTIONS];
unsigned int num_productions = 0;

/* GRAMMAR SYMBOL OPERATIONS */

int construct_grammarsym(struct grammarsym** result, const char* str, const int type) {
	if(!result)
		return 0;

	if((type == TYPE_NONTERMINAL || type == TYPE_NONTERMINAL) && !str) {
		*result = NULL;
		return 0;
	}

	*result = (struct grammarsym*)malloc(sizeof(struct grammarsym));
	(*result)->type = type;

	if(type == TYPE_NONTERMINAL || type == TYPE_TERMINAL) {
		char* result_str = (char*)malloc(strlen(str) + 1);
		strcpy(result_str, str);
		(*result)->str = result_str;
	} else {
		// str representation doesn't matter in this case.
		(*result)->str = NULL;
	}

	return 1;
}

int grammarsym_equals(struct grammarsym* a, struct grammarsym* b) {
	if(!a || !b)
		return 0;

	if((a->type == TYPE_EMPTY && b->type == TYPE_EMPTY) ||
	   (a->type == TYPE_END && b->type == TYPE_END))
	{
		return 1;
	}

	else {
		return a->type == b->type && strcmp(a->str, b->str) == 0;
	}
}

void print_grammarsym(struct grammarsym* to_print) {
	if(!to_print)
		return;

	int temp_type = to_print->type;

	if(temp_type == TYPE_EMPTY) {
		printf("e");
	} else if(temp_type == TYPE_END) {
		printf("$");
	} else {
		if(!to_print->str)
			return;
		else
			printf("%s", to_print->str);
	}

}

int destruct_grammarsym(struct grammarsym* sym) {
	if(!sym)
		return 0;

	if(sym->type == TYPE_TERMINAL || sym->type == TYPE_NONTERMINAL) {
		if(sym->str)
			free(sym->str);
		else
			return 0;
	}

	free(sym);

	return 1;
}

/* PRODUCTION OPERATIONS */
int construct_production(struct production** result, struct grammarsym* leftside) {
	if(!leftside) {
		*result = NULL;
		return 0;
	}

	struct production* temp_result = (struct production*)malloc(sizeof(struct production));
	temp_result->leftside = leftside;

	int i;
	for(i = 0; i < MAX_RIGHTSIDE; i++)
		temp_result->rightside[i] = NULL;
	temp_result->rightside_len = 0;

	*result = temp_result;
	return 1;
}

int add_rightside(struct production* prod, struct grammarsym* right) {
	if(!prod || !right)
		return 0;

	if(prod->rightside_len >= MAX_RIGHTSIDE)
		return 0;

	prod->rightside[prod->rightside_len] = right;
	prod->rightside_len += 1;

	return 1;
}

void print_production(struct production* prod) {
	if(!prod || !prod->leftside || prod->rightside_len < 1)
		return;

	print_grammarsym(prod->leftside);
	printf(" -> ");

	unsigned int i;
	for(i = 0; i < prod->rightside_len; i++)
		print_grammarsym(prod->rightside[i]);

	printf("\n");
}

int destruct_production(struct production* prod) {
	if(!prod)
		return 0;

	if(prod->leftside)
		destruct_grammarsym(prod->leftside);

	int i;
	for(i = 0; i < prod->rightside_len; i++)
		destruct_grammarsym(prod->rightside[i]);

	free(prod);
	return 1;
}
