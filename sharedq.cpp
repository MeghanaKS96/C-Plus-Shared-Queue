#include "sharedq.h"
#include <stdexcept>
#include <deque>
#include<string>



int SharedQueue::ref=0;
void SharedQueue::enqueue(int i)
{
    elems.push_back(i);
}

int SharedQueue::dequeue()
{
    int i = elems.front();
    elems.pop_front();
    return i;
}

bool SharedQueue::empty()
{
    return elems.empty();
}

int SharedQueue::size()
{
    return elems.size();
}

//returning reference count 4.2
unsigned int SharedQueue::num_references()
{
    return SharedQueue::ref;
}

//defining destructor 4.3
SharedQueue::~SharedQueue()
{
    SharedQueue::ref -=1; 
}

//defining getinstance 4.4
SharedQueue &SharedQueue::getInstance()
{
    if (ref >= 10)
     throw std::overflow_error("");
   ref+=1;
   return SQ_instance;
}

//copy constructor 4.5
SharedQueue::SharedQueue(const SharedQueue &other)
{
    elems = other.elems;
    SQ_instance=other.SQ_instance;
   
}

//Overload = function 4.6
SharedQueue &SharedQueue::operator=(const SharedQueue &rhs)
{
    
    if (ref>=10)
    throw std::overflow_error("");
    SharedQueue::ref ++;
    return *this;
    
}

std::ostream &operator<<(std::ostream &os, const SharedQueue &sq)
{

    // for(int i =0; i<sq.elems.size();i++)
    // {
    //     os << sq.elems[i] << " ";
    // }
    for(auto &i : sq.elems)
    {
        os << i << " ";
    }
    os << std::endl;
    return os;
}