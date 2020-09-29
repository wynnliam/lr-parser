// Liam Wynn, 9/29/2020, LR Parser

#include "./grammar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print_grammarsym(struct grammarsym* to_print) {
	if(!to_print)
		return;

	int temp_type = to_print->type;

	if(temp_type == TYPE_EMPTY) {
		printf("e\n");
	} else if(temp_type == TYPE_END) {
		printf("$\n");
	} else {
		if(!to_print->str)
			return;
		else
			printf("%s\n", to_print->str);
	}

}
