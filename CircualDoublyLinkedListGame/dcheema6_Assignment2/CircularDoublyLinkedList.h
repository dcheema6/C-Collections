#pragma once
#include<iostream>

using std::cout;

template<class T>
class CDLL
{
public:
	struct Node
	{
		T value;
		Node* next;
		Node* previous;
		Node(T val, Node* nxt = nullptr, Node* prv = nullptr) :value(val), next(nxt), previous(prv) {}
	};
private:
	unsigned _size;
	Node* _head;
	Node* _tail;
public:
	CDLL(); // construct an empty CDL list
	CDLL(const CDLL<T> &other);
	~CDLL();     // destroy a CDL list
	void addHead(T item);
	void addTail(T item);  // adds item to end of list or one can say before _head in this case
	void removeHead();
	void removeTail();
	T retrieveHead() const;
	T retrieveTail() const;
	T retrieve(unsigned n) const; // Return the item value from the node in position n

	void swap(unsigned a, unsigned b); //Swap the two values stored at a and b location
	void left(); //shift head to right on chain ie shifts the chain to left by one element
	void right(); //shift head to left on chain ie shifts the chain o right by one element
	void add(unsigned int n, T item);

	void remove(unsigned int n);
	void replace(unsigned int n, T item);
	bool isEmpty() const;
	unsigned int size() const;

	class Iterator {
	private:
		Node* m_ptr;
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator++ () { m_ptr = m_ptr->next; }
		bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
		T operator *() { return m_ptr->value; }
		T getValue() { return m_ptr->value; }
		void setValue(T val) { m_ptr->value = val; }
	};

	Iterator begin() { return Iterator(m_head); }
	Iterator end() { return Iterator(nullptr); }

};

template<class T>
CDLL<T>::CDLL() : _size(0), _head(nullptr), _tail(nullptr) {}

template <class T>
CDLL<T>::CDLL(const CDLL<T> &other) {

	if (other.m_size == 0) {
		_head = nullptr;
		_tail = nullptr;
		_size = 0;
	}
	else {
		_size = other.m_size;
		_head = new Node(other._head->value, nullptr);
		if (other._tail == nullptr) {
			_tail = _head;
		}
		else {
			Node * copyFrom = other._head->next;
			Node *nextNode = _head;

			while (copyFrom != nullptr) {
				nextNode->next = new Node(copyFrom->value);
				copyFrom = copyFrom->next;
				nextNode = nextNode->next;
			}
			_tail = nextNode;
		}

	}
}


template<class T>
CDLL<T>::~CDLL()
{
	Node * here = _head, *nextNode;
	unsigned n = 0;
	while (n != _size&&here != nullptr)
	{
		nextNode = here->next;
		delete here;
		here = nextNode;
		n++;
	}
	_head = nullptr;
}

template<class T>
void CDLL<T>::addTail(T item)
{
	if (_head == nullptr&&_tail == nullptr)
	{
		_head = new Node(item);
	}
	else if (_head != nullptr&&_tail == nullptr)
	{
		_tail = new Node(item);
		_head->next = _head->previous = _tail;
		_tail->next = _tail->previous = _head;
	}
	else
	{
		Node* n = _tail;
		_tail = new Node(item);
		n->next = _tail;
		_tail->previous = n;
		_tail->next = _head;
		_head->previous = _tail;
	}
	_size++;
}

template<class T>
void CDLL<T>::addHead(T item)
{
	if (_head == nullptr)
	{
		_head = new Node(item);
	}
	else if (_tail == nullptr&&_head != nullptr)
	{
		_tail = _head;
		_head = new Node(item);
		_tail->next = _tail->previous = _head;
		_head->next = _head->previous = _tail;
	}
	else
	{
		Node*n = _head;
		_head = new Node(item);
		_tail->next = _head;
		n->previous = _head;
		_head->next = n;
		_head->previous = _tail;
	}
	_size++;
}

template<class T>
T CDLL<T>::retrieve(unsigned n) const
{
	if (n == 1) return _head->value;
	if (n == _size) return _tail->value;
	Node * here = _head;
	for (unsigned k = 1; k < n; k++) here = here->next;
	return here->value;
}

template<class T>
void CDLL<T>::swap(unsigned a, unsigned b)
{
	Node* n1 = _head;
	Node* n2 = _head;
	for (unsigned k = 1; k < a; k++) n1 = n1->next;
	for (unsigned k = 1; k < b; k++) n2 = n2->next;
	unsigned i = n1->value;
	n1->value = n2->value;
	n2->value = i;
}

template<class T>
void CDLL<T>::left()
{
	_head = _head->next;
	_tail = _tail->next;
}

template<class T>
void CDLL<T>::right()
{
	_head = _head->previous;
	_tail = _tail->previous;
}

template<class T>
void CDLL<T>::removeHead()
{
	if (_head==nullptr)
	{
		cout << "List is Empty\n";
		return;
	}
	Node* n = _head;
	_head = _head->next;
	_head->previous = _tail;
	_tail->next = _head;
	delete n;
	_size--;
}

template<class T>
void CDLL<T>::removeTail()
{
	if (_tail == nullptr)
	{
		cout << "Only one element in in the list\n";
		return;
	}
	Node* n = _tail;
	_tail = _tail->previous;
	_tail->next = _head;
	_head->previous = _tail;
	delete n;
	_size--;
}

template<class T>
T CDLL<T>::retrieveHead() const
{
	return _head->value;
}

template<class T>
T CDLL<T>::retrieveTail() const
{
	return _tail->value;
}

template<class T>
void CDLL<T>::add(unsigned int n, T item)
{
	Node* prev = _head;Node* next = _head;
	for (unsigned i = 2; i < n; i++) prev = prev->next;
	for (unsigned i = 1; i < n; i++) next = next->next;
	Node* New = new Node(item);
	prev->next = New; New->previous = prev;
	next->previous = New; New->next = next;
	_size++;
}

template<class T>
void CDLL<T>::remove(unsigned int n)
{
	Node* prev = _head; Node* next = _head;
	for (unsigned i = 2; i < n; i++) prev = prev->next;
	for (unsigned i = 1; i < n; i++) next = next->next;
	Node* del = next;
	next = next->next;
	delete del;
	prev->next = next;
	next->previous = prev;
	_size--;
}

template<class T>
void CDLL<T>::replace(unsigned int n, T item)
{
	Node* New = _head;
	for (unsigned i = 1; i < n; i++) New = New->next;
	New->value = item;
}

template<class T>
bool CDLL<T>::isEmpty() const
{
	if (_head == nullptr) return true;
	else return false;
}

template<class T>
unsigned int CDLL<T>::size() const
{
	Node* New = _head->next;
	unsigned n = 1;
	while (New != _head)
	{
		New = New->next;
		n++;
	}
	return n;
}