#ifndef TALLOCATIONBLOCK_H
#define	TALLOCATIONBLOCK_H

#include <cstdlib>
#include "Tree.h"


class TAllocationBlock {
public:
    TAllocationBlock(size_t size,size_t count);
    void *allocate();
    void deallocate(void *pointer);
    bool has_free_blocks();
    
    virtual ~TAllocationBlock();
private:
    size_t _size;
    size_t _count;
    
    char  *_used_blocks;
    // void  **_free_blocks;
    std::shared_ptr <Tree <void*> > _free;

    size_t _free_count;      
};

#endif	/* TALLOCATIONBLOCK_H */