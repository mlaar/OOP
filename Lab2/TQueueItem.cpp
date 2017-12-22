#include "TQueueItem.h"
#include <iostream>

TQueueItem::TQueueItem(const Trapeze& trapeze) {
	this->trapeze = trapeze;
	this->next = nullptr;
	std::cout << "Queue item: created" << "\n";
}

TQueueItem::TQueueItem(const TQueueItem& orig) {
	this->trapeze = orig.trapeze;
	this->next = orig.next;
	std::cout << "Queue item: copied" << "\n";
}

TQueueItem* TQueueItem::SetNext(TQueueItem* next) {
	TQueueItem* old = this->next;
	this->next = next;
	return old;
}

Trapeze TQueueItem::GetTrapeze() const {
	return this->trapeze;
}

TQueueItem* TQueueItem::GetNext() {
	return this->next;
}

TQueueItem::~TQueueItem() {
	std::cout << "Queue item: deleted" << "\n";
	delete next;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
	os << "[" << obj.trapeze << "]" << "\n";
	return os;
}