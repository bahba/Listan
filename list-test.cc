///*
// * list-test.cc    Laboration Listan
// */
//#include "List.h"
//
//#include <iostream>
//#include <utility>
//
//using namespace linked_list;
//using namespace std;
//
//
//void print(ostream& os, const List<int>& lst)
//{
//	lst.print(cout, " -> ");
//	os << '\n';
//}
//
//void print(ostream& os, const List<char>& lst)
//{
//	lst.print(cout, " -> ");
//	os << '\n';
//}
//
//int main()
//{
//	List<int> list_1;
//
//	cout << "Ny lista skapad: List1\n";
//
//	if (list_1.empty())
//		cout << "List1 �r tom\n";
//	else
//		cout << "List1 �r inte tom\n";
//
//	cout << "\nS�tter in, i tur och ordning, 1, 2, 3 f�rst i List1\n";
//	list_1.insert(1);
//	list_1.insert(2);
//	list_1.insert(3);
//
//	if (list_1.empty())
//		cout << "List1 �r tom\n";
//	else
//		cout << "List1 �r inte tom\n";
//
//	cout << "List1 inneh�ller: ";
//	print(cout, list_1);
//
//	cout << "\nS�tter in, i tur och ordning, 4, 5, 6 sist i List1\n";
//	list_1.append(4);
//	list_1.append(5);
//	list_1.append(6);
//
//	cout << "List1 inneh�ller: ";
//	print(cout, list_1);
//
//	if (list_1.member(4))
//		cout << "\nV�rdet 4 finns i List1\n";
//	else
//		cout << "\nV�rdet 4 finns ej i List1\n";
//
//	if (list_1.member(7))
//		cout << "V�rdet 7 finns i List1\n";
//	else
//		cout << "V�rdet 7 finns ej i List1\n";
//
//	cout << "\nTar bort 4 ur List1\n";
//	list_1.remove(4);
//
//	cout << "List1 inneh�ller: ";
//	print(cout, list_1);
//
//	cout << "\nTar bort 1 ur List1\n";
//	list_1.remove(1);
//
//	cout << "List1 inneh�ller: ";
//	print(cout, list_1);
//
//	cout << "\nTar bort 6 ur List1\n";
//	list_1.remove(6);
//
//	cout << "List1 inneh�ller: ";
//	print(cout, list_1);
//
//	cout << "\nT�mmer List1\n";
//	list_1.clear();
//
//	if (list_1.empty())
//	{
//		cout << "List1 �r tom\n";
//	}
//	else
//	{
//		cout << "List1 �r inte tom\n";
//		cout << "List1 inneh�ller: ";
//		print(cout, list_1);
//	}
//
//	cout << "\nS�tter in, i tur och ordning, 1, 2, 3 f�rst i List1\n";
//	list_1.insert(1);
//	list_1.insert(2);
//	list_1.insert(3);
//
//	cout << "List1 inneh�ller: ";
//	print(cout, list_1);
//
//	cout << "\nNy lista skapad: List2.\n";
//	List<int> list_2;
//
//	if (list_2.empty())
//		cout << "List2 �r tom\n";
//	else
//		cout << "List2 �r inte tom\n";
//
//	cout << "\nS�tter in, i tur och ordning, 7, 8, 9 sist i List2\n";
//	list_2.append(7);
//	list_2.append(8);
//	list_2.append(9);
//
//	cout << "List2 inneh�ller: ";
//	print(cout, list_2);
//
//	cout << "\nList1 byter inneh�ll med List2, via medlemsfunktion\n";
//	list_1.swap(list_2);
//
//	if (list_1.empty())
//		cout << "\nList1 �r tom";
//	else
//	{
//		cout << "\nList1 �r inte tom";
//		cout << "\nList1 inneh�ller: ";
//		print(cout, list_1);
//	}
//
//	if (list_2.empty())
//		cout << "\nList2 �r tom";
//	else
//	{
//		cout << "\nList2 �r inte tom";
//		cout << "\nList2 inneh�ller: ";
//		print(cout, list_2);
//	}
//
//	cout << "\nList1 byter inneh�ll med List2, via normalfunktion\n";
//	swap(list_1, list_2);
//
//	if (list_1.empty())
//		cout << "\nList1 �r tom";
//	else
//	{
//		cout << "\nList1 �r inte tom";
//		cout << "\nList1 inneh�ller: ";
//		print(cout, list_1);
//	}
//
//	if (list_2.empty())
//		cout << "\nList2 �r tom";
//	else
//	{
//		cout << "\nList2 �r inte tom";
//		cout << "\nList2 inneh�ller: ";
//		print(cout, list_2);
//	}
//
//	cout << "\nNy lista skapas: List3\nList3 inneh�ller: ";
//	List<int> list_3;
//	list_3.append(10);
//	list_3.append(11);
//	list_3.append(12);
//	print(cout, list_3);
//
//	cout << "\nKopieringskonstruerar List4 fr�n List3";
//	List<int> list_4(list_3);
//
//	cout << "\nList4 inneh�ller: ";
//	print(cout, list_4);
//
//	cout << "\nEfter kopieringskonstruktion -> List3 inneh�ller: ";
//	print(cout, list_3);
//
//	cout << "\nFlytt-konstruerar List5 fr�n List3";
//	List<int> list_5(std::move(list_3));
//
//	cout << "\nList5 inneh�ller: ";
//	print(cout, list_5);
//
//	cout << "\nList3 �r ";
//	if (list_3.empty())
//		cout << "tom\n";
//	else
//	{
//		cout << "inte tom\n";
//		print(cout, list_3);
//	}
//
//	cout << "\nList1 inneh�ller: ";
//	print(cout, list_1);
//
//	cout << "\nFlytt-tilldelar List1 fr�n List5";
//	list_1 = std::move(list_5);
//
//	cout << "\nList1 inneh�ller: ";
//	print(cout, list_1);
//
//	cout << "\nList5 �r ";
//	if (list_5.empty())
//		cout << "tom\n";
//	else
//	{
//		cout << "inte tom\n";
//		print(cout, list_5);
//	}
//
//	cout << "\nInitierar List6 med initializer_list av ints";
//	List<int> list_6{1, 2, 3, 4, 5, 6};
//	cout << "\nList6 inneh�ller: ";
//	print(cout, list_6);
//
//	cout << "\nInitierar List7 med initializer_list av chars";
//	List<char> list_7{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
//	cout << "\nList7 inneh�ller: ";
//	print(cout, list_7);
//
//	cout << "\nListorna destrueras\n";
//
//	return 0;
//}
