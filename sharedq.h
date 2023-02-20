#include <deque>
#include <iostream>

#ifndef _SHAREDQ_H_
#define _SHAREDQ_H_


class SharedQueue
{
    //adding member data 4.1
private:
    static std::deque<int> elems;
    SharedQueue() {}
    static SharedQueue SQ_instance;
    
    
public:
    
  
    ~SharedQueue();

    static int ref;
    void enqueue(int);
    int dequeue();
    bool empty();
    int size();
    SharedQueue(const SharedQueue &);
    static SharedQueue &getInstance();
    SharedQueue &operator=(const SharedQueue &);
    static unsigned int num_references();
    int created = 0;
    

    friend std::ostream &operator<<(std::ostream &os, const SharedQueue &sq);
};
std::deque<int> SharedQueue::elems;
SharedQueue SharedQueue::SQ_instance;

#endif
