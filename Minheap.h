#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Minheap {

public:
    //constructor
    Minheap(int size);
 
    //inserts new element into vector and calls heapify
    void insert();

    void increment(int i);

    void push();

    //if vector is full then element is added at root and heapify is called
    void add(int element);
 
    //get element i from heap
    pair<int,int> get(int i);

    //get size of heap
    int getSize();

    //check if heap is full
    bool isFull();

    //heapify downwards used for when element is incremented
    void heapify_down(int i);
 
    //heapify upwards, used for when element is inserted
    void heapify_up(int i);

private:
    int counter;
    int size;
    vector<pair<int, int>> heap;
};
#endif