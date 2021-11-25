#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include "JobList.hpp" // type jobType, class JobList
#include "JobQueue.hpp" // class JobQueue
#include "AnsList.hpp" // class AnsList
#include "Simulation.hpp" // class Simulation

#define MAX_LEN 255 

using namespace std;

int getM();

bool JobList::getSorted() {
	FILE *infile = NULL;
	
	string fileName;
	bool success = false ;
	cin >> fileName;
	fileID = fileName;

	fileName = "input"+fileName+".txt";
	infile = fopen(fileName.c_str(), "r");
	
	if (infile == NULL)
		cout<<endl<<fileName<<"does not exist!"<<endl ;
	else {	
	
		fscanf(infile, "%*[^\n]\n"); // remove title
		
		jobType job;
		
		while(fscanf(infile,"%d", &job.OID) != EOF) {	
			fscanf(infile,"%d", &job.arrival);
			fscanf(infile,"%d", &job.duration);
			fscanf(infile,"%d", &job.timeout);
			aList.push_back( job );
		}//end while
		
		sortByArrival();
		putAll();
		
		fclose(infile);
		
		success = true;
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
		
		success = true;
	}//end else
	return success;

} // end JobList::getAll

void JobList::nextJob(jobType &nextJob) { // get the next job then remove it
	nextJob = aList.front();
	aList.erase(aList.begin());
} // end JobList::nextJob

void JobList::showJob() { // show the job list 
	cout << "        OID     Arrival Duration        TimeOut\n";

	for ( int i = 0 ; i < aList.size() ; i++ ) {
		cout << '(' << i + 1 << ')' << "     ";
		cout << aList[i].OID << "     " << aList[i].arrival << "     ";
		cout << aList[i].duration << "     " << aList[i].timeout << endl;
	} // end for
} // end JobList::showJob

void JobList::putAll() { // show the job list 
	FILE *outfile = NULL;
	string filename = "sorted"+fileID+".txt";
	outfile = fopen(filename.c_str(), "a");
	fprintf(outfile, "%s", "OID	Arrival	Duration	TimeOut\n" );
	for ( int i = 0 ; i < aList.size() ; i++ ) {
		fprintf(outfile, "%d %d %d %d", aList[i].OID, aList[i].arrival, aList[i].duration, aList[i].timeout );
		fprintf(outfile, "%c", '\n');
	} // end for

   	fclose(outfile);
} // end JobList::putAll

void AnsList::putAll( string fileName, string test ) { // show the job list 
	FILE *outfile = NULL;
	string filename = "output"+fileName+".txt";
	outfile = fopen(filename.c_str(), "a");
	fprintf(outfile, "%s", "OID	Arrival	Duration	TimeOut\n" );


   	fclose(outfile);
} // end AnsList::putAll

void AnsList::showAll() { // show the job list 
	cout << "        OID     Arrival Duration        TimeOut\n";
} // end AnsList::showAll

void AnsList::addDoneJob( int OID, int arrival, int duration, int cpuTime ) { // show the job list 
	doneType job;
	job.OID = OID, job.departure = cpuTime+duration, job.delay = cpuTime - arrival;
	doneJobs.push_back(job);
} // end AnsList::addDoneJob

void AnsList::addAbortJob( int OID, int arrival, int timeout, int cpuTime ) { // show the job list 
	abortType job;
	job.OID = OID, job.abort = cpuTime, job.delay = cpuTime - arrival;
	abortJobs.push_back(job);
} // end AnsList::addAbortJob

void Simulation::SQF() { // shortest queue first

	allQ = new JobQueue<jobType> * [qNum]; // create qNum of cpu
	for (size_t i = 0; i < qNum; i++) { // create queue for each cpu                       
        allQ[i] = new JobQueue<jobType>(3);                                                                     
    } // end for
    
    
} // end Simulation::SQF

int main(void) {
	int command = 0;
	
	do
	{	
		JobList jobs;
		cout<<endl<<"*Arithmetic Expression Evaluator*";
		cout<<endl<<"*0.QUIT                         *";
		cout<<endl<<"*1.Sort Job List                *";
		cout<<endl<<"*2.Queue Job List               *";
		cout<<endl<<"*********************************";
		cout<<endl<<"Input a choice(0,1,2) : ";
		command = getM();
		cin.ignore(MAX_LEN, '\n');
		switch(command)
		{	case 0:break;
			case 1:cout<<endl<<"Input a file : ";
				if(jobs.getSorted())jobs.showJob();
				break;
			
			case 2:cout<<endl<<"Input a file : ";
				if(jobs.getAll()) {
					Simulation cpu( jobs, 1 );
					// cpu.SQF();
				} // end if
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


