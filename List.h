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

	//defaultkonstruktor som sätter iteratorn till "förbi-sista"
	List_iterator_() : node_() {}

	//konstruktor för att initiera med en pekare till en listnod
	List_iterator_(List_Node<T>* n) : node_(n) {}

	//operator* ska returnera en referens till elementet i noden
	reference operator*() const {return (node_->data_);}

	//operator-> ska returnera en pekare till elementet i noden
	pointer operator->() const {return &(node_->data_);}

	//operator++ i både prefix och postfix version för att stegra iteratorn
	List_iterator_<T>& operator++()
			{
		node_ = node_->next_;
		return *this;
			}
	List_iterator_<T> operator++(int)
			{
		List_iterator_ temp_ = *this;
		node_ = node_->next_;
		return temp_;
			}

	//operator== för att kontrollera om två iteratorer är lika, eller inte
	bool operator==(const List_iterator_& rhs) const
		{
		return node_ == rhs.node_;
		}

	//operator!= för att kontrollera om två iteratorer är olika, eller inte
	bool operator!=(const List_iterator_& rhs) const
		{
		return node_ != rhs.node_;
		}

	//pekare till listnod, representationen för iteratorn
	linked_list::List_Node<T>* node_;
};

template <typename T>
struct List_const_iterator_
{
	typedef const List_Node<T>					c_node;

	typedef T 									value_type;
	typedef const T* 							pointer;
	typedef const T& 							reference;
	typedef std::ptrdiff_t 				difference_type;
	typedef std::forward_iterator_tag 	iterator_category;

	//defaultkonstruktor som sätter iteratorn till "förbi-sista"
//	List_const_iterator_<T>(List_iterator_<T> *iter);
	//List_const_iterator_() : node_() {}
	List_const_iterator_(const List_iterator_<T>& iter) : node_(iter.node_) {}

	//konstruktor för att initiera med en pekare till en listnod
	List_const_iterator_(const List_Node<T>* n) : node_(n) {}

	//operator* ska returnera en referens till elementet i noden
	reference operator*() const {return static_cast<c_node*>(node_)->data_;}

	//operator-> ska returnera en pekare till elementet i noden
	pointer operator->() const {return &(static_cast<c_node*>(node_)->data_);}

	//operator++ i både prefix och postfix version för att stegra iteratorn
	List_const_iterator_<T>& operator++()
		{
		node_ = node_->next_;
		return *this;
		}

	List_const_iterator_<T> operator++(int)
		{
		List_const_iterator_<T> temp = *this;
		node_ = node_->next_;
		return temp;
		}

	//operator== för att kontrollera om två iteratorer är lika, eller inte
	bool operator==(const List_const_iterator_<T>& rhs) const
		{
		return node_ == rhs.node_;
		}

	//operator!= för att kontrollera om två iteratorer är olika, eller inte
	bool operator!= (const List_const_iterator_<T>& rhs)const
		{
		return node_ != rhs.node_;
		}

	//pekare till listnod, representationen för iteratorn
	const linked_list::List_Node<T>* node_;
};

template<typename t>
inline bool operator==(const List_iterator_<t>& lhs, const List_const_iterator_<t>& rhs)
{
	return lhs.node_ == rhs.node_;
}

template<typename t>
inline bool operator!=(const List_iterator_<t>& lhs, const List_const_iterator_<t>& rhs)
{
	return lhs.node_ != rhs.node_;
}

template <typename T>
class List
{
public:
	typedef List_iterator_<T> 					iterator;
	typedef List_const_iterator_<T> 		const_iterator;
	typedef std::size_t 						size_type;
	//using size_type = std::size_t;


	List() = default;
	List(const List<T> & list); 									//kopieringskonsruktor
	List(List<T> && rightList)/* noexcept*/;						//flyttkonstruktor

	List(std::initializer_list<T> array);
//	int size(std::initializer_list<T> array) {return array.size();}

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

	int size() const;

	bool empty() const;
	bool member(T value) const;

	void print(std::ostream&, const std::string& delimiter = " ") const;
	void swap(List<T> &) noexcept; 				//medlem: byter innehåll med annan lista

private:
	struct List_Node<T>* head_{ nullptr }; 		//creates empty node head_ that points to front of list
	List<T> copy(const List<T> &);

	//static List_Node* copy(const List_Node* list) { return list->clone(); }
};

template <typename T>
void swap(List<T> &,List<T> &) noexcept; 				//icke-medlem: byter innehåll på två listor
}

#include "List.tcc"

#endif
