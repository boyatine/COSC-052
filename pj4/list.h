#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include "node.h"
#include "nosuchobject.h"
#include "listiterator.h"

template <typename T>
class List;

template <typename T>
ostream &operator<<( ostream &, const List<T> & );

template <typename T>
class List {

  friend ostream &operator<< <>( ostream &, const List<T> & ); ////////////

  public:
    List();//////////
    List( const List<T> & ) throw ( bad_alloc ); //////////
    ~List(); ////////////

    void add( unsigned, const T & ) throw ( bad_alloc, out_of_range ); ////////
    void addAll( const List<T> & ) throw ( bad_alloc ); ////////
    void addAll( unsigned, const List<T> & ) throw ( bad_alloc, out_of_range ); ///////////
    void addFirst( const T & ) throw ( bad_alloc ); //////////
    void addLast( const T & ) throw ( bad_alloc ); /////////
    void clear(); //////////
    bool contains( const T & ) const; ////////////////
    bool empty() const;//////////////
    int indexOf( const T & ) const; ////////////
    T &get( unsigned ) const throw ( out_of_range ); ////////
    T &getFirst() const throw ( NoSuchObject ); //////////
    T &getLast() const throw ( NoSuchObject ); ////////////
    ListIterator<T> listIterator(); 
    ListIterator<T> listIterator( unsigned ) throw ( out_of_range );
    T remove( unsigned ) throw ( out_of_range ); ///////////
    T removeFirst() throw ( NoSuchObject ); //////////
    T removeFirstOccurrence( const T & ) throw ( NoSuchObject ); /////////
    T removeLast() throw ( NoSuchObject ); /////////////
    T removeLastOccurrence( const T & ) throw ( NoSuchObject ); ////////
    T set( unsigned, const T & ) throw ( out_of_range ); //////
    unsigned size() const; /////////
    T *toArray() const throw ( bad_alloc ); /////////
    const List<T> &operator=( const List<T> & ) throw ( bad_alloc ); /////////
    void printInternal( ostream & = cout ); ////////////

  private:
    Node<T> *frontPtr, *backPtr;
    unsigned sz;

    void add( Node<T> *, const T & ) throw ( bad_alloc ); /////////
    void initialize(); //////////
    Node<T> *getIthNode( unsigned ) const throw ( out_of_range ); //////////
    T remove( Node<T> * ); //////////

}; // List class

template <typename T>
void List<T>::initialize() {
    frontPtr = backPtr = NULL;
    sz = 0;
}

template <typename T>
List<T>::List() {

    initialize();
}

template <typename T>
void List<T>::addFirst( const T& object ) throw ( bad_alloc ) {

    Node<T> *newNode = new Node<T>(object);

    if ( empty() ) {
        frontPtr = backPtr = newNode;
    } else {
        newNode->setNextPtr(frontPtr);
        frontPtr->setPrevPtr(newNode);
    }

    frontPtr = newNode;
    sz++;
}

template <typename T>
void List<T>::addLast( const T& object ) throw ( bad_alloc ) {         
    
    Node<T> *newNode = new Node<T>(object);

    if ( empty() ) {
        frontPtr = backPtr = newNode;
    } else {
        newNode->setPrevPtr(backPtr);
        backPtr->setNextPtr(newNode);
    }

    backPtr = newNode;
    sz++;
}

template <typename T>
T List<T>::removeFirst() throw ( NoSuchObject ) {

    if ( empty() )
        throw NoSuchObject( "front is empty" );

    Node<T>* temp = frontPtr;
    T object = temp->getObject();

    frontPtr = frontPtr->getNextPtr();

    if ( frontPtr == NULL ) {
        backPtr = NULL;
    } else {
        frontPtr->setPrevPtr(NULL);
    }

    sz--;

    return object;   
}

template <typename T>
T List<T>::removeLast() throw ( NoSuchObject ) {

    if ( empty() )
        throw NoSuchObject( "front is empty" );

    Node<T>* temp = backPtr;
    T object = temp->getObject();

    backPtr = backPtr->getPrevPtr();

    if ( backPtr == NULL ) {
        frontPtr = NULL;
    } else {
        backPtr->setNextPtr(NULL);
    }

    sz--;

    return object;   
}

template <typename T>
T& List<T>::getFirst() const throw ( NoSuchObject ) {

    if ( empty() ) {
        throw NoSuchObject( "front is empty" );
    }

    return ( frontPtr->getObject() );    
}

template <typename T>
T& List<T>::getLast() const throw ( NoSuchObject ) {

    if ( empty() ) {
        throw NoSuchObject("list is empty");
    }

    return ( backPtr->getObject() );
}

template <typename T>
Node<T>* List<T>::getIthNode( unsigned index ) const throw ( out_of_range ) {

    if ( frontPtr == NULL || index >= sz ) {
        throw out_of_range( "the index could not be found" );
    }

    Node<T> *temp = frontPtr;

    for ( unsigned i = 0; i < index; i++ ) {
        temp = temp->getNextPtr();
    }

    return temp;
}

template <typename T>
void List<T>::add( unsigned index, const T & object ) throw ( bad_alloc, out_of_range ) {
    
    if ( frontPtr == NULL || index >= sz)
        throw out_of_range( "the index could not be found" );

    Node<T> *current = getIthNode(index);

    this->add(current, object);
}

template <typename T>
void List<T>::add( Node<T> *current, const T & object ) throw ( bad_alloc ) {

    if ( current == frontPtr )
        this->addFirst(object);
    else if ( current == backPtr )
        this->addLast(object);
    else {
        Node<T> *newNode = new Node<T>(object);
        Node<T> *beforeAdd = current->getPrevPtr();

        newNode->setPrevPtr(beforeAdd);
        newNode->setNextPtr(current);

        beforeAdd->setNextPtr(newNode);
        current->setPrevPtr(newNode);

        sz++;
    }    
}

template <typename T>
void List<T>::addAll( const List<T> & list ) throw ( bad_alloc ) {

    Node<T> *current = list.frontPtr;

    while ( current != NULL ) {
        this->addLast(current->getObject());
        current = current->getNextPtr();
    }   
}

template <typename T>
void List<T>::addAll( unsigned index, const List<T> & list ) throw ( bad_alloc, out_of_range ) {

    if ( frontPtr == NULL || index >= sz )
        throw out_of_range( "the index could not be found" );

    Node<T> *newNode = list.frontPtr;

    while ( newNode != NULL ) {
        this->add(index, newNode->getObject());
        newNode = newNode->getNextPtr();
        index++;
    }
}

template <typename T>
T List<T>::remove( unsigned index ) throw ( out_of_range ) {

    if ( frontPtr == NULL || index >= sz )
        throw out_of_range( "the index could not be found" );

    Node<T> *current = getIthNode(index);
    T object = this->remove(current);

    return object;
}

template <typename T>
T List<T>::remove( Node<T> *current ) {

    if ( current == frontPtr ) {
        this->removeFirst();
    } else if ( current == backPtr ) {
        this->removeLast();
    } else {
        T object = current->getObject();
        Node<T>* beforeCurrent = current->getPrevPtr();
        Node<T>* afterCurrent = current->getNextPtr();
        
        beforeCurrent->setNextPtr(afterCurrent);
        afterCurrent->setPrevPtr(beforeCurrent);

        // is this necessary
        current->setPrevPtr(NULL);
        current->setNextPtr(NULL);

        sz--;

        return object;
    }
}

template <typename T>
T List<T>::removeFirstOccurrence( const T & object ) throw ( NoSuchObject ) {

    Node<T> *current = frontPtr;
    T removed;

    while ( current != NULL ) {
        if ( current->getObject() == object )
            removed = current->getObject();
            remove(current);
            break;

        current = current->getNextPtr();
    }

    return removed;
}

template <typename T>
T List<T>::removeLastOccurrence( const T & object ) throw ( NoSuchObject ) {

    Node<T> *current = backPtr;
    T removed;

    while ( current != NULL ) {
        if ( current->getObject() == object )
            removed = current->getObject();
            remove(current);
            break;

        current = current->getPrevPtr();
    }    

    return removed;
}

template <typename T>
bool List<T>::empty() const {

    return ( frontPtr == NULL );
}

template <typename T>
int List<T>::indexOf( const T & object ) const {

    Node<T> *temp = frontPtr;
    int index = 0;

    while ( temp != NULL ) {
        if ( temp->getObject() == object )
            return index;

        temp = temp->getNextPtr();
        index++;
    }

    return -1;
}

template <typename T>
unsigned List<T>::size() const {

    return sz;
}

template <typename T>
T& List<T>::get( unsigned index ) const throw ( out_of_range ) {

    if ( empty() || index >= sz ) {
        throw out_of_range( "the index could not be found" );
    }

    return ( getIthNode(index)->getObject() );
}

template <typename T>
void List<T>::clear() {

    Node<T> *temp = frontPtr;

    while (frontPtr != NULL) {
        frontPtr = frontPtr->getNextPtr();
        delete temp;
        temp = frontPtr;
    }

    sz = 0;
    backPtr = NULL;
}

template <typename T>
T List<T>::set( unsigned index, const T & object ) throw ( out_of_range ) {

    if ( frontPtr == NULL || index >= sz )
        throw out_of_range( "the index could not be found" );

    Node<T> *current = getIthNode(index);
    T removed = current->getObject();

    if ( current == frontPtr ) {
        this->removeFirst();
        this->addFirst(object);
    } else if ( current == backPtr ) {
        this->removeLast();
        this->addLast(object);
    } else {
        this->remove(index);
        this->add(index, object);
    }

    return removed;
}

template <typename T>
T* List<T>::toArray() const throw ( bad_alloc ) {

    int size = static_cast<int>(this->size());
    T array[size];

    Node<T> *current = frontPtr;

    while ( current != NULL ) {
        for ( int i = 0; i < size; i++ ) {
            T currentObj = current->getObject();
            array[i] = currentObj;
        }

        current = current->getNextPtr();
    }

    return array;
}

template <typename T>
bool List<T>::contains( const T& object ) const {

// I could make this faster by checking the ends before looping?
    Node<T> *temp = frontPtr;
    bool b = false;

    while ( temp != NULL ) {
        if (temp->getObject() == object)
            b = true;
            return b;

        temp = temp->getNextPtr();
    }
}

template <typename T>
ListIterator<T> List<T>::listIterator() {

    ListIterator<T> li;

    return li;
}

template <typename T>
ListIterator<T> List<T>::listIterator( unsigned index ) throw ( out_of_range ) {

    ListIterator<T> li;
    li.current = getIthNode(index);

    return li;
}

template <typename T>
List<T>::List( const List<T>& s ) throw ( bad_alloc ) {

    List();
    *this = s;
}

template <typename T>
List<T>::~List() {

    this->clear();
}

template <typename T>
void List<T>::printInternal( ostream &out ) {

    Node<T>* current = frontPtr;
    unsigned i = 0;
    cout << "front: " << frontPtr << endl;
    cout << "back: " << backPtr << endl;
    while ( current != NULL ) {
        cout << "Node " << i << endl;
        cout << "  address: " << current << endl;
        cout << "  object: " << current->getObject() << endl;
        cout << "  previous: " << current->getPrevPtr() << endl;
        cout << "  next: " << current->getNextPtr() << endl;
        current = current->getNextPtr();
        i++;
    }
}

template <typename T>
ostream &operator<<( ostream &out, const List<T> &list ) {
    
    Node<T> *current = list.frontPtr;

    out << "[";
    while ( current!= NULL ) {
        out << current->getObject() << ",";
    }
    out << "]" << endl;

    return out;
}

template <typename T>
const List<T>& List<T>::operator=( const List<T>& list ) throw ( bad_alloc ) {
    if ( &list != this ) {
        if ( !empty() )
            clear();

        sz = list.sz;

        this->addAll(list);
    }

    return *this;
}

#endif