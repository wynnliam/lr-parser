// Liam Wynn, 10/2/2020, LR Parser

/*
	Keeps track of all global variables the system
	will use.
*/

#ifndef GLOBALS
#define GLOBALS

#define TYPE_NONTERMINAL	0
#define TYPE_TERMINAL		TYPE_NONTERMINAL + 1
#define TYPE_EMPTY			TYPE_TERMINAL + 1
#define TYPE_END			TYPE_EMPTY + 1

#define MAX_RIGHTSIDE		10

/* GRAMMAR SYMBOL DEFINITIONS */

// A simple definition for a grammar symbol. This
// can be a non-terminal, terminal, or empty. Empty
// is also a terminal, but since it is a unique enough
// kind of terminal that warrants a distinct type.
struct grammarsym {
	char* str;
	int type;
};

#define MAX_PRODUCTIONS	10

/* PRODUCTION DEFINITIONS*/

/*
	Suppose leftside is A, and rightside is B, then
	this represents a single production of the form:

	A -> B

	Now, since a production can have a form like:

	A -> ( E )

	Which has three symbols, we make the rightside
	and array. Since this is a toy program, we'll limit
	the amount of symbols to 10.
*/
struct production {
	struct grammarsym* leftside;
	struct grammarsym* rightside[MAX_RIGHTSIDE];
	unsigned int rightside_len;
};

extern struct production* productions[];
extern unsigned int num_productions;

// Number of grammar symbols we can put into the FIRST result.
#define MAX_FIRST	100

// Definitions for items, and sets of items

#define MAX_ITEM_PER_SET	100

struct item {
	// Neccessary for cannonical LR parsers.
	// Used to refine set of states.
	struct grammarsym* lookahead;
	// Index into productions array.
	int production;
	// Index into rightside of productions[index].
	int position;
};

struct item_set {
	struct item* items[MAX_ITEM_PER_SET];
};

#endif
