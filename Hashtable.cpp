#include "Hashtable.h"
#include <cstring>

using namespace std;

Hashtable::Hashtable(int size){
  this->size = nextPrime(size);
  table.reserve(nextPrime(size));
}

bool Hashtable::isPrime(int n){
    if (n <= 1) {
		return false;
	} 
    if (n <= 3) {
		return true;
	}

    if (n % 2 == 0 || n % 3 == 0) {
		return false;
    }
    for (int i = 5; i*i <= n; i = i+6){
		if (n % i == 0 || n % (i+2) == 0) {
			return false;
		}
	}
    return true;
}
 
int Hashtable::nextPrime(int n){
	int prime = n*2;   
	if (prime <= 1) {
		return 2;
	}
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime)){
			found = true;
		}
    }
    return prime;
}

int Hashtable::exists(string ip){
    for(int i = 0; i < this->size; i++){
        if(table[i].first == ip){
            return 0;
        }
    }
    return -1;
}
bool Hashtable::isEmpty(int i){
    if(table[i].first == "" && table[i].second == 0){
        return true;
    }
    return false;
}

int Hashtable::hash(string ip){
    unsigned long hash = 5381;
    unsigned char *val=new unsigned char[ip.length()+1];
    strcpy((char *)val,ip.c_str());
    int c;

    while (c = *val++)
        hash = ((hash << 5) + hash) + c; 

    return hash % size;
}
    
void Hashtable::insertItem(string ip, int index){
    int key = hash(ip);
    for(int i = 0; i < size; i++){
        int quad = (key + i * i) % size;
        if(isEmpty(quad)){
            table[quad].first = ip;
            table[quad].second = index;
        }
    }
}
void Hashtable::deleteItem(int i) {
    table[i].first = "";
    table[i].second = 0;
}



