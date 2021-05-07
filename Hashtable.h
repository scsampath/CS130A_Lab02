#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Hashtable {

  public:
    vector<pair<string, int>> table;

    Hashtable(int size);

    bool isPrime(int i);
    int nextPrime(int i);

    int findString(string ip);
    int findIndex(int index);
    
    bool isEmpty(int i);

    int hash(string ip);
    
    void insertItem(string ip, int index);
    void deleteItem();

    pair<string,int> get(int i);
    void set(string ip,int val, int i);

    int getSize(){
      return table.size();
    };

    void set(int i, int val);

  private:
    int size;

};


#endif
