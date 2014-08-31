/*
 * iterator-test.cc
 *
 *  Created on: 19 maj 2014
 *      Author: Bee
 */


#include "List.h"

#include <iostream>
#include <utility>

using namespace linked_list;
using namespace std;


void print(ostream& os, const List<int>& lst)
{
	lst.print(cout, " -> ");
	os << '\n';
}

void print(ostream& os, const List<char>& lst)
{
	lst.print(cout, " -> ");
	os << '\n';
}

int main()
{
	List<int> list_1;

	list_1.append(1);
	list_1.append(2);
	list_1.append(3);

	cout << "List1 innehåller: ";
	print(cout, list_1);

	cout << "\nTestar iteratorer\n";
	cout << "\nSkapar List2 och kopierar över data via iteratorer";
	List<int> list_2;

	//List<int>::iterator* it;

	//it->current_->data_ = 3;
	//list_2.append(it->current_->data_);

	//cout << "\nList2 innehåller: ";
		//print(cout, list_2);
}
