// Liam Wynn, 9/28/2020, LR Parser

#ifndef GRAMMARDEF
#define GRAMMARDEF

#define TYPE_NONTERMINAL	0
#define TYPE_TERMINAL		TYPE_NONTERMINAL + 1
#define TYPE_EMPTY			TYPE_TERMINAL + 1
#define TYPE_END			TYPE_EMPTY + 1

// A simple definition for a grammar symbol. This
// can be a non-terminal, terminal, or empty. Empty
// is also a terminal, but since it is a unique enough
// kind of terminal that warrants a distinct type.
struct grammarsym {
	char* str;
	int type;
};

/*
	PRECONDITIONS:
		- N/A
	POSTCONDITIONS:
		- result will point to a newly allocated
		grammarsym.
		- If construction fails (see notes), result
		will point to null.
	SIDE-EFFECTS:
		- N/A
	RETURNS:
		- 1 if construction operation was successful.
		- 0 if not
	NOTES:
		- Construction can fail if type is a terminal/nonterminal with
		NULL str.
		- If result doesn't point to anything, makesure it is set to NULL!
		otherwise there will be a segfault!
		- If type is niether terminal nor nonterminal, result's str is set to NULL
*/
int construct_grammarsym(struct grammarsym** result, const char* str, const int type);

void print_grammarsym(struct grammarsym* to_print);

#endif
