#include "Minheap.h"
#include <iostream>

using namespace std;

Minheap::Minheap(int size){
    counter = 0;
    this->size = size;
    Node n = {0,0,""};
    this->heap.push_back(n);
}

void Minheap::insert(string input){
    counter++;
    Node n = {1, counter, input};
    heap.push_back(n);
    heapify_up(heap.size() - 1);
}

void Minheap::increment(int i){
    heap[i].frequency++;
    heapify_down(i);
}

void Minheap::push(string input){
    counter++;
    heap[1].frequency++;
    heap[1].count = counter;
    heap[1].str = input;
    heapify_down(1);
}

Minheap::Node Minheap::get(int i){
    return heap[i];
}

int Minheap::getSize(){
    return heap.size() - 1;
}

bool Minheap::isFull(){
    return (getSize() == size);
}

void Minheap::heapify_down(int i) {
    int min = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    //check if left is smaller
    if (heap[leftChild].frequency < heap[min].frequency && leftChild <= getSize()) {
        min = leftChild;
    }
    else if (heap[leftChild].frequency == heap[min].frequency && leftChild <= getSize()) {
        if(heap[leftChild].count > heap[min].count){
            min = leftChild;
        }
    }

    //check if right is smaller
    if (heap[rightChild].frequency < heap[min].frequency && rightChild <= getSize()) {
        min = rightChild;
    }
    else if (heap[rightChild].frequency == heap[min].frequency && rightChild <= getSize()){
        if(heap[rightChild].count > heap[min].count){
            min = rightChild;
        }
    }

    if (min != i)
    {
        Node temp = heap[min];
        heap[min] = heap[i];
        heap[i] = temp;
        heapify_down(min);
    }
}


void Minheap::heapify_up(int i) {
    if (i > 1)
    {
        int parent = i / 2;
        if(heap[parent].frequency > heap[i].frequency){
            Node temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            heapify_up(parent);
        }
        else if(heap[parent].frequency == heap[i].frequency){
            if(heap[parent].count < heap[i].count){
                Node temp = heap[parent];
                heap[parent] = heap[i];
                heap[i] = temp;
                heapify_up(parent);
            }
        }
    }
}

void Minheap::del(int i){
    heap.erase(heap.begin() + i);
}


      