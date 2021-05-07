#include "Minheap.h"
#include "Hashtable.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main(int argc, char* argv[]) {
    if(argc != 4) return -1;

    int k = stoi(argv[3]);
    
    Minheap m(k);
    Hashtable h(k);

    ifstream file(argv[1]);
    string data = "";
    while(getline(file, data,',')){
        int exists = h.findString(data);
        if(exists != -1){
            int index = h.get(exists).second;
            m.increment(index);    
        }
        else {
            if(!(m.isFull())){
                m.insert(data);
                h.insertItem(data,1);
            } else {
                m.push(data);
                h.deleteItem();
                h.insertItem(data,1);
            }
        }
        for(int i = 1; i < m.getSize() + 1; i++){
            int index = h.findString(m.get(i).str);
            h.set(index, i);
        }
    }
    file.close();

    ofstream outputFile;
    outputFile.open(argv[2]);
    int size = m.getSize();
    for(int i = 0; i < size; i++){
        int min = 1;
        for(int j = 1; j < m.getSize() + 1; j++){
            if(m.get(min).frequency > m.get(j).frequency){
                min = j;
            }
            else if(m.get(min).frequency == m.get(j).frequency && m.get(min).count < m.get(j).count){
                min = j;
            }
        }
        outputFile<<m.get(min).str<<":"<<m.get(min).frequency<<",";
        m.del(min);
    }
    outputFile.close();
}