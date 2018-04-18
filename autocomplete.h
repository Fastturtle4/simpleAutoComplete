//Paul Barrett
//Project 3
//autocomplete.h

#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "term.h"
#include "SortingList.h"

class Autocomplete {

    public:
	// insert the newterm to the sequence 
	void insert(Term newterm);

	// return all terms whose queries match the given prefix, 
	// in descending order by weight
	SortingList<Term> allMatches(string prefix);

	// first: the index of the first query whose prefix matches
	//        the search key, or -1 if no such key
	// last: the index of the last query whose prefix matches
	//       the search key, or -1 if no such key
	// key: the given prefix to match
	void search(string key, int& first, int& last);

	// return the index number of the term whose query 
	// prefix-matches the given prefix, using binary search algorithm
	// Note that binary search can only be applied to sorted sequence
	// Note that you may want a binary search helper function
	int binary_search(string prefix);

	// display all the terms
	void print();

    private:
	// choose your own data structure to represent the sequence of Term Objects
	SortingList<Term> terms;
};

#endif

