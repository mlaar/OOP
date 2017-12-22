#ifndef TREEITEM_H
#define TREEITEM_H

#include <iostream>
#include <iomanip>
#include <memory>
#include "Figure.h"

template <class T>
class Node {
public:
    Node(T figure);

    std::shared_ptr <Node <T> > GetSon();
    std::shared_ptr <Node <T> > GetBro();

    void SetSon(std::shared_ptr <Node<T> > newSon);
    void SetBro(std::shared_ptr <Node<T> > newBro);

    int CountSons();

    T GetFigure();

    void AddSon(std::shared_ptr <Node<T> > newSon);

    virtual ~Node();
private:
    T figure;
    std::shared_ptr <Node <T> > son;
    std::shared_ptr <Node <T> > brother;
};

template <class T> void PrintNodes(std::shared_ptr<Node<T> > curr, int depth);
template <class T> void PrintNodes(std::shared_ptr<Node<std::shared_ptr<T> > > curr, int depth);

#endif