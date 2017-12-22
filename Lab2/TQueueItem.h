#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H

#include "Trapeze.h"

class TQueueItem {
public:
	TQueueItem(const Trapeze& trapeze);
	TQueueItem(const TQueueItem& orig);
	friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

	TQueueItem* SetNext(TQueueItem* next);
	TQueueItem* GetNext();
	Trapeze GetTrapeze() const;

	virtual ~TQueueItem();
private:
	Trapeze trapeze;
	TQueueItem *next;
};

#endif