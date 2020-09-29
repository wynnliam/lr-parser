// Liam Wynn, 9/29/2020, LR Parser

#include "./grammar.h"
#include <stdlib.h>
#include <string.h>

int construct_grammarsym(struct grammarsym** result, const char* str, const int type) {
	if(!result)
		return 0;

	if((type == TYPE_NONTERMINAL || type == TYPE_NONTERMINAL) && !str)
		return 0;

	*result = (struct grammar*)malloc(sizeof(struct grammar));
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
