#include <cxxtest/TestSuite.h>
#include "ArrayList.h"

class TestArrayList : public CxxTest::TestSuite {
public:
	void testGet(void) {
		int len = 4;
		int arr[len] = {1, 2, 3, 4};
		ArrayList<int> list(arr, len);
		TS_ASSERT_EQUALS(list.get(0), arr[0]);
		TS_ASSERT_EQUALS(list.get(1), arr[1]);
		TS_ASSERT_EQUALS(list.get(2), arr[2]);
		TS_ASSERT_EQUALS(list.get(3), arr[3]);
	}
	
	void testAppend(void) {
		ArrayList<int> list;
		list.add(3);
		TS_ASSERT_EQUALS(list.get(0), 3);
		list.add(4);
		TS_ASSERT_EQUALS(list.get(0), 3);
		TS_ASSERT_EQUALS(list.get(1), 4);
	}

	void testAdd(void) {
		ArrayList<int> list;
		list.add(0, 2);
		TS_ASSERT_EQUALS(list.get(0), 2);
		list.add(0, 1);
		TS_ASSERT_EQUALS(list.get(0), 1);
		TS_ASSERT_EQUALS(list.get(1), 2);
		list.add(1, 4);
		TS_ASSERT_EQUALS(list.get(0), 1);
		TS_ASSERT_EQUALS(list.get(1), 4);
		TS_ASSERT_EQUALS(list.get(2), 2);
		list.add(5);
		TS_ASSERT_EQUALS(list.get(0), 1);
		TS_ASSERT_EQUALS(list.get(1), 4);
		TS_ASSERT_EQUALS(list.get(2), 2);
		TS_ASSERT_EQUALS(list.get(3), 5);
	}
};
