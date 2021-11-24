#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include "JobList.hpp" // type jobType, class JobList
//#include "JobQueue.hpp" // class JobQueue
//#include "AnsList.hpp" // class AnsList
//#include "Simulation.hpp" // class Simulation

#define MAX_LEN 255 

using namespace std;

int getM();

bool JobList::getSorted() {
	FILE *infile = NULL;
	
	string fileName;
	bool success = false ;
	cin >> fileName;

	fileName = "input"+fileName+".txt";
	infile = fopen(fileName.c_str(), "r");
	
	if (infile == NULL)
		cout<<endl<<fileName<<"does not exist!"<<endl ;
	else {	
	
		char *title = (char*)malloc(sizeof(char));
		fscanf(infile, "%[^\n] ", title); // remove title
		
		jobType job;
		
		while(fscanf(infile,"%d", &job.OID) != EOF) {	
			fscanf(infile,"%d", &job.arrival);
			fscanf(infile,"%d", &job.duration);
			fscanf(infile,"%d", &job.timeout);
			aList.push_back( job );
		}//end while
		
		showJob();
		
		fclose(infile);
	}//end else
	return success;

} // end JobList::getSorted

bool JobList::getAll() {
	FILE *infile = NULL;
	
	string fileName;
	bool success = false ;
	cin >> fileName;

	fileName = "sorted"+fileName+".txt";
	infile = fopen(fileName.c_str(), "r");
	
	if (infile == NULL)
		cout<<endl<<fileName<<"does not exist!"<<endl ;
	else {	
	
		char *title = (char*)malloc(sizeof(char));
		fscanf(infile, "%[^\n] ", title); // remove title
		
		jobType job;
		
		while(fscanf(infile,"%d", &job.OID) != EOF) {	
			fscanf(infile,"%d", &job.arrival);
			fscanf(infile,"%d", &job.duration);
			fscanf(infile,"%d", &job.timeout);
			aList.push_back( job );
		}//end while
		
		fclose(infile);
	}//end else
	return success;

} // end JobList::getAll

void JobList::nextJob(jobType &nextJob) { // get the next job then remove it
	nextJob = aList.front();
	aList.erase(aList.begin());
} // end JobList::nextJob

void JobList::showJob() { // show the job list 
	for ( int i = 0 ; i < aList.size() ; i++ ) {
		cout << aList[i].OID << ' ' << aList[i].arrival << ' ';
		cout << aList[i].duration << ' ' << aList[i].timeout << endl;
	} // end for
} // end JobList::nextJob


int main(void) {
	int command = 0;
	
	do
	{	
		JobList jobs;
		cout<<endl<<"*Arithmetic Expression Evaluator*";
		cout<<endl<<"*0.QUIT                         *";
		cout<<endl<<"*1.Infix2postfix Evaluation     *";
		cout<<endl<<"*********************************";
		cout<<endl<<"Input a choice(0,1) : ";
		command = getM();
		cin.ignore(MAX_LEN, '\n');
		switch(command)
		{	case 0:break;
			case 1:cout<<endl<<"Input a file : ";
				jobs.getSorted();
				break;
			default:cout<<endl<<"Command does not exist!"<<endl;
			 
		}//end switch
	}while(command != 0);
	
	system("pause");
	return 0;
}//end main

int getM() {
	// get a number from user
	
	int temp;
	string inputS;
	bool isNum;
	
	do {
		
		cin >> inputS;
		isNum = true;
		
		for ( int i = 0 ; ( i < inputS.length() ) && ( isNum ) ; i++ ) {
			if ( ( inputS[i] > '9' ) || ( inputS[i] < '0' ) ) isNum = false;
		} // for
		
		if( !isNum ) {
			cout<<endl<<"Wrong Command! Please try again. : ";
			continue;	
		} // end if
		temp = strtoul( inputS.c_str(), NULL, 10 );
		
		if ( isNum  ) break;
	
	} while(true);

	return temp;
} // end getM


