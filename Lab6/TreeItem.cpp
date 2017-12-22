#include "TreeItem.h"

template <class T> Node<T>::Node(T figure) {
    this->figure = figure;
    this->brother = this->son = nullptr;
}

template <class T> std::shared_ptr <Node <T> > Node<T>::GetSon() {
    return this->son;
}

template <class T> std::shared_ptr <Node <T> > Node<T>::GetBro() {
    return this->brother;
}

template <class T> void Node<T>::SetSon(std::shared_ptr <Node<T> > newSon) {
    this->son = newSon;
}

template <class T> void Node<T>::SetBro(std::shared_ptr <Node<T> > newBro) {
    this->brother = newBro;
}

template <class T> int Node<T>::CountSons() {
    std::shared_ptr<Node<T>> curr = this->son;
    int count = 0;
    while ( curr != nullptr ) {
        curr = curr->GetBro();
        count++;
    }
    return count;
}

template <class T> T Node<T>::GetFigure() {
    return this->figure;
}


template <class T> void Node<T>::AddSon(std::shared_ptr <Node<T> > newSon) {
    if ( this->son == nullptr )
        this->son = newSon;
    else {
        std::shared_ptr<Node<T>> tmp = this->GetSon();
        while ( tmp->brother != nullptr )
            tmp = tmp->GetBro();
        tmp->brother = newSon; 
    }
}

template <class T> void PrintNodes(std::shared_ptr <Node <T> > curr, int depth) {
    std::cout << std::setw(5*depth) << (curr->GetFigure()) << std::endl;
    curr = curr->GetSon();
    depth++;
    while ( curr != nullptr ) {
        PrintNodes(curr, depth);
        curr = curr->GetBro();
    }
}

template <class T> Node<T>::~Node() {   
}

// template class Node<int>;
// template void PrintNodes(std::shared_ptr<Node<int> > curr, int depth);

template class Node<void*>;
template void PrintNodes(std::shared_ptr<Node<void*> > curr, int depth);

// template class Node<char>;
// template void PrintNodes(std::shared_ptr<Node<char> > curr, int depth);