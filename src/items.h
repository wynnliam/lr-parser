// Liam Wynn, 11/3/2020, LR Parser

/*
	Stores all procedures and structures for defining
	the sets of items construction. This is important
	for computing the overall parsing table itself.

	A set of items essentially says "supposing we've
	read some amount of string, how much of that corresponds
	to a given productions?"

	For example. Suppose I have the following grammar

	S -> BB
	B -> aB | b

	And I have the input string: "aab". Then, I read in
	the first 'a'. My stack and input buffer look like this:

	stack	|	input buffer
	------------------------
	  a		|		ab
	------------------------

	So looking at this, compare it to B -> aB.

	We've read in an a, so we can mark that with the following
	item:

	B -> a . B

	the '.' tells you how much of the production you've read,
	and how much you expect to see. So in our case, we can see
	it as "I have read in an 'a', and I can expect to see a string
	deriavable from B."

	Formally, an item is a production and a dot denoting how much
	of said production we've seen thus far.

	So what can we do with these items? In broad stroaks, these
	items are used to construct a DFA for viable prefixes. Viable
	prefixes are any prefixes of a right sentential form (a string
	of grammar symbols derived from only doing right-most productions)
	that can appear on the input stack. Collections of items are the states,
	and the viable prefixes are the things we use to transition between states.
	We employ two operations for this: closure, which builds our collection
	of sets of items; and goto, which defines how we go from one collection
	of items to another given what we've seen already and what we are seeing now.

	Now, what are "collections of items"? Basically, given a single item, we
	compute a closure on that. This will return every item we could potentially
	derive from that one. Going back to our example:

	S' -> S
	S -> B
	B -> aB
	B -> b

	Given item S' -> . S, our closure would be:

	S' -> . S
	S -> . B
	B -> . aB
	B -> . b

	This is one set of items. As we are constructing these sets of items,
	we build our DFA of viables prefixes using an operation called "goto".

	TODO: Define goto more

	It must be emphasized - this DFA is NOT the parser itself! The DFA
	is ultimately used to build the parsing table. Please see parser.h
	for more.
	
*/

