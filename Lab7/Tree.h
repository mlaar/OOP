#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <memory>
#include <string>

#include "TreeItem.h"
#include "Figure.h"

template <class T> 
class Tree
{
public:
    Tree(T figure, int n);

    T Delete(std::string& path);

    bool Insert(T figure, std::string& path);
    
    void Delete();
    void Print();

    ~Tree();
private:
    std::shared_ptr <Node <T> > root;
    int n;
};


#endif