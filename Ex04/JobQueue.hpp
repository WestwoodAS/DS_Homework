#ifndef _JobQueue_HPP
#define _JobQueue_HPP

template< typename T >
class JobQueue {
	T *cA;
	int qFront, qBack;
	int qSize, qMax;
	
	int next( int idx ) { return  ((idx + 1 ) % qMax); } // move to next pos
	int prev( int idx ) { return (( idx + qMax - 1 ) % qMax); } // move to previous pos

public:
	int avail;
	JobQueue():cA(NULL), qFront(0), qBack(0), 
		qSize(0), qMax(0), avail(0) {} // constructor of no-space queue
		
	JobQueue<T>( int maxS ):qFront(0), qSize(0), avail(0) {
		cA = new T [maxS];
		qMax = maxS;
		qBack = maxS - 1;
	} // end constructor
	
	int length() const { return qSize; } // return current queue length
	int isEmpty() const { return (qSize == 0); } // check if queue is empty
	int isFull() const { return (qSize == qMax); } // check if queue is empty
	
	void enQueue( T &newItem ) { // append a new element
		qSize++; // increase queue length
		qBack = next(qBack); // locate this last element
		cA[qBack] = newItem; // call by reference
	} // end enQueue

	void getFront( T &oldItem ) const { oldItem = cA[qFront]; } // get the first element
	void deQueue() { // drop the first element
		qSize--; // decrease queue size
		qFront = next(qFront); // locate the first element
	} // end deQueue
	
	void deQueue( T &oldItem ) { // get then drop the first element
		getFront(oldItem);
		deQueue();
 	} // end deQueue
	
	void clearQ() { // clean queue
		while( !isEmpty() ) deQueue();
		delete [] cA;
		cA = NULL;
	} // end clearQ
	
	~JobQueue() { clearQ(); } // destructor
	
}; // end JobQueue
#endif //_JobQueue_HPP
