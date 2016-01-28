#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"

class HashEntry
{
  private:
    int key;
    Student value;

  public:
    HashEntry(int key, Student value) : key(key), value(value) {}
    void setKey(int key) { this->key = key; }
    void setValue(Student Value) { this->value = value; }
    const int getKey() const { return key; }
    const Student getValue() const { return value; }
};

class HashTable
{
  private:
    HashEntry **table;

    int mode;

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

    std::string getMode() const;

    void setMode(int mode) { this->mode = mode; }

    ~HashTable();
};

#endif
