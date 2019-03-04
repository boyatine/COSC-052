#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <new>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector 
{
    public:
        Vector(); // YES
        Vector( const unsigned ) throw ( bad_alloc ); // YES
        Vector( const unsigned, const T& ) throw ( bad_alloc ); // YES
        Vector( const Vector<T> & ) throw ( bad_alloc );
        ~Vector(); // YES
        void assign( const unsigned, const T& ) throw ( out_of_range ); // YES
        T& at( const unsigned ) const throw ( out_of_range ); // YES
        unsigned capacity() const; // YES
        void clear(); // YES
        bool empty() const; // YES
        void insert( const unsigned, const T& ) throw ( bad_alloc, out_of_range ); // YES
        T& operator[]( const unsigned ) const throw ( out_of_range ); // YES
        const Vector<T> &operator=( const Vector<T>& ) throw ( bad_alloc );
        void push_back( const T& ) throw ( bad_alloc ); // YES
        void resize( const unsigned, const T& = T() ) throw ( bad_alloc ); // YES
        unsigned size() const; // YES
        void sort();
        void remove( const unsigned ) throw ( out_of_range ); // YES

    private:
        T* contents;
        unsigned sz;
        unsigned cap;

        void increaseCapacity() throw ( bad_alloc ); // YES
}; // Vector<T> class

////////////////////////////////////Constructors & Destructors/////////////////////////////////////

template <typename T>
Vector<T>::Vector()
{
    sz = 0;
    cap = 10;
    contents = new T[cap];
}

template <typename T>
Vector<T>::Vector( const unsigned cap ) throw ( bad_alloc )
{
    sz = 0;
    this->cap = cap;
    contents = new T[cap];
}

template <typename T>
Vector<T>::Vector( const unsigned sz, const T& object ) throw ( bad_alloc )
{
    this->sz = sz;
    cap = sz;
    contents = new T[cap];

    for ( unsigned i = 0; i < sz; i++ )
        contents[i] = object;
}

template <typename T>
Vector<T>::Vector( const Vector<T> & vector ) throw ( bad_alloc ) 
{
    Vector();
    *this = vector;
}

template <typename T>
Vector<T>::~Vector()
{
    delete [] contents;
    clear();
    cap = 0;
}

/////////////////////////////////////////Member Functions//////////////////////////////////////////

template <typename T>
void Vector<T>::assign( const unsigned i, const T & object ) throw ( out_of_range ) 
{
    if ( i >= sz )
        throw out_of_range( "the index could not be found" );

    contents[i] = object;

    sz++;
}

template <typename T>
T& Vector<T>::at( const unsigned i ) const throw ( out_of_range )
{
    if ( i >= sz ) 
        throw out_of_range( "the index could not be found" );
    

    return contents[i];
}

template <typename T>
unsigned Vector<T>::capacity() const
{
    return cap;
}

template <typename T>
void Vector<T>::clear()
{
    sz = 0;
}

template <typename T>
bool Vector<T>::empty() const
{
    return sz == 0;
}

template <typename T>
void Vector<T>::increaseCapacity() throw ( bad_alloc )
{
    unsigned oldsz = sz;
    resize(cap * 2);
    sz = oldsz;
}

template <typename T>
void Vector<T>::insert( const unsigned i, const T & object ) throw ( bad_alloc, out_of_range )
{
    if ( i >= sz )
        throw out_of_range( "the index could not be found" );

    if ( sz == cap )
        increaseCapacity();

    for ( unsigned c = sz - 1; c >= i ; --c )
        contents[c+1] = contents[c];

    contents[i] = object;

    sz++;
}

template <typename T>
const Vector<T>& Vector<T>::operator=( const Vector<T> & vector ) throw ( bad_alloc )
{
    if ( &vector != this ) {
        if ( !empty() )
            clear();

        sz = vector.sz;
        cap = vector.cap;

        for ( unsigned i = 0; i < sz ; i++ )
            contents[i] = vector[i];
    }
    
    return *this;
}

template <typename T>
T& Vector<T>::operator[]( const unsigned i ) const throw ( out_of_range )
{
    return at(i);
}

template <typename T>
void Vector<T>::push_back( const T & object ) throw ( bad_alloc )
{
    if ( sz == cap )
        increaseCapacity();
    
    contents[sz] = object;
    sz++;
}

template <typename T>
void Vector<T>::remove( const unsigned i ) throw ( out_of_range )
{
    if ( i >= sz )
        throw out_of_range( "the index could not be found" );

    for ( unsigned c = sz - 1; c > i ; --c )
        contents[c-1] = contents[c];

    sz--;    
}

template <typename T>
void Vector<T>::resize( const unsigned newSize, const T & object ) throw ( bad_alloc )
{
    if ( newSize > sz ) {
        if ( newSize > cap ) {
                cap = newSize;
            }

        for ( unsigned i = cap; i < newSize; ++i )
            contents[i] = object;
    } 
    else 
        sz = newSize;
     
}

template <typename T>
unsigned Vector<T>::size() const 
{
    return sz;
}

template <typename T>
void Vector<T>::sort()
{
    for ( unsigned i = 0; i < sz-1; i++ ) 
        for (unsigned j = 0; j < sz-1-i; j++ )
            if (contents[j] > contents[j+1]) {
                T temp = contents[j+1];
                contents[j+1] = contents[j];
                contents[j] = temp;
            }     
}

#endif