#include "TAllocationBlock.h"
#include <iostream>
#include <string>

TAllocationBlock::TAllocationBlock(size_t size,size_t count): _size(size),_count(count)  {
    _used_blocks = (char*)malloc(_size*_count);
    _free = std::shared_ptr<Tree<void*> >(new Tree<void*> ((nullptr), _count));
    std::string path = "\0";
    for (size_t i = 0; i < _count; i++) { 
        _free->Insert(((void*)(_used_blocks + i * _size)), path);
    }
    _free_count = _count;
    std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void *TAllocationBlock::allocate() {
    void *result = nullptr;
    
    if(_free_count > 0) {
        std::string path = "S";
        result = _free->Delete(path);
        _free_count--;
        std::cout << "TAllocationBlock: Allocate " << (_count - _free_count) << " of " << _count << std::endl;
    } else {
        std::cout << "TAllocationBlock: No memory exception :-)" << std::endl;
    }    
    return result;
}

void TAllocationBlock::deallocate(void *pointer) {
    std::cout << "TAllocationBlock: Deallocate block "<< std::endl;
    std::string path = "\0";
    _free->Insert(pointer, path);
    _free_count ++;
}

bool TAllocationBlock::has_free_blocks() {
    return _free_count > 0;
}

TAllocationBlock::~TAllocationBlock() {
    
    if(_free_count<_count) std::cout << "TAllocationBlock: Memory leak?" << std::endl;
                    else  std::cout << "TAllocationBlock: Memory freed" << std::endl;
    free(_used_blocks);
}