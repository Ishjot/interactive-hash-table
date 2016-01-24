#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"

class HashTable
{
  private:
    HashEntry **table;

  public:
    HashTable();

    void insert(int key, Student value);

//    Student lookup const (int key);

    void print();

    ~HashTable();
};
#endif
