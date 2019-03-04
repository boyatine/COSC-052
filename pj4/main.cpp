#include "main.h"

int main() {

	try {

        List<int> myList;
        
        cout << "adding five objects to the list using addFirst..." << endl;
        myList.addFirst(20);
        myList.addFirst(80);
        myList.addFirst(5);
        myList.addFirst(3);
        myList.addFirst(1976);
        
        cout << "instantiating an iterator object (itr1), passing 0 as argument..." << endl;
        ListIterator<int> itr1 = myList.listIterator(0);
        
        cout << "using itr1 to traverse list and output value of all nodes:" << endl;
        while (itr1.hasNext())
        {
            cout << itr1.next() << " ";
        }
        cout << endl;

        cout << "instantiating an iterator object (itr2), passing no argument..." << endl;
        ListIterator<int> itr2 = myList.listIterator();
        
        cout << "using itr2 to output value of first node:" << endl;
        cout << itr2.next() << endl;
        cout << "using itr2 to output value of second node:" << endl;
        cout << itr2.next() << endl;
        cout << "using itr2 to output value of third node, then ";
        cout << "alternating calls to previous/next:" << endl;
        cout << itr2.next() << endl;
        cout << itr2.previous() << endl;
        cout << itr2.next() << endl;
        cout << itr2.previous() << endl;
        cout << itr2.next() << endl;
        cout << itr2.previous() << endl;
        
        cout << "using itr2 to output value of third-fifth nodes:" << endl;
        cout << itr2.next() << endl;
        cout << itr2.next() << endl;
        cout << itr2.next() << endl;
        
        cout << "using itr2 to call next when already at list end, ";
        cout << "should throw an exception:" << endl;
        cout << itr2.next() << endl;
        
        cout << "using itr2 to call previous when at list end, requires ";
        cout << "change of direction, should output value of last node:" << endl;
        cout << itr2.previous() << endl;
        
        cout << "instantiating an iterator object (itr3), passing 5 (size()) ";
        cout << "as argument..." << endl;
        ListIterator<int> itr3 = myList.listIterator(myList.size());
        
        cout << "using itr3 to call next when already at list end, ";
        cout << "should throw an exception:" << endl;
        cout << itr3.next() << endl;
        
        cout << "using itr3 to call previous, should output value of last node:";
        cout << endl;
        cout << itr3.previous() << endl;
        
    } catch (NoSuchObject &e) {
		cout << e.what() << endl;
	} catch (bad_alloc &e) {
		cout << "bad_alloc caught in main" << endl;
		cout << e.what() << endl;
	} catch (out_of_range &e) {
		cout << e.what() << endl; 
	} catch ( ... ) {
		cout << "unknown exception caught in main" << endl;
    }

	return 0;
}