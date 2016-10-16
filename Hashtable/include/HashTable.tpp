#include "HashTable.h"
#include <iostream>

template <class T>
HashTable<T>::Node::Node(const T element) {
	next = nullptr;
	val = element;
}

template <class T>
HashTable<T>::Node::~Node() {
	if(next != nullptr) {
		delete next;
	}
}

template<class T>
void HashTable<T>::Node::append(const T element) {
	Node* n = this;
	while(n->next != nullptr) {
		n = n -> next;
	}
	n->next = new Node(element);
}

template <class T>
HashTable<T>::HashTable(int length) {
	nodes = new Node*[length];
	size = length;
	for(int i = 0; i < length; i++) {
		nodes[i] = nullptr;
	}
}

template <class T>
HashTable<T>::~HashTable() {
	for(int i = 0; i < size; i++) {
		delete nodes[i];
	}
	delete[] nodes;
}

template <class T>
void HashTable<T>::add(const T element) {
	int h = hash(element);
	if(nodes[h] == nullptr) {
		nodes[h] = new Node(element);
	} else {
		nodes[h]->append(element);
	}
}

template <class T>
const int HashTable<T>::hash(const T element) {
	return element % size;
}

template <class T>
std::ostream &operator<< (std::ostream &out, const HashTable<T> &list) {
	for(int i = 0; i < list.size; i++) {
		typename HashTable<T>::Node* n = list.nodes[i];
		while(n != nullptr) {
			out << n->getVal() << " ";
			n = n->getNext();
		}
		out << "\n";
	}
	return out;
}
