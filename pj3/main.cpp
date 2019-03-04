#include "main.h"

int main() {
	Stack<string> s;
	Deque<string> d;
	Deque<string> e;

	try {
		// s.push(" world");
		// s.push("hello");
		// while (true) {
		// 	cout << s.pop() << endl;
		// }

		// d.insertFront(124);
		d.insertBack("abc");
		// d.removeBack();

		// e.printInternal();
		// d.insertFront(1);
		// d.removeFront();
		// d.insertBack(3123);
		// d.insertFront(99999);


		d.removeBack();
		d.insertFront("hi");

		d.printInternal();


		e = d;



		e.printInternal();

		cout << e.back() << endl;

		// e.removeFront();

		// e.printInternal();

		e.removeBack();

		e.insertFront("dog");

		e.insertBack("cat");

		e.printInternal();

		
	} catch (NoSuchObject &e) {
		cout << e.what() << endl;
	} catch ( bad_alloc &e ) {
		cout << "bad_alloc caught in main" << endl;
		cout << e.what() << endl;
	} catch ( ... ) {
		cout << "unknown exception caught in main" << endl;
	}

	return 0;
}