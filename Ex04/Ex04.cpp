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
		fscanf(infile, "%[^\n] ", title);
		jobType type;
		
		while(fscanf(infile,"%d", &type.OID) != EOF) {	
			fscanf(infile,"%d", &type.arrival);
			fscanf(infile,"%d", &type.duration);
			fscanf(infile,"%d", &type.timeout);
			aList.push_back( type );
		}//end while
		
		fclose(infile);
	}//end else
	return success;

} // end JobList::getAll


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


