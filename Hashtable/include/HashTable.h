#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>

template <class T>
class HashTable {
 private:
	class Node {
	private:
		T val;
		Node* next;

	public:
		Node(const T element);
		~Node();
		
		void append(const T element);
		inline const T getVal() { return val;};
		inline Node* getNext() { return next;};
	};

	Node** nodes;
	int size;

	const int hash(const T element);

 public:
	HashTable(int length = 1);
	~HashTable();

	void add(const T element);

	template <class U>
	friend std::ostream &operator<< (std::ostream& out, const HashTable<U> &list);
};

#include "HashTable.tpp"

#endif
