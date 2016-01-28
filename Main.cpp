#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include "Hashtable.h"
#include "Hashentry.h"
#include "Student.h"

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);     // if you use this line, it merely redirects stdin to input.txt file; simple as that


	try
	{
		HashTable h;

		while(true)
		{
			string str;
			cin >> str;
			if(cin.eof())
			{
				break;
			}
			if(str.compare("exit") == 0)
			{
				break;
			}
	    else if(str.compare("linearprobing") == 0)
			{
				h.setMode(1);
			}
			else if(str.compare("doublehashing") == 0)
			{
				h.setMode(2);
			}
			else if(str.compare("insert") == 0)
			{
				int key;
				string name;
				double gpa;
				cin >> key >> name >> gpa;
				Student tmp(name, gpa);
				h.insert(key, tmp);
			}
			else if(str.compare("lookup") == 0)
			{
				int key;
				cin >> key;
				h.lookup(key);
			}
			else if(str.compare("delete") == 0)
			{
				int key;
				cin >> key;
				h.remove(key);
			}
			else if(str.compare("print") == 0)
			{
				h.print();
			}
      else if(str.compare("size") == 0)
      {
        cout << h.getTableSize() << endl;
      }
      else if(str.compare("used") == 0)
      {
        cout << h.getUsed() << endl;
      }
      else if(str.compare("mode") == 0)
      {
        cout << h.getMode() << endl;
      }
			else
			{
				cin.clear();
				cout << "Inputed string format was incorrect" << endl;
			}
		}
	}
	catch(exception& ex)
	{
		cerr << ex.what() << endl;
	}

	return 0;
}
