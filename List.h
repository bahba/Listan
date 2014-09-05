/*
 * List.h    Laboration Listan (iterativ)
 */
#ifndef LIST_H
#define LIST_H

#include <iosfwd>
#include <string>
#include <initializer_list>

namespace linked_list
{
template <typename T>
struct List_Node
{
	List_Node(T value, List_Node* tail)
	: data_(value), next_(tail) {};

	List_Node(T value)
	: data_(value), next_(nullptr) {};

	~List_Node()
	{
		if (NULL == next_)
			delete next_;
	}

	T data_; 				//data to be stored
	List_Node<T>* next_; 	//pointer to next node
};

template <typename T>
struct List_iterator_
{
	typedef T 							value_type;
	typedef T* 							pointer;
	typedef T& 							reference;
	typedef std::ptrdiff_t 				difference_type;
	typedef std::forward_iterator_tag 	iterator_category;

	//defaultkonstruktor som s�tter iteratorn till "f�rbi-sista"
	List_iterator_<T>() = default;
	//konstruktor f�r att initiera med en pekare till en listnod
	List_iterator_<T>(List_Node<T>* ptr);
	//operator* ska returnera en referens till elementet i noden
	T operator*();
	//operator-> ska returnera en pekare till elementet i noden
	T operator->();
	//operator++ i b�de prefix och postfix version f�r att stegra iteratorn
	T& operator++();			//postfix
	const T operator++(int);	//prefix
	//operator== f�r att kontrollera om tv� iteratorer �r lika, eller inte
	T& operator==(const T& rhs);
	//operator!= f�r att kontrollera om tv� iteratorer �r olika, eller inte
	T& operator!=(const T& rhs);
	//pekare till listnod, representationen f�r iteratorn
	List_Node<T>* current_;


};

//template <typename T>
//List_iterator_<T>::List_iterator_()
//{
//	default;
//
//}

template <typename T>
List_iterator_<T>::List_iterator_(List_Node<T>* head)
{
	current_ = head;
}

template <typename T>
T List_iterator_<T>::operator *()
{
	return current_->data_;
}

template <typename T>
T List_iterator_<T>::operator ->()
{
	return &current_->data_();
}

template <typename T>
T& List_iterator_<T>::operator ++()
{
	current_ = current_->next_;
	return *this;
}

template <typename T>
const T List_iterator_<T>::operator ++(int)
{
	List_iterator_<T> temp = *this;
	current_ = current_->next_;
	return temp;
}

template <typename T>
T& List_iterator_<T>::operator ==(const T& rhs)
{

}

template <typename T>
T& List_iterator_<T>::operator !=(const T& rhs)
{

}


template <typename i>
struct List_const_iterator_
{
	typedef i 									value_type;
	typedef const i* 							pointer;
	typedef const i& 							reference;
	typedef std::ptrdiff_t 				difference_type;
	typedef std::forward_iterator_tag 	iterator_category;

	//defaultkonstruktor som s�tter iteratorn till "f�rbi-sista"
	List_const_iterator_<i>(List_iterator_<i> *iter);
	//konstruktor f�r att initiera med en pekare till en listnod
	//operator* ska returnera en referens till elementet i noden
	//operator-> ska returnera en pekare till elementet i noden
	//operator++ i b�de prefix och postfix version f�r att stegra iteratorn
	//operator== f�r att kontrollera om tv� iteratorer �r lika, eller inte
	//operator!= f�r att kontrollera om tv� iteratorer �r olika, eller inte
	//pekare till listnod, representationen f�r iteratorn
};

template<typename i>
List_const_iterator_<i>::List_const_iterator_(List_iterator_<i> *iter)
{
	this = iter;
}


template <typename T>
class List
{
public:
	typedef List_iterator_<T> iterator;
	typedef List_const_iterator_<T> const_iterator;
	//using size_type = std::size_t;
	typedef std::size_t size_type;

	List() = default;
	List(const List<T> & list); 									//kopieringskonsruktor
	List(List<T> && rightList)/* noexcept*/;						//flyttkonstruktor

	List(std::initializer_list<T> array);
	int size(std::initializer_list<T> array) {return array.size();}

	List<T> &operator=(const List<T> &) /*&*/; 						//kopieringstilldelningsoperator
	List<T> &operator=(List<T> &&) /*& noexcept*/;					//flytttilldelningsoperator

	iterator begin() {return iterator{head_};}
	const_iterator begin() const {return const_iterator{head_};}
	const_iterator cbegin() const noexcept {return const_iterator{nullptr};}
	iterator end() {return iterator{nullptr};}
	const_iterator end() const {return const_iterator{nullptr};}
	const_iterator cend() const noexcept {return const_iterator{nullptr};}


	~List() {delete head_;}

	void insert(T value);
	void append(T value);
	void remove(T value);
	void clear();
	size_type size() const;

	bool empty() const;
	bool member(T value) const;

	void print(std::ostream&, const std::string& delimiter = " ") const;
	void swap(List &) noexcept; 				//medlem: byter inneh�ll med annan lista

private:
	struct List_Node<T>* head_{ nullptr }; 		//creates empty node head_ that points to front of list
	List<T> copy(const List<T> &);

	//static List_Node* copy(const List_Node* list) { return list->clone(); }
};

template <typename T>
void swap(List<T> &,List<T> &) noexcept; 				//icke-medlem: byter inneh�ll p� tv� listor
}

#include "List.tcc"

#endif
