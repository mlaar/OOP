#ifndef TQUEUE_H
#define TQUEUE_H

#include "Trapeze.h"
#include "TQueueItem.h"

class TQueue {
public:
	TQueue();
	TQueue(const TQueue& orig);

	void Push(Trapeze &&trapeze);
	bool Empty();
	Trapeze Pop();
	friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
	virtual ~TQueue();
private:
	TQueueItem *head;
	TQueueItem *last;
};

#endif