#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Hashtable {

  public:

    Hashtable(int size);

    bool isPrime(int i);
    int nextPrime(int i);

    int exists(string ip);
    bool isEmpty(int i);

    int hash(string ip);
    
    void insertItem(string ip, int index);
    void deleteItem(int i);

  private:
    int size;
    vector<pair<string, int>> table;
};


#endif
