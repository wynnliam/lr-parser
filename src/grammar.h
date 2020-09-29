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

#endif
