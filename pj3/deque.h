#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include "dlnode.h"
#include "nosuchobject.h"

template <typename T>
class Deque {

  public:
    Deque();
    Deque( const Deque<T>& ) throw ( bad_alloc );
    bool empty() const;
    unsigned size() const;
    void insertFront( const T& ) throw ( bad_alloc );
    void insertBack( const T& ) throw ( bad_alloc );
    T removeFront() throw ( NoSuchObject );
    T& front() const throw ( NoSuchObject );
    T removeBack() throw ( NoSuchObject );
    T& back() const throw ( NoSuchObject );
    const Deque<T> &operator=( const Deque<T>& ) throw ( bad_alloc );
    void clear();
    ~Deque();
    void printInternal() const;

  private:
    unsigned sz;
    DLNode<T>* frontPtr;
    DLNode<T>* backPtr;
    
    void initialize();

}; // Deque class

template <typename T>
void Deque<T>::initialize() {
    frontPtr = backPtr = NULL;
    sz = 0;
}

template <typename T>
Deque<T>::Deque() {
    initialize();
}

template <typename T>
bool Deque<T>::empty() const {
    return ( frontPtr == 0 );
    return ( backPtr == 0 );
    return (sz == 0);
}

template <typename T>
unsigned Deque<T>::size() const {
    return sz;
}

template <typename T>
void Deque<T>::insertFront( const T& object ) throw ( bad_alloc ) {
    DLNode<T> *newNode = new DLNode<T>(object);

    if ( frontPtr == 0 ) {
        frontPtr = backPtr = newNode;
    } else {
        newNode->setNextPtr(frontPtr);
        frontPtr->setPrevPtr(newNode);
        frontPtr = newNode;
    }

    sz++;
}

template <typename T>
void Deque<T>::insertBack( const T& object ) throw ( bad_alloc ) {
    DLNode<T> *newNode = new DLNode<T>(object);

    if ( backPtr == 0 ) {
        frontPtr = backPtr = newNode;
    } else {
        newNode->setPrevPtr(backPtr);
        backPtr->setNextPtr(newNode);
        backPtr = newNode;
    }

    sz++;
}

template <typename T>
T Deque<T>::removeFront() throw ( NoSuchObject ) {
    if ( empty() )
        throw NoSuchObject( "front is empty" );

    DLNode<T>* temp = frontPtr;

    frontPtr = frontPtr->getNextPtr();
    T object = temp->getObject();

    if ( frontPtr == 0 ) {
        backPtr = 0;
    } else {
        frontPtr->setPrevPtr(0);
    }

    sz--;

    return object;    
}

template <typename T>
T& Deque<T>::front() const throw ( NoSuchObject ) {
    if ( empty() ) 
        throw NoSuchObject( "front is empty" );

    return frontPtr->getObject();    
}

template <typename T>
T Deque<T>::removeBack() throw ( NoSuchObject ) {
    if ( empty() )
        throw NoSuchObject( "back is empty" );

    DLNode<T> *temp = backPtr;

    backPtr = backPtr->getPrevPtr();
    T object = temp->getObject();

    if ( backPtr == 0 ) {
        frontPtr = 0;
    } else {
        backPtr->setNextPtr(0);
    }

    sz--;

    return object;    
}

template <typename T>
T& Deque<T>::back() const throw ( NoSuchObject ) {
    if ( empty() ) 
        throw NoSuchObject( "back is empty" );

    return backPtr->getObject();    
}

template <typename T>
const Deque<T>& Deque<T>::operator=( const Deque<T> &s ) throw ( bad_alloc ) {
    if (&s != this) {
        if (!empty()) {
            clear();
        }
        sz = s.sz;

        Node<T> *sptr = s.frontPtr;
        Node<T> *temp = NULL;
        Node<T> *backPtr = NULL;

        while ( sptr != NULL ) {
            if (backPtr == NULL) {
                frontPtr = temp = backPtr = new DLNode<T>(*sptr);
            } else {
                temp = sptr;
                temp->getPrevPtr();
                backPtr->setNextPtr(new DLNode<T>(*sptr));
                backPtr = backPtr->getNextPtr();
                backPtr->setPrevPtr(temp);
            }

            sptr = sptr->getNextPtr();
            
        }
    }
    //     if ( s.frontPtr == 0 ) {
    //         frontPtr = backPtr = 0;
    //     } else {
    //         frontPtr = new DLNode<T>( *s.frontPtr );   
    //         DLNode<T> *sTemp = s.frontPtr->getNextPtr();
    //         DLNode<T> *temp = frontPtr;
    //         while ( sTemp != 0 ) {
    //             temp->setNextPtr( new DLNode<T>( *sTemp ) ); 
    //             temp = temp->getNextPtr();                                      
    //             sTemp = sTemp->getNextPtr();                          
    //         }

    //     backPtr = temp;
    //     }
    // }

    return *this;

//     Most of operator= is commented out.  What's commented out looks pretty good
// and is similar to what we discussed in class.

// The statement if s.frontPtr == 0 which assigns frontPtr and backPtr to
// null is unnecessary.  At that point in execution, frontPtr and backPtr
// are already null, regardless of s.frontPtr's value.

// The current implement doesn't set the previous pointers of the new nodes.
}

template <typename T>
Deque<T>::Deque( const Deque<T>& s ) throw ( bad_alloc ) {
    initialize();
    *this = s;
}

template <typename T>
void Deque<T>::clear() 
{
  DLNode<T> *temp = frontPtr;
  while (frontPtr != 0) {
    frontPtr = frontPtr->getNextPtr();
    delete temp;
    temp = frontPtr;
  }
  sz = 0;
  backPtr = 0;
}


template <typename T>
Deque<T>::~Deque() {
    this->clear();
}

template <typename T>
void List<T>::printInternal() const {
    DLNode<T>* current = frontPtr;
    int i = 0;
    cout << "front: " << frontPtr << endl;
    cout << "back: " << backPtr << endl;
    while ( current != 0 ) {
    cout << "Node " << i << endl;
    cout << "  address: " << current << endl;
    cout << "  object: " << current->getObject() << endl;
    cout << "  previous: " << current->getPrevPtr() << endl;
    cout << "  next: " << current->getNextPtr() << endl;
    current = current->getNextPtr();
    i++;
    }
}

#endif