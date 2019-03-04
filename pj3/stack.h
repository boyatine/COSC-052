#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include "node.h"
#include "nosuchobject.h"

using namespace std;

template <typename T>
class Stack {

     public:
          Stack(); //
          Stack( const Stack<T>& s ) throw ( bad_alloc ); //
          bool empty() const; //
          unsigned size() const; //
          T& top() const throw ( NoSuchObject ); //
          T pop() throw ( NoSuchObject ); //
          void push( const T& ) throw ( bad_alloc ); //
          const Stack<T>& operator=( const Stack<T>& ) throw ( bad_alloc );
          void printInternal() const; //
          void clear(); //
          ~Stack(); //

     private:
          unsigned sz;
          Node<T>* topPtr;

          void initialize(); //

}; // Stack<T> class

template <typename T>
void Stack<T>::initialize() {
     topPtr = 0;
     sz = 0;
}

template <typename T>
Stack<T>::Stack() {
     initialize();
}

template <typename T>
bool Stack<T>::empty() const {
     return( topPtr == 0 );
     return( sz == 0 );
}

template <typename T>
unsigned Stack<T>::size() const {
     return sz;
}

template <typename T>
T& Stack<T>::top() const throw ( NoSuchObject ) {
     if ( empty() ) 
          throw NoSuchObject( "top stack is empty" );
     
     return topPtr->getObject();
}

template <typename T>
void Stack<T>::push( const T& object ) throw ( bad_alloc ) {
     Node<T> *newNode = new Node<T>(object);
     newNode->setNextPtr(topPtr);
     topPtr = newNode;
     sz++;
}

template <typename T>
T Stack<T>::pop() throw ( NoSuchObject ) {
     if ( empty() )
          throw NoSuchObject( "top stack is empty" );

     Node<T> *ptr = topPtr;
     topPtr = topPtr->getNextPtr();
     T object = ptr->getObject();
     delete ptr;
     sz--;

     return object;
}

template <typename T>
const Stack<T>& Stack<T>::operator=( const Stack<T> &s ) throw ( bad_alloc ) {
     if (&s != this) {
          if (!empty()) {
               clear();
          }
          sz = s.sz;
          Node<T> *sptr = s.topPtr, *last = NULL;

          while ( sptr != NULL ) {
               if (last == NULL) {
                    topPtr = last = new Node<T>(*sptr);
               } else {
                    last->setNextPtr(new Node<T>(*sptr));
                    last = last->getNextPtr();
               }

               sptr = sptr->getNextPtr();
          }
     }

     return *this;
}

template <typename T>
Stack<T>::Stack( const Stack<T>& s ) throw ( bad_alloc ) {
     initialize();
     *this = s;
}

template <typename T>
void Stack<T>::printInternal() const
{
  Node<T>* current = topPtr;
  int i = 0;
  cout << "top: " << topPtr << endl;
  while ( current != 0 ) {
    cout << "Node " << i << endl;
    cout << "  address: " << current << endl;
    cout << "  object: " << current->getObject() << endl;
    cout << "  next: " << current->getNextPtr() << endl;
    current = current->getNextPtr();
    i++;
  } // while
} // Stack<T>::printInternal

template <typename T>
void Stack<T>::clear() {
     while ( !empty() )
          this->pop();
     
     topPtr = NULL;
     sz = 0;
}

template <typename T>
Stack<T>::~Stack() {
     this->clear();
}

#endif