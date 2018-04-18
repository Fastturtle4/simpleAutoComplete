//Paul Barrett
//Project 3
//term.cpp


#include "term.h"
#include <iostream>

//default constructor
Term::Term(){
	query = "";
	weight = 0;
}

//initialize the given query string and weight
Term::Term(std::string query, long weight){
	if(weight < 0){
		std::cout << "Weight must be a positive number." << std::endl;
		weight = 0;
	} else {
		this->query = query;
		this->weight = weight;
	}
}

//compare 2 terms in descending order by weight
//if t1 and t2 are in descending order by weight, return 1
//if they are of the same weight, return 0;
//otherwise, return -1
int Term::compareByWeight(Term t1, Term t2){
	if(t1.weight > t2.weight){
		return 1;
	} else if (t1.weight == t2.weight) {
		return 0;
	} else {
		return -1;
	}
}

//compares first two terms in lexicographic order but using only
//the first r characters of each entry query
//if the first r characters of t1 and t2 are in lexicographic order, return 1
//if they are of the same r characters, return 0;
// otherwise, return -1
int Term::compareByPrefix(Term t1,Term t2,int r){
	std::string term1r = t1.query.substr(0,r);
	std::string term2r = t2.query.substr(0,r);
	if(r < 0) {
		std::cout << "The length of the prefix should be a positive number!" << std::endl;
	}
	if(term1r < term2r){
		return 1;
	} else if (term1r == term2r) {
		return 0;
	} else {
		return -1;
	}
}

// define the operator “<” for Term class(as friend function)
bool operator<(Term t1,Term t2){
	if(t1.query < t2.query){
		return true;
	} else {
		return false;
	}
}

// define the operator “<<” for Term class(as friend function)
// so that it can send the Term object directly to cout, in the following format:
// the weight followed by a tab key, then followed by the query
std::ostream& operator<<(std::ostream& out, const Term& t){
	out << t.weight << "\t" << t.query;
	return out;
}


