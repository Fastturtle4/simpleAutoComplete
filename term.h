//Paul Barrett
//Project 3
//term.h

#ifndef TERM_H
#define TERM_H

#include <string>

class Term {

    public:
	//default constructor
	Term();

	//initialize the given query string and weight
	Term(std::string query, long weight);

	//compare 2 terms in descending order by weight
	//if t1 and t2 are in descending order by weight, return 1
	//if they are of the same weight, return 0;
	//otherwise, return -1
	static int compareByWeight(Term t1, Term t2);

	//compares first two terms in lexicographic order but using only
	//the first r characters of each entry query
	//if the first r characters of t1 and t2 are in lexicographic order, return 1 
	// if they are of the same r characters, return 0; 
	// otherwise, return -1
	static int compareByPrefix(Term t1,Term t2,int r);

	// define the operator “<” for Term class(as friend function)
	friend bool operator<(Term t1,Term t2);

	// define the operator “<<” for Term class(as friend function)
	// so that it can send the Term object directly to cout, in the following format:
	// the weight followed by a tab key, then followed by the query
	friend std::ostream& operator<<(std::ostream& out, const Term& t);

    private:
	std::string query;
	long weight;
};

#endif

