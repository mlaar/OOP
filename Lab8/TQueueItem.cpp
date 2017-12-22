#include "TQueueItem.h"
#include <iostream>

template <class T> TQueueItem<T>::TQueueItem(const std::shared_ptr<T> &figure) {
    this->figure = figure;
    this->next = nullptr;
    std::cout << "Queue item: created" << "\n";
}

template <class T> TQueueItem<T>::TQueueItem(const TQueueItem& orig) {
    this->figure = orig.figure;
    this->next = orig.next;
    std::cout << "Queue item: copied" << "\n";
}

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> &next) {
    std::shared_ptr<TQueueItem<T>> old = this->next;
    this->next = next;
    return old;
}

template <class T> std::shared_ptr<T> TQueueItem<T>::GetFigure() const {
    return this->figure;
}

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
    return this->next;
}

template <class T> TQueueItem<T>::~TQueueItem() {
    std::cout << "Queue item: deleted" << "\n";
}

template <class A> std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
    //os << "[" << *obj.figure << "]" << "\n";
    obj.figure->Print();
    return os;
}



template <class T>
TAllocationBlock TQueueItem<T>::item_allocator(sizeof(TQueueItem<T>), 100);


template <class T> void * TQueueItem<T>::operator new (size_t size) {
    return item_allocator.allocate();
}

template <class T> void TQueueItem<T>::operator delete(void *p) {
    item_allocator.deallocate(p);
}


#include "Figure.h"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>&stack);