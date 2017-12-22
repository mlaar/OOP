#include "TQueue.h"
#include <iostream>

TQueue::TQueue() : head(nullptr), last(nullptr) {
}

TQueue::TQueue(const TQueue& orig) {
	head = orig.head;
	last = orig.last;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
	TQueueItem *item = queue.head;
	
	while(item!=nullptr)
	{
		os << *item;
		item = item->GetNext();
	}
	return os;
}

void TQueue::Push(Trapeze &&trapeze) {
	TQueueItem *other = new TQueueItem(trapeze);
	if (Empty())  {
		head = other;
		last = other;
	}
	else {
		last->SetNext(other);
		last = other;
	}
}

bool TQueue::Empty() {
	return head == nullptr;
}

Trapeze TQueue::Pop() {
	Trapeze result;
	if (head != nullptr) {
		TQueueItem *old_head = head;
		head = head->GetNext();
		result = old_head->GetTrapeze();
		old_head->SetNext(nullptr);
		delete old_head;
	}
	return result;
}

TQueue::~TQueue() {
	delete head;
}