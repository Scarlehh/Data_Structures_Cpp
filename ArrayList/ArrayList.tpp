/*
 * ArrayList.cpp
 *
 *  Created on: 6 Feb 2016
 *      Author: scarlett
 */

#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(int length) : size(length) {
	array = new T[length];
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete array;
}

template <class T>
std::ostream& operator<< (std::ostream& out, ArrayList<T> &list) {
	if(list.getSize() == 0) {
		out << "No list\n";
	} else {
		for(int i = 0; i < list.getSize(); i++) {
			out << list.getPos(i) << " ";
		}
		out << "\n";
	}
	return out;
}
