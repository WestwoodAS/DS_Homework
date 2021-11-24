#ifndef _AnsList_HPP
#define _AnsList_HPP

class AnsList{ 
	typedef struct aT {
		int OID;
		int abort; // abort time
		int delay;
	} abortType;
	
	typedef struct dT {
		int OID;
		int departure; // departure time
		int delay;
	} doneType;
	vector<abortType> abortJobs;
	vector<doneType> doneJobs;
	float avgDelay; // average of delay
	float successRate; // percentage of done jobs
	
	void showAbortJobs(string); // display abort jobs on screen
	void showDoneJobs(string); // display done jobs on screen 
	void computeStat(); // compute the statistics
	void showStat(); // display statistics on screen
	
public:
	AnsList():avgDelay(0,0), successRate(0,0) { // constructor for initialzation
		abortJobs.clear();
		doneJobs.clear();
	} // end AnsList
	~AnsList() {
		abortJobs.clear();
		doneJobs.clear();
	} // destructor for initialzation
	void showAll(string);
	void addAbortJob( int, int, int, int ); // add one aborted job
	void addDoneJob( int, int, int, int ); // add one done job
	
	void putAll( string, string ); // write all as a file
}; // end AnsList
#endif // _AnsList_HPP
