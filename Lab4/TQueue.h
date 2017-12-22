#ifndef TQUEUE_H
#define TQUEUE_H

#include "Trapeze.h"
#include "Pentagon.h"
#include "Rhombus.h"
#include "TQueueItem.h"
#include <memory>

template <class T> class TQueue {
public:
	TQueue();
	TQueue(const TQueue& orig);

	void Push(std::shared_ptr<T> &&item);
	bool Empty();
	std::shared_ptr<T> Pop();
	template <class A>friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
	virtual ~TQueue();
private:
	std::shared_ptr<TQueueItem<T>> head;
	std::shared_ptr<TQueueItem<T>> last;
};

#endif