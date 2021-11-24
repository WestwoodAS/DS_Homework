#ifndef _JobLIST_HPP
#define _JobLIST_HPP

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<ctime>

typedef struct jT {
	int OID; // order identifier
	int arrival;
	int duration; 
	int timeout; // expire time
} jobType; 

class JobList {
	vector<jobType> aList;
	string fileID;
	
	void reset() {
	
	
	} // end reset
	void showJob(jobType &);
	void sortByArrival();
	void putAll();
	void showTime();
	void nextJobCheck(jobType &); // get the next job without removal
	
public:
	JobList(){ reset(); }
	~JobList() { reset(); }
	
	bool isEmpty(); // check if it is empty

	bool getAll(string); // read all from a file;
	bool getSorted(); // read all from a file and sort them
	void nextJob(jobType &) // get and remove the next job
}; // end JobList
#endif //_JobLIST_HPP