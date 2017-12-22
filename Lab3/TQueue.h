#ifndef TQUEUE_H
#define TQUEUE_H

#include "Trapeze.h"
#include "Pentagon.h"
#include "Rhombus.h"
#include "TQueueItem.h"
#include <memory>

class TQueue {
public:
	TQueue();
	TQueue(const TQueue& orig);

	void Push(std::shared_ptr<Figure> &&figure);
	bool Empty();
	std::shared_ptr<Figure> Pop();
	friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
	virtual ~TQueue();
private:
	std::shared_ptr<TQueueItem> head;
	std::shared_ptr<TQueueItem> last;
};

#endif