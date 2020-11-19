// Liam Wynn, 11/4/2020, LR Parser

#include "./items.h"
#include "./grammar.h"
#include <stdlib.h>
#include <stdio.h>

int construct_item(const int production, const int position, struct grammarsym* lookahead, struct item** result) {
	if(!result || !lookahead || production < 0 || production >= num_productions) {
		*result = NULL;
		return 0;
	}

	*result = (struct item*)malloc(sizeof(struct item));
	(*result)->production = production;
	(*result)->position = position;
	(*result)->lookahead = lookahead;

	return 1;
}

void print_item(struct item* dis) {
	if(!dis)
		return;

	struct production* p = productions[dis->production];

	print_grammarsym(p->leftside);
	printf(" -> ");

	unsigned int i;
	for(i = 0; i < p->rightside_len; i++) {
		if(i == dis->position)
			printf(".");

		print_grammarsym(p->rightside[i]);
	}

	if(i == dis->position)
		printf(".");

	printf("\n");
}

int compare_item(struct item* a, struct item* b) {
	if(!a || !b)
		return 0;
	else
		return a->production == b->production &&
			   a->position == b->position &&
			   a->lookahead == b->lookahead;
}

int is_valid_item(struct item* verify) {
	if(!verify)
		return 0;
	return 1;
}

void destruct_item(struct item* clear) {
	if(clear)
		free(clear);
}
