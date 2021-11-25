#ifndef _Simulation_HPP
#define _Simulation_HPP

#include "JobList.hpp" // type jobType, class JobList
#include "JobQueue.hpp" // class JobQueue
#include "AnsList.hpp" // class AnsList


class Simulation {
	JobList jobs; // a list of jobs
	AnsList answer; // a set of answers
	JobQueue<jobType> **allQ; // a set of queues
	int qNum; // number of queues
	
	void delQ(int); // delete an old job from a queue
	void updateQ(int,int); // update each queue
	void finishQ(); // finish the remaining jobs in queue
	
public:
	Simulation( JobList aList, int N ):jobs(aList),qNum(N) { // copy constructor
		delete allQ;
	} // end constructor
	
	~Simulation() { // destructor
		delete allQ;
	} // end destructor
	void SQF(); // shortest queue first

}; // end Simulation
#endif // _Simulation_HPP

