//Paul Barrett
//Project 3
//main.cpp

#ifndef MAIN_CPP
#define MAIN_CPP

#include "autocomplete.h"
#include <fstream>
#include <sstream>

int main(int argc, char** argv){
	const int ARGUMENTS = 3;
	int resultnum = 0;
	
	//convert # of results to display to int and make sure > 0
	stringstream convert(argv[2]);
	convert >> resultnum;
	if(resultnum <= 0){
		cout << "You must enter a number > 0 of entries to view" << endl;
		return -1;
	}
	
	//make sure right # of args and read file
	if(argc != ARGUMENTS){
		cout << "Usage: " << argv[0] << " <filename> <# of results to display>" << endl;
		return 1;
	}

	ifstream infile;
	infile.open(argv[1]);
	if(!infile.good()){
		cout << "Cannot open the file name " << argv[1] << endl;
		return 2;
	}
	
	//read from file into dataList
	Autocomplete dataList;
	long weight;
	string query;
	
	while(infile >> weight){
		infile >> ws;
		getline(infile, query);
		if(query != ""){
			Term newterm(query, weight);
			dataList.insert(newterm);
		}
	}

	infile.close();
	
	//ask user for search query and store in prefix
	string prefix;
	cout << "Please input the search query (type \"exit\" to quit: " << endl;
	getline(cin, prefix);
	int flippy = 0;
	
	//looping menu asks for prefix and shows results
	while(prefix != "exit"){
		//find all matches, check if none found
		SortingList<Term> matchedTerms = dataList.allMatches(prefix);
		if (matchedTerms.size() == 0)
			cout << "No matches found!" << endl;
		else {
			//if # results < # requested, tell user and display most results possible
			SortingList<Term> results;
			if(resultnum > matchedTerms.size()){
				cout << "Only " << matchedTerms.size() << " terms found: " << endl;
				resultnum = matchedTerms.size();
				flippy = 1;//switch tells to update resultnum back to original value if needed
			}
			//insert resultnum # of results into result list
			for(int i = 0; i < resultnum; i++){
				results.insert(matchedTerms[i]);
			}
			//reset result num if changed earlier
			if(flippy == 1){
				stringstream convert(argv[2]);
       	 			convert >> resultnum;
				flippy = 0;
			}
			//print results
			results.print();
		}
		//ask for new search query from user
		cout << "Please input the search query (type \"exit\" to quit: " << endl;
		getline(cin, prefix);
	}		
	return 0;
}

#endif
