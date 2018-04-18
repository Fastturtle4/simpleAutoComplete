//Paul Barrett
//Project 3
//autocomplete.cpp

#include "autocomplete.h"

// insert the newterm to the sequence
void Autocomplete::insert(Term newterm)
{
	terms.insert(newterm);
}

// return all terms whose queries match the given prefix,
// in descending order by weight
SortingList<Term> Autocomplete::allMatches(std::string prefix)
{
	SortingList<Term> matches;
	int first;
	int last;
	search(prefix, first, last);
	if (first != -1 && last != -1){
		for(int i = first; i <= last; i++){
			matches.insert(terms[i]);
		}	
		matches.selection_sort(Term::compareByWeight);
	}
	return matches;
}

// first: the index of the first query whose prefix matches
//        the search key, or -1 if no such key
// last: the index of the last query whose prefix matches
//       the search key, or -1 if no such key
// key: the given prefix to match
void Autocomplete::search(std::string key, int& first, int& last)
{
	Term matchTerm(key, 0);
	int index = binary_search(key);
	int i = index;
	if(index != -1){
		while((Term::compareByPrefix(matchTerm, terms[i], key.length()) == 0) && i>=0){
                        first = i;
			i--;
        	}
		int k = index;
		while((Term::compareByPrefix(matchTerm, terms[k], key.length()) == 0) && i < terms.size()){
                        last = k;
			k++;
		}	
		first = i;
		last = k;
	} else {
		first = -1;
		last = -1;
	}
}

// return the index number of the term whose query
// prefix-matches the given prefix, using binary search algorithm
// Note that binary search can only be applied to sorted sequence
// Note that you may want a binary search helper function
int Autocomplete::binary_search(std::string prefix)
{
	int index = -1;
	terms.sort();
	Term matchTerm(prefix, 0);
	int R = terms.size();
	for(int L = 0; L < R; L++){
		if(L > R){
			std::cout << "Binary search failed" << std::endl;
			continue;
		}
		Term m = terms[((L+R)/2)];
		if(Term::compareByPrefix(m, matchTerm, prefix.length()) == 1){ //m < matchTerm
			L = ((L+R)/2) + 1;
		} else if (Term::compareByPrefix(m, matchTerm, prefix.length()) == -1){ //m > matchTerm
			R = ((L+R)/2) - 1;
		} else {
			index = (L+R)/2;
			continue;
		}
	}
	return index;
}

// display all the terms
void Autocomplete::print()
{
	terms.print();
}

