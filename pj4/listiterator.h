#ifndef LISTITERATOR_H
#define LISTITERATOR_H

template <typename> class List;   // required forward declaration

template <typename T>
class ListIterator {

	friend class List<T>;

	public:
		ListIterator();
		bool hasNext() const;
		bool hasPrevious() const;
		T &next() throw ( NoSuchObject );
		T &previous() throw ( NoSuchObject );
		void printInternal() const;

	private:
		Node<T> *current;
		bool before;

};

template <typename T>
ListIterator<T>::ListIterator() {
	current = NULL;
	before = true;
}

template <typename T>
bool ListIterator<T>::hasNext() const {

	bool b = true;

	if (before == false) {
		if ( current->getNextPtr() == NULL )
			b = false;
	} else {
		
	}

	return b;
}
  
template <typename T>
bool ListIterator<T>::hasPrevious() const {

	bool b = true;

	if (before == true) {
		if ( current->getPrevPtr() == NULL )
			b = false;
	}

	return b;
}

template <typename T>
T& ListIterator<T>::next() throw ( NoSuchObject ) {

	if ( !(current->getNextPtr() == NULL) ) {
	    throw NoSuchObject( "no such object exists in iterator" );
    }

    if (before == true) {
    	before = false;
    }

    if (before == false) {
    	current = current->getNextPtr();
    	before = true;
    }

    return ( current->getObject() );
}

template <typename T>
T& ListIterator<T>::previous() throw ( NoSuchObject ) {

	if ( !(current->getPrevPtr() == NULL) ) {
	    throw NoSuchObject( "no such object exists in iterator" );
    }

    if (before == true) {
    	current = current->getPrevPtr();
    	before = false;
    }

    if (before == false) {
    	before = true;
    }

    return ( current->getObject() );
}

template <typename T>
void ListIterator<T>::printInternal() const {
	// cout << "The iterator is currently at: " << current.
}

#endif