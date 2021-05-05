#include "Minheap.h"
#include <iostream>

using namespace std;

Minheap::Minheap(int size){
    counter = 0;
    this->size = size;
    pair<int,int> n(0,0);
    this->heap.push_back(n);
}

void Minheap::insert(){
    counter++;
    pair<int,int> n(1, counter);
    heap.push_back(n);
    heapify_up(heap.size() - 1);
}

//vector<pair<int,int>> 
void Minheap::increment(int i){
    counter++;
    heap[i].first++;
    heap[i].second = counter;
    heapify_down(i);
}

 //vector<pair<int,int>> 
 void Minheap::push(){
    counter++;
    heap[1].first++;
    heap[1].second = counter;
    heapify_down(1);
}

pair<int,int> Minheap::get(int i){
    return heap[i];
}

int Minheap::getSize(){
    return heap.size();
}

bool Minheap::isFull(){
    return (getSize() - 1 == size);
}

void Minheap::heapify_down(int i) {
    int min = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    //check if left is smaller
    if (heap[leftChild].first < heap[min].first && leftChild <= getSize()) {
        min = leftChild;
    }
    else if (heap[leftChild].first == heap[min].first && leftChild <= getSize()) {
        if(heap[leftChild].second > heap[min].second){
            min = leftChild;
        }
    }

    //check if right is smaller
    if (heap[rightChild].first < heap[min].first && rightChild <= getSize()) {
        min = rightChild;
    }
    else if (heap[leftChild].first == heap[min].first && leftChild <= getSize()){
        if(heap[rightChild].second > heap[min].second){
            min = rightChild;
        }
    }

    if (min != i)
    {
        pair<int,int> temp = heap[min];
        heap[min] = heap[i];
        heap[i] = temp;
        heapify_down(min);
    }
}


void Minheap::heapify_up(int i) {
    if (i > 1)
    {
        int parent = i / 2;
        if(heap[parent].first > heap[i].first){
            pair<int,int> temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            heapify_up(parent);
        }
        else if(heap[parent].first == heap[i].first){
            if(heap[parent].second < heap[i].second){
                pair<int,int> temp = heap[parent];
                heap[parent] = heap[i];
                heap[i] = temp;
                heapify_up(parent);
            }
        }
    }
}


      