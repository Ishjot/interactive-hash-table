#include <iostream>
#include <math.h>
#include <iomanip>
#include "Hashtable.h"

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
 
void reHashHelper(HashEntry **table, int size, int mode, int key, Student value)
{

  int index = ( (key % 492113) % size );

  int i = 1;

  while( (table[index] != NULL && table[index]->getKey() != -1) && table[index]->getKey() != key)
  {  
    if(mode == 1) // Linear Probing
      index = (index + 1) % size;

    else if(mode == 2) // Double Hashing
    {
      int h2 = ((key % 392113) % size);
      if(h2 == 0)
      {
        h2 = 1;
      }
      index = (index + i*h2) % size;
      i++;
    }
  }  

  if( table[index] != NULL ) 
    delete table[index];

  table[index] = new HashEntry(key, value);
}

HashTable::HashTable()
{
  
  this->TABLE_SIZE = 5;
  this->mode = 1;
  this->used = 0;
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

  bool doesExist = false;
  for(int i = 0; i < TABLE_SIZE - 1; i++)
  {
    if(table[i] != NULL)
    {
      if(table[i]->getKey() == key)
        doesExist = true;
    }
  }

  if(doesExist)
  {
    cout << "item already present" << endl;
    return;
  }

  used++;

  if(used/(double)TABLE_SIZE >= 0.7)
    reHash();

  int index = hash(key);
  int i = 1;
  {
    while(table[index] != NULL && table[index]->getKey() != -1 && table[index]->getKey() != key)
    {  
      if(mode == 1) // Linear Probing
        index = (index + 1) % TABLE_SIZE;
      else if(mode == 2) // Double Hashing
      {
	      int h2 = hash2(key);
	      if(h2 == 0)
	      {
	        h2 = 1;
	      }
        index = (index + i*h2) % TABLE_SIZE;
        i++;
      }
    }
  } 

  if(table[index] != NULL)
    delete table[index];

  table[index] = new HashEntry(key, value);

  cout << "item successfully inserted" << endl;

}

void HashTable::remove(int key)
{

  int index = hash(key);
  int i = 1;
  while(table[index] != NULL && table[index]->getKey() != key)
  {
    if(this->mode == 1) // Linear probing
      index = (index + 1) % TABLE_SIZE;
    else if(this->mode == 2) // Double hashing
    {
      index = (index + i*hash2(key)) % TABLE_SIZE;
      i++;
    }
  }

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
  int i = 1;
  while(table[index] != NULL && table[index]->getKey() != key)
  {
    if(this->mode == 1) // Linear Probing
      index = (index + 1) % TABLE_SIZE;
    if(this->mode == 2) // Double Hashing
    {
      index = (index + i*hash2(key)) % TABLE_SIZE;
      i++;
    }
  }
  if (table[index] == NULL)
    cout << "item not found" << endl;

  else
    cout << "item found; " << table[index]->getValue().getName() << " " << index << endl;
  
}

void HashTable::print()
{

  for(int i = 0; i < TABLE_SIZE; i++)
  {

    if(table[i] != NULL && table[i]->getKey() != -1)
    {
      cout << "(" << table[i]->getKey() << "," << table[i]->getValue().getName() << ",";
      cout << std::fixed << std::setprecision(1) << table[i]->getValue().getGPA();
      cout << ")";
    }
  
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
      reHashHelper( newTable, newSize, mode, table[i]->getKey(), table[i]->getValue() );
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

string HashTable::getMode() const
{

  if( this->mode == 1 )
    return "linearprobing";

  else if( this-> mode == 2 )
    return "doublehashing";

  else
    return "unsupported mode!";

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
