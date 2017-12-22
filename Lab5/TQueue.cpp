#include "TQueue.h"
#include <iostream>

template <class T> TQueue<T>::TQueue() : head(nullptr), last(nullptr) {
}

template <class T> TQueue<T>::TQueue(const TQueue<T>& orig) {
	head = orig.head;
	last = orig.last;
}

template <class T> std::ostream& operator<<(std::ostream& os, const TQueue<T>& queue) {
	std::shared_ptr<TQueueItem<T>> item = queue.head;
	
	while(item!=nullptr)
	{
		os << *item;
		item = item->GetNext();
	}
	return os;
}

template <class T> TIterator<TQueueItem<T>,T> TQueue<T>::begin(){
	return TIterator<TQueueItem<T>,T> (head);
}

template <class T> TIterator<TQueueItem<T>,T> TQueue<T>::end(){
	return TIterator<TQueueItem<T>,T> (nullptr);
}

template <class T> void TQueue<T>::Push(std::shared_ptr<T> &&item) {
	std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(item));
	if (Empty())  {
		head = other;
		last = other;
	}
	else {
		last->SetNext(other);
		last = other;
	}
}

template <class T> bool TQueue<T>::Empty() {
	return head == nullptr;
}

template <class T> std::shared_ptr<T> TQueue<T>::Pop() {
	std::shared_ptr<T> result;
	if (head != nullptr) {
		result = head->GetFigure();
		head = head->GetNext();
	}
	return result;
}

template <class T> TQueue<T>::~TQueue() {
}

#include "Figure.h"
template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Figure>&
stack);