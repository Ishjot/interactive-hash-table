#include <iostream>
#include "HashTable.h"

#define TABLE_SIZE 5

using namespace std;

int hash(int key)
{

  return ( (key % 492113) % TABLE_SIZE );

}

HashTable::HashTable()
{

  table = new HashEntry * [TABLE_SIZE];
  for(int i = 0; i < TABLE_SIZE; i++)
    table[i] = NULL;

}


void HashTable::insert(int key, Student value)
{

  int index = hash(key);
  while(table[index] != NULL && table[index]->getKey() != key)
    index = (index + 1) % TABLE_SIZE;

  if (table[index] != NULL)
    delete table[index];

  table[index] = new HashEntry(key, value);

  cout << "item successfully inserted" << endl;

}

void HashTable::lookup(int key)
{

  int index = hash(key);
  while(table[index] != NULL && table[index]->getKey() != key)
    index = (index + 1) % TABLE_SIZE;

  if (table[index] == NULL)
    cout << "item not present in the table" << endl;

  else
    cout << "item found; " << table[index]->getValue().getName() << " " << table[index]->getValue().getGPA() << endl;
  
}

void HashTable::print()
{

  for(int i = 0; i < TABLE_SIZE; i++)
  {

    if(table[i] != NULL)
      cout << "Student at index " << i << " is " << table[i]->getValue().getName() << " " << table[i]->getValue().getGPA() << endl;
  
  }

}

HashTable::~HashTable()
{

  for(int i = 0; i < TABLE_SIZE; i++)
  {
    if(table[i] != NULL)
      delete table[i];
  }

  delete[] table;

}
