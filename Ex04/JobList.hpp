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
	std::vector<jobType> aList;
	std::string fileID;
	
	void reset() {aList.clear();} // end reset
	void showJob();
	void sortByArrival();
	void putAll(); // write all as a file
	void showTime(); // output time on screen
	void nextJobCheck(jobType &nextJob) { nextJob = aList.front(); } // get the next job without removal
	
public:
	JobList(){ reset(); }
	~JobList() { reset(); }
	
	bool isEmpty() { return aList.empty(); } // check if it is empty

	bool getAll(); // read all from a file;
	bool getSorted(); // read all from a file and sort them
	void nextJob(jobType &); // get and remove the next job
	
}; // end JobList
#endif //_JobLIST_HPP
