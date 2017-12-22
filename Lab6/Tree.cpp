#include "Tree.h"

template <class T> Tree<T>::Tree(T figure, int n) {
    this->n = n;
    root = std::make_shared <Node<T> >(figure);
}

template <class T> T Tree<T>::Delete(std::string& path) {
    std::shared_ptr <Node<T> > curr = this->root;
    std::shared_ptr <Node<T> > prev = nullptr;
    int index = 0;
    while ( path[index] != '\0' ) {
        switch ( path[index] ) {
            case 'S':
                prev = curr;
                curr = curr->GetSon();
                break;
            case 'B':
                prev = curr;
                curr = curr->GetBro();
                break;
            default:
                std::cout << "Invalid path" << std::endl;
                return nullptr;
        }
        if ( curr == nullptr ) {
            std::cout << "Invalid path" << std::endl;
            return nullptr;
        }
        index++;
    }
    if ( curr->GetSon() ) {
        std::cout << "Current vertex is not a leaf" << std::endl;
        return nullptr;
    }
    if ( !prev || index == 0 ) {
        this->root = nullptr;
        return curr->GetFigure();
    }
    if ( prev->GetSon() == curr ) {
        prev->SetSon(curr->GetBro());
    }
    else {
        prev->SetBro(curr->GetBro());
    }
    return curr->GetFigure();
}

template <class T> bool Tree<T>::Insert(T figure, std::string& path) {
    std::shared_ptr <Node <T> > curr = this->root;
    int index = 0;
    while ( path[index] != '\0' ) {
        std::cout << path[index] << std::endl;
        switch ( path[index] ) {
            case 'S':
                curr = curr->GetSon();
                break;
            case 'B':
                curr = curr->GetBro();
                break;
            default:
                std::cout << "Invalid path" << std::endl;
                return false;
        }
        if ( curr == nullptr ) {
            std::cout << "Invalid path" << std::endl;
            return false;
        }
        index++;
    }
    int sons = curr->CountSons();
    if ( sons == this->n) {
        std::cout << "This node already has " << this->n << " sons" << std::endl;
        return false;
    }
    curr->AddSon( std::make_shared <Node <T> > (figure));
    return true;
}

template <class T> void Tree<T>::Print() {
    PrintNodes(this->root, 0);
}


template <class T> Tree<T>::~Tree() {
    
}

// template class Tree<int>;
template class Tree<void*>;
// template class Tree<char>;