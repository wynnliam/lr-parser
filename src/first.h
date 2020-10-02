// Liam Wynn, 9/29/2020, LR Parser

/*
	Stores all procedures related to computing
	the FIRST operation for a grammar symbol.

	Let a be a string of grammar symbols,
	then FIRST(a) is the set of terminals
	that begin the strings derived from a.

	Here's the rules for computing FIRST:

	1. If X is a single terminal FIRST(X) = {X}.

	2. If X -> e (empty) is a production, then
	add e to FIRST(X).

	3. If X is a nonterminal with a production
	X -> Y_1 Y_2 ... Y_k, then put a in FIRST(X)
	if for some i, a is in FIRST(Y_i) and e is in
	all of FIRST(Y_1), ..., FIRST(Y_(i-1)).
	If e is in FIRST(Y_j) for j = 1 ... k, add e
	to FIRST(X).

	Using these rules, you can compute the FIRST
	for a string of symbols Q = X_1 X_2 ... X_n as follows:
	Add all non-e symbols of FIRST(X_1) to FIRST(Q). Add
	all non-e symbols of FIRST(X_k) if e is in FIRST(X_1), ..., FIRST(X_(k-1)).
	Add e to FIRST(Q) if e is in all FIRST(X_i) (for i in 1 .. n).
*/

#ifndef FIRST
#define FIRST

#include "./globals.h"

/*
	Defines FIRST(X) for a single grammar symbol X.

	PRECONDITIONS:
		- sym is properly initialized and should be in globals productions
	POSTCONDITIONS:
		- Will fill result with all first grammar symbols according to rules.
	SIDE-EFFECTS:
		- None
	RETURNS:
		- The number of grammarsymbols in result.
	NOTES:
		- If sym is not in productions, the return value will be zero.
		- If sym is null, will also return 0.
*/
int first_single_grammarsym(struct grammarsym* sym, struct grammarsym* result[MAX_FIRST]);

#endif
