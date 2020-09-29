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

/*
	PRECONDITIONS:
		- a, b properly initialized
	POSTCONDITIONS:
		- N/A
	SIDE-EFFECTS:
		- N/A
	RETURNS:
		- 1 is a, b are equal.
		- 0 otherwise.
	NOTES:
		- Equality defined as follows:
			- empty and empty is equal
			- end and end is equal
			- otherwise, types and str must be equal.
		- If either a or b are null, we return 0.
		- Besides null-checking, no other error checking is done.
*/
int grammarsym_equals(struct grammarsym* a, struct grammarsym* b);

/*
	PRECONDITIONS:
		- N/A, technically. But for anything interesting, you need a 
		valid grammarsym
	POSTCONDITIONS:
		- N/A
	SIDE-EFFECTS:
		- if grammarsym is not null, we print the appropriate symbol.
		- Otherwise, N/A
	RETURNS:
		- N/A
	NOTES:
		- If type is terminal or nonterminal, please make sure the str
		is valid. Otherwise it will not print.
*/
void print_grammarsym(struct grammarsym* to_print);

/*
	PRECONDITIONS:
		- sym is properly constructed (see notes).
	POSTCONDITIONS:
		- Sym will be free'd
	SIDE-EFFECTS:
		- N/A
	RETURNS:
		- 1 if free'd properly
		- 0 otherwise.
	NOTES:
		- If sym is NULL we return 0. No free will happen.
		- If type is nonterminal or terminal, and str is null, no free happens (returns 0).
*/
int destruct_grammarsym(struct grammarsym* sym);

#endif
