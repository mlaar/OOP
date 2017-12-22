#include "TQueueItem.h"
#include <iostream>

TQueueItem::TQueueItem(const std::shared_ptr<Figure> &figure) {
	this->figure = figure;
	this->next = nullptr;
	std::cout << "Queue item: created" << "\n";
}

TQueueItem::TQueueItem(const TQueueItem& orig) {
	this->figure = orig.figure;
	this->next = orig.next;
	std::cout << "Queue item: copied" << "\n";
}

std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> &next) {
	std::shared_ptr<TQueueItem> old = this->next;
	this->next = next;
	return old;
}

std::shared_ptr<Figure> TQueueItem::GetFigure() const {
	return this->figure;
}

std::shared_ptr<TQueueItem> TQueueItem::GetNext() {
	return this->next;
}

TQueueItem::~TQueueItem() {
	std::cout << "Queue item: deleted" << "\n";
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
	//os << "[" << *obj.figure << "]" << "\n";
	obj.figure->Print();
	return os;
}