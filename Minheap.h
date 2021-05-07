#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Minheap {

public:

    struct Node{
        int frequency;
        int count;
        string str;
    };

    //constructor
    Minheap(int size);
 
    //inserts new element into vector and calls heapify
    void insert(string input);

    void increment(int i);

    void push(string input);

    //get element i from heap
    Node get(int i);

    //get size of heap
    int getSize();

    //check if heap is full
    bool isFull();

    //heapify downwards used for when element is incremented
    void heapify_down(int i);
 
    //heapify upwards, used for when element is inserted
    void heapify_up(int i);

    void del(int i);

private:
    int counter;
    int size;
    vector<Node> heap;
};
#endif