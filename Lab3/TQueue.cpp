#include "TQueue.h"
#include <iostream>

TQueue::TQueue() : head(nullptr), last(nullptr) {
}

TQueue::TQueue(const TQueue& orig) {
	head = orig.head;
	last = orig.last;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {
	std::shared_ptr<TQueueItem> item = queue.head;
	
	while(item!=nullptr)
	{
		os << *item;
		item = item->GetNext();
	}
	return os;
}

void TQueue::Push(std::shared_ptr<Figure> &&figure) {
	std::shared_ptr<TQueueItem> other(new TQueueItem(figure));
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

std::shared_ptr<Figure> TQueue::Pop() {
	std::shared_ptr<Figure> result;
	if (head != nullptr) {
		result = head->GetFigure();
		head = head->GetNext();
	}
	return result;
}

TQueue::~TQueue() {
}