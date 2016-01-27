#include <iostream>
#include <math.h>
#include "HashTable.h"

using namespace std;

bool isPrime(int num)
{

  for(int i = 2.0; i <= (sqrt(num) + 1); i++)
  {
    if(i%num == 0)
      return false;
  }

  return true;

}

int findNextPrimeOdd(int num)
{

  while(!isPrime(num))
    num += 2;

  return num;

}

int findPrimeTwiceAsLargeAs(int num)
{

  int candidate = num*2 + 1;
  return findNextPrimeOdd(candidate);

}

int HashTable::hash(int key)
{

  return ( (key % 492113) % TABLE_SIZE );

}
  
int HashTable::hash2(int key)
{
  
  return ( (key % 392113) % TABLE_SIZE );

}
 
void HashTable::reHashHelper(HashEntry **table, int size, int key, Student value)
{

  int index = hash(key);
  while( (table[index] != NULL && table[index]->getKey() != -1) && table[index]->getKey() != key)
    index = (index + 1) % size;

  if( table[index] != NULL ) 
    delete table[index];

  table[index] = new HashEntry(key, value);
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
  for(int i = 0; i < size; i++)
    table[i] = NULL;

}

void HashTable::insert(int key, Student value)
{

  used++;

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
    used--;
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
  HashEntry **newTable = new HashEntry * [newSize];
  
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    if(table[i] != NULL && table[i]->getKey() != -1)
      reHashHelper( newTable, newSize, table[i]->getKey(), table[i]->getValue() );
  }

  for(int i = 0; i< TABLE_SIZE; i++)
  {
    if( table[i] != NULL)
      delete table[i];
  }

  table = newTable;
  TABLE_SIZE = newSize;

  cout << "table doubled" << endl;

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
