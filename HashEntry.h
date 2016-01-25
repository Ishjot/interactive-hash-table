#ifndef HASHENTRY_H
#define HASHENTRY_H

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

#endif
