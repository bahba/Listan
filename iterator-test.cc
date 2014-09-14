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
	cout << "list1 initieras med int via append.\n" << "list1 innehåller: ";
	List<int> list1;
	list1.append(2);
	list1.append(4);
	list1.append(6);

	print(cout, list1);

	cout << "\nlist2 initieras med int via insert.\n" << "list2 innehåller: ";
	List<int> list2;
	list2.insert(1);
	list2.insert(3);
	list2.insert(5);

	print(cout, list2);

	cout << "\nlist3 initieras med char via append.\n" << "list3 innehåller: ";
	List<char> list3;
	list3.append('b');
	list3.append('a');
	list3.append('h');
	list3.append('a');
	list3.append('r');
	list3.append('e');

	print(cout, list3);

	cout << "\nlist4 initieras via iteratorer, till en kopia av list3.\n" << "list4 innehåller: ";
	List<char> list4;
	for (List<char>::iterator it = list3.begin(); it != list3.end(); it++)
	{
		list4.append(*it);
	}

	print(cout, list4);

	cout << "\nlist4.size(): " << list4.size();

	cout << "\nlist4.member('a'): " << list4.member('a');

	int counter = 0;
	for (List<char>::iterator it = list4.begin(); it != list4.end(); it++)
	{
		if (*it == 'a')
			counter++;
	}
	cout << "\nTotal antal uppkomst av 'a' i list4: " << counter;

	cout << "\n\nTest om list3 == list4: ";

	bool lika = false;
	List<char>::iterator cit, cit2;
	for (cit = list3.begin(), cit2 = list4.begin(); cit != list3.end(), cit2 != list4.end(); cit++, cit2++)
	{
		if (*cit == *cit2)
			lika = true;
		else
			lika = false;
	}

	if (lika)
		cout << "sant";
	else
		cout << "falskt";

	cout << "\n\nTest om list1 == list2: ";
	List<int>::iterator iit, iit2;
	for (iit = list1.begin(), iit2 = list2.begin(); iit != list1.end(), iit2 != list2.end(); iit++, iit2++)
	{
		if (*iit == *iit2)
			lika = true;
		else
			lika = false;
	}

	if (lika)
		cout << "sant";
	else
		cout << "falskt";

	cout << "Test av swap().\n" << "före:\n" << "list1: ";
	print(cout, list1);
	cout << "list2: ";
	print(cout, list2);

	cout << "efter:\n" << "list1: ";
	list1.swap(list2);
	print(cout, list1);
	cout << "list2: ";
	print(cout, list2);

	cout << "\nTestar list2.clear().\nföre  - list2.size(): " << list2.size() << "\nefter - list2.size(): ";
	list2.clear();
	cout << list2.size();

	list1.insert(3);
	list2.append(3);
	list1.insert(7);
	list2.append(9);
	cout << "\n\nTestar list1.remove(3).\nföre  - list1 innehåller: ";
	print(cout, list1);
	list1.remove(3);
	cout << "efter - list1 innehåller nu: ";
	print(cout, list1);

	const List<int> clist1 {1, 2, 3, 4, 5, 6};
	cout << "\nLäser const list mha const_iterator.\nclist1 innehåller: ";

	List<int>::const_iterator start = clist1.begin();
	List<int>::const_iterator stop = clist1.end();

	while (start != stop)
	{
		cout << *start << " ";
//		start++;
	}


}
