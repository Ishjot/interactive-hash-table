#include <iostream>
#include "HashTable.h"

using namespace std;

int hash(int key)
{

  return ( (key % 492113) % TABLE_SIZE );

}

HashTable::HashTable()
{
  
  TABLE_SIZE = 5;
  table = new HashEntry * [TABLE_SIZE];
  for(int i = 0; i < TABLE_SIZE; i++)
    table[i] = NULL;

}

HashTable::HashTable(int size)
{

  table = new HashEntry * [size];
  for(int i = 0; i < size; i++;)
    table[i] = NULL;

}

void HashTable::insert(int key, Student value)
{

  if(used/(double)TABLE_SIZE >= 0.7)
    reHash(); 

  int index = hash(key);
  while((table[index] != NULL && table[index]->getKey() != -1) && table[index]->getKey() != key)
    index = (index + 1) % TABLE_SIZE;

  if (table[index] != NULL)
    delete table[index];

  table[index] = new HashEntry(key, value);

  cout << "item successfully inserted" << endl;

}

void HashTable::remove(int key)
{

  int index = hash(key);
  while(table[index] != NULL && table[index]->getKey() != key)
    index = (index + 1) % TABLE_SIZE;

  if(table[index] == NULL)
    cout << "item not present in the table" << endl;

  else
  {
    table[index]->setKey(-1);
    cout << "item successfully deleted" << endl;
  }

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

    if(table[i] != NULL && table[i]->getKey() != -1)
      cout << "(" << table[i]->getKey() << "," << table[i]->getValue().getName() << "," << table[i]->getValue().getGPA() << ")";
  
  }
  cout << endl;
}

void HashTable::reHash()
{

  int newSize = findPrimeTwiceAsLargeAs(TABLE_SIZE);
  HashTable reHashed = new HashTable(newSize);

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
