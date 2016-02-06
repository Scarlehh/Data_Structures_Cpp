/*
 * ArrayList.h
 *
 *  Created on: 6 Feb 2016
 *      Author: scarlett
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <ostream>

template <class T>
class ArrayList {
	private:
		T* array;
		int size;

	public:
		ArrayList(int length = 0);
		virtual ~ArrayList();
		int getSize() { return size; };
		T getPos(int index) { return array[index]; }

		template <class U>
		friend std::ostream& operator<< (std::ostream& out, ArrayList<U>& list);
};

#include "ArrayList.tpp"

#endif /* ARRAYLIST_H_ */
