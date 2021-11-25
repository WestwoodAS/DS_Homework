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
	void sortByArrival(){
        int gap = 0;
        jobType temp;
        gap = aList.size() / 2 ;
        while( gap > 0 ) {
            for( int k = 0 ;  k < gap ; k++ ) {

                for( int i = k+gap ; i < aList.size() ; i = i+gap ) {
                    for( int j = i-gap ; j >= k ; j = j-gap) {
                        if( aList[j].arrival > aList[j+gap].arrival  ) {
                            temp = aList[j];
                            aList[j] = aList[j+gap];
                            aList[j+gap] = temp;
                        } // end if
                        else if ( aList[j].arrival == aList[j+gap].arrival ) {
                        	if ( aList[j].OID > aList[j+gap].OID ) {
                        		temp = aList[j];
	                            aList[j] = aList[j+gap];
	                            aList[j+gap] = temp;
							} // end if
						} // end else if
                    } // end for
                } // end for
            } // end for

            gap = gap / 2 ;

        } // end while

    }//end of sortByArrival
	void putAll(); // write all as a file
	void showTime(); // output time on screen
	void nextJobCheck(jobType &nextJob) { nextJob = aList.front(); } // get the next job without removal
	
public:
	JobList(){ reset(); }
	~JobList() { reset(); }
	
	bool isEmpty() { return aList.empty(); } // check if it is empty

	bool getAll(); // read all from a file;
	bool getSorted(); // read all from a file and sort them
	void showJob(); // show job on screen
	void nextJob(jobType &); // get and remove the next job
	
}; // end JobList
#endif //_JobLIST_HPP
