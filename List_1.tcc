/*
 * List.cc    Laboration Listan (iterativ)
 */
//#include "List.h"

#include <iostream>
#include <string>
#include <utility>
#include "exception"

namespace linked_list
{
using namespace std;

List::List(const List & list)
{
	copy(list);
}

List::List(List && rightList) /* noexcept*/
	: List()
{
	swap(rightList);
}

List::List(std::initializer_list<int> array)
{
	std::initializer_list<int>::iterator it;  // same as: const int* it
	for ( it = array.begin(); it != array.end(); ++it)
	{
		this->insert(*it);
	}
}

List & List::operator =(const List & rightList)/* & */
{
	List_Node* inP = rightList.head_;
	List_Node* p = this->head_;

	while (inP != nullptr || p != nullptr)
	{
		auto temp = inP->data_;
		inP->data_ = p->data_;
		p->data_ = temp;
	}

	return *this;
}

List & List::operator =(List && rightList) /*& noexcept*/
{
	clear();
	swap(rightList);
	return *this;
}

// insert() sätter in ett värde först.
void List::insert(int value)
{
	try
	{
		head_ = new List_Node(value, head_);
	}
	catch (std::exception& e)
	{
		delete head_;
	}
}

// append() sätter in ett värde sist. 
void List::append(int value)
{
	try
	{
		if (head_ == nullptr)
		{
			head_ = new List_Node(value, nullptr);
		}
		else
		{
			List_Node* last{ head_ };

			while (last->next_ != nullptr)
				last = last->next_;

			last->next_ = new List_Node{ value, nullptr };
		}
	}
	catch (std::exception& e)
	{
		delete head_;
	}
}

// remove() tar bort den först hittade förekomsten av angivet värde, om det 
// finns ett sådant värde.
void List::remove(int value)
{
	if (head_ == nullptr)
	{
		return;
	}
	else if (head_->data_ == value)
	{
		List_Node* garbage{ head_ };
		head_ = head_->next_;
		garbage->next_ = nullptr;
		delete garbage;
	}
	else
	{
		List_Node* prev{ head_ };
		List_Node* curr{ head_->next_ };

		while (curr != nullptr && curr->data_ != value)
		{
			prev = curr;
			curr = curr->next_;
		}

		if (curr != nullptr)
		{
			List_Node* garbage{ curr };
			prev->next_ = curr->next_;
			garbage->next_ = nullptr;
			delete garbage;
		}
	}
}

// clear() tömmer listan.
void List::clear()
{
	delete head_;
	head_ = nullptr;
}

// empty() returnerar sant om listan är tom, falskt annars.
bool List::empty() const
{
	return head_ == nullptr;
}

// member() returnerar sant om angivet värdet finns i listan, annars falskt.
bool List::member(int value) const
{
	List_Node* p{ head_ };

	while (p != nullptr && p->data_ != value)
		p = p->next_;

	return p != nullptr;
}

// print() skriver ut elementen i listan, med 'delimiter' mellan varje värde.
void List::print(std::ostream& os, const std::string& delimiter) const
{
	for (List_Node* p = head_; p != nullptr; p = p->next_)
		os << p->data_ << (p->next_ ? delimiter : "");
}

//byter innehåll med annan lista
void List::swap(List & rightList) noexcept
		{
	std::swap(this->head_, rightList.head_);

	//	if (rightList.empty() || this->empty())
	//			return;
	//	List_Node* p;
	//	List_Node* inp;
	//
	//	for (p = head_, inp = rightList.head_; p != nullptr && inp != nullptr; p = p->next_, inp = inp->next_)
	//	{
	//		auto temp = inp->data_;
	//		inp->data_ = p->data_;
	//		p->data_ = temp;
	//	}
		}

//byter innehåll på två listor
void swap(List & leftList, List & rightList) noexcept
		{
	if (leftList.empty() || rightList.empty())
		return;

	leftList.swap(rightList);
		}

List List::copy(const List & inList)
{
	try
	{
		if (inList.head_ != NULL)
		{
			List_Node* inP;

			for (inP = inList.head_; inP != nullptr; inP = inP->next_)
			{
				this->append(inP->data_);
			}

			//		this->head_ = new List_Node(inP->data_, NULL);
			//		inP = inP->next_;
			//		bool firstCount = true;
			//
			//		while (inP != NULL)
			//		{
			//			List_Node *node = new List_Node(inP->data_, NULL);
			//
			//			if (firstCount)
			//			{
			//				this->head_->next_ = node;
			//				firstCount = false;
			//				p = node;
			//			}
			//			else
			//			{
			//				p->next_ = node;
			//				p = p->next_;
			//			}
			//			inP = inP->next_;
			//		}
			//		inP = NULL;
			//		p = NULL;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "\n\nStandard exception thrown: " << e.what() << "\n\n";
		delete this;
		this->~List();
	}
}
}
