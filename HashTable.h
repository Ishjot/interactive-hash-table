#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"

class HashTable
{
  private:
    HashEntry **table;

    int TABLE_SIZE;

    int used;

  public:

    int hash(int key);

    int hash2(int key);

    HashTable();

    HashTable(int size);

    void insert(int key, Student value);

    void remove(int key);

    void lookup (int key);

    void print();

    void reHash();

    int getTableSize() const { return TABLE_SIZE; }

    int getUsed() const { return used; }

    ~HashTable();
};
#endif
