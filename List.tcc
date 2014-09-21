/*
 * List.cc    Laboration Listan (iterativ)
 */
#include "List.h"

#include <iostream>
#include <string>
#include <utility>
#include "exception"

namespace linked_list
{
using namespace std;

template <typename T>
List<T>::List(const List<T> & list)
{
	/*
	 * origin head -> node -> node -> node -> nullptr/end
	 *    new head -> node -> node -> node -> nullptr/end
	 */
	List_Node<T>* current = nullptr;
	List_Node<T>* next = nullptr;
	
	if (NULL == list.head_)
		head_ = NULL;
	else
	{
		head_ = new List_Node<T>(list.head_->data_);
		current = head_;
		next = list.head_->next_;
	}

	while (next)
	{
		current->next_ = new List_Node<T>(next->data_);
		current = current->next_;
		next = next->next_;
	}
	current->next_ = nullptr;
}

template <typename T>
List<T>::List(List<T> && rightList) /* noexcept*/
	: List<T>()
{
	swap(rightList);
}

template <typename T>
List<T>::List(std::initializer_list<T> array)
{
	typename std::initializer_list<T>::iterator it;  // same as: const int* it
	for ( it = array.begin(); it != array.end(); ++it)
	{
		this->insert(*it);
	}
}
template <typename T>
List<T> & List<T>::operator =(const List<T> & rightList)/* & */
{
	List_Node<T>* inP = rightList.head_;
	List_Node<T>* p = this->head_;

	while (inP != nullptr || p != nullptr)
	{
		auto temp = inP->data_;
		inP->data_ = p->data_;
		p->data_ = temp;
	}

	return *this;
}
template <typename T>
List<T> & List<T>::operator =(List<T> && rightList) /*& noexcept*/
{
	clear();
	swap(rightList);
	return *this;
}

// insert() sätter in ett värde först.
template <typename T>
void List<T>::insert(T value)
{
	try
	{
		head_ = new List_Node<T>(value, head_);
		//size() += 1;
	}
	catch (std::exception& e)
	{
		delete head_;
	}
}

// append() sätter in ett värde sist.
template <typename T>
void List<T>::append(T value)
{
	try
	{
		if (head_ == nullptr)
		{
			head_ = new List_Node<T>(value, nullptr);
		}
		else
		{
			List_Node<T>* last{ head_ };

			while (last->next_ != nullptr)
				last = last->next_;

			last->next_ = new List_Node<T>{ value, nullptr };
		}
	}
	catch (std::exception& e)
	{
		delete head_;
	}
}

// remove() tar bort den först hittade förekomsten av angivet värde, om det
// finns ett sådant värde.
template <typename T>
void List<T>::remove(T value)
{
	if (head_ == nullptr)
	{
		return;
	}
	else if (head_->data_ == value)
	{
		List_Node<T>* garbage{ head_ };
		head_ = head_->next_;
		garbage->next_ = nullptr;
		delete garbage;
		//size() -= 1;
	}
	else
	{
		List_Node<T>* prev{ head_ };
		List_Node<T>* curr{ head_->next_ };

		while (curr != nullptr && curr->data_ != value)
		{
			prev = curr;
			curr = curr->next_;
		}

		if (curr != nullptr)
		{
			List_Node<T>* garbage{ curr };
			prev->next_ = curr->next_;
			garbage->next_ = nullptr;
			delete garbage;
			//size() -= 1;
		}
	}
}

// clear() tömmer listan.
template <typename T>
void List<T>::clear()
{
	List_Node<T>* pn {head_};
	while (pn != NULL)
	{
		head_ = head_->next_;
		delete pn;
		pn = head_;
	}
	head_ = NULL;
}

//size() ger storleken på arrayen(listan)
template <typename T>
int List<T>::size() const
{
	int counter = 0;
	List_Node<T>* pn{ head_ };

	while (pn != nullptr)
	{
		counter++;
		pn = pn->next_;
	}

	return counter;
}

// empty() returnerar sant om listan är tom, falskt annars.
template <typename T>
bool List<T>::empty() const
{
	return head_ == nullptr;
}

// member() returnerar sant om angivet värdet finns i listan, annars falskt.
template <typename T>
bool List<T>::member(T value) const
{
	List_Node<T>* pn{ head_ };

	while (pn != nullptr && pn->data_ != value)
		pn = pn->next_;

	return pn != nullptr;
}

// print() skriver ut elementen i listan, med 'delimiter' mellan varje värde.
template <typename T>
void List<T>::print(std::ostream& os, const std::string& delimiter) const
{
	for (List_Node<T>* pn = head_; pn != nullptr; pn = pn->next_)
		os << pn->data_ << (pn->next_ ? delimiter : "");
}

//byter innehåll med annan lista
template <typename T>
void List<T>::swap(List<T> & rightList) noexcept
{
	//size_type temp = size();
	//size() = rightList.size();
	//rightList.size() = temp;
	//std::swap(this->head_, rightList.head_);
	
	
		if (rightList.empty() || this->empty())
				return;
		List_Node<T>* p;
		List_Node<T>* inp;
	
		for (p = head_, inp = rightList.head_; p != nullptr && inp != nullptr; p = p->next_, inp = inp->next_)
		{
			auto temp = inp->data_;
			inp->data_ = p->data_;
			p->data_ = temp;
		}
}

//byter innehåll på två listor
template <typename T>
void swap(List<T> & leftList, List<T> & rightList) noexcept
{
	if (leftList.empty() || rightList.empty())
		return;
		
	leftList.swap(rightList);
}

template <typename T>
List<T> List<T>::copy(const List<T> & inList) //shallow copy
{
	try
	{
		List_Node<T>* inP;
		inP = inList.head_;
		List_Node<T>* newHead_ = new List_Node<T>(inP->data_);
		
		newHead_->data_ = inP->data_;

		while (nullptr != inP->next_)
		{
			newHead_->next_ = inP->next_;

//			for (inP = inList.head_; inP != nullptr; inP = inP->next_)
//			{
//				this->append(inP->data_);
//			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << "\n\nStandard exception kastats: " << e.what() << "\n\n";
		delete this;
		this->~List();
	}
}
}