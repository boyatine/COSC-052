#ifndef __vector_h__
#define __vector_h__


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <cmath>
#include <exception>
#include <stdexcept>

using namespace std;
using std::bad_alloc;



template <typename T>
class Vector {

  public:
    Vector();
    Vector( const unsigned ) throw ( bad_alloc );
    Vector( const unsigned, const T& ) throw ( bad_alloc );
    Vector( const Vector<T> & ) throw ( bad_alloc );
    ~Vector();
    void assign( const unsigned, const T& ) throw ( out_of_range );
    T& at( const unsigned ) const throw ( out_of_range );
    unsigned capacity() const;
    void clear();
    bool empty() const;
    void insert( const unsigned, const T& ) throw ( bad_alloc, out_of_range );
    T& operator[]( const unsigned ) const throw ( out_of_range );
    const Vector<T> &operator=( const Vector<T>& ) throw ( bad_alloc );
    void push_back( const T& ) throw ( bad_alloc );
    void resize( const unsigned, const T& = T() ) throw ( bad_alloc );
    unsigned size() const;
    void sort();
    void remove( const unsigned ) throw ( out_of_range );

  private:
    T* contents;
    unsigned sz;
    unsigned cap;

    void increaseCapacity() throw ( bad_alloc );

}; // Vector<T> class

template <typename T>
Vector <T>::Vector()
{
    cap = 10;
    sz=0;
    contents = new T[cap];


}

template <typename T>
Vector<T>:: Vector (const unsigned capacity ) throw (bad_alloc)
{
    sz=0;
    cap = 10;
    cap =capacity;
    contents = new T[cap];


}

template <typename T>
Vector <T>::Vector( const unsigned sz, const T& obj) throw ( bad_alloc )
{
    this -> sz=sz;
    cap = sz;
    contents = new T[cap];

    for (unsigned i=0; i < sz; i++)
    {
        contents [i]= obj;
    }

}

template <typename T>
Vector <T>::Vector( const Vector<T> &vec ) throw ( bad_alloc )
{
    contents = new T[vec.capacity()];
    sz=vec.size();
    cap=vec.capacity();

    for (unsigned long i=0; i<vec.size(); i++)
    {
        this->contents[i] = vec[i];
    }
}

template <typename T>
Vector <T>::~Vector()
{
    delete []contents;

    cap=0;
    sz=0;
    clear();

    cout << "leaving destructor" << endl;
    //contents = NULL;
}

template <typename T>
void Vector<T>:: assign(const unsigned ndx, const T&obj) throw (out_of_range)
{
    if (ndx > (size()-1) || ndx<0)
    {
        throw out_of_range ("messed up at assign");
    }
    contents [ndx]= obj;
}

template <typename T>
T& Vector<T>::at(const unsigned ndx) const throw ( out_of_range )
{

    //changed from size-1
    if (ndx > (size()) || ndx<0)
    {
        throw out_of_range ("messed up in at");
    }

    return contents[ndx];
}

template <typename T>
unsigned Vector<T>:: capacity() const
{
    //cout<< capacity<< endl;
    return cap;
}

template <typename T>
void Vector<T>:: clear()
{
    sz=0;
}

template <typename T>
bool Vector<T>:: empty() const
{
    return sz==0;

}

template <typename T>
void Vector<T>:: insert(const unsigned ndx, const T& obj) throw (bad_alloc, out_of_range)
{
    if (ndx > size() || ndx <0)
    {
        throw out_of_range ("messed up in insert");
    }

    if (capacity()== size())
    {
        increaseCapacity();
    }
    for (unsigned long i=size(); i>ndx; i--)
    {
        contents [i] = contents [i-1];
    }
    contents[ndx] = obj;
    sz++;
}

template <typename T>
T& Vector<T>:: operator[](const unsigned ndx) const throw (out_of_range)
{
    if (ndx > sz)
    {
        throw out_of_range ("messed up in at");
    }

    return contents[ndx];
}

template <typename T>
const Vector <T>& Vector<T>:: operator=(const Vector<T> &vec ) throw (bad_alloc)
{
    if (&vec != this)
    {
        delete[]contents;
        this->clear();

        contents = new T[vec.capacity()];

        for (unsigned i=0; i< vec.size(); i++)
        {
            this->push_back( vec[i]);
        }
    }

    return *this;
}

template <typename T>
void Vector<T>:: push_back(const T& obj) throw (bad_alloc)
{
    if (capacity()==size())
    {
        increaseCapacity();
    }

    insert(size(), obj);

}

template <typename T>
void Vector<T>:: resize(const unsigned newSize, const T& obj) throw (bad_alloc)
{
    T* tempA = new T[sz];

    for (unsigned int i=0; i<sz; i++)
    {
        tempA[i]= this->at(i);
    }

    unsigned oSize = this-> size();

    sz = newSize;

    cap =newSize;

    for (unsigned int i=0; i<sz; i++)
    {
        if (i< oSize)
        {
            this-> at(i) =tempA[i];
        }

        else
        {
            this-> at(i)= obj;
        }
    }

    delete [] tempA;
}

template <typename T>
unsigned Vector<T>:: size() const
{
    //cout << sz<< endl;
    return sz;
}

template <typename T>
void Vector<T>:: sort()
{
    T temp;
    int iteration;
    int index;

    //cout << "starting bubble sort of list with " << length << " elements..." << endl;

    for(iteration = 1; iteration < sz; iteration++)
    {
        for(index = 0; index < sz - iteration; index++)
        {
            if(contents[index] > contents[index + 1])
            {
                //cout << "swapping " << list[index] << " with " << list[index+1] << endl;

                temp = contents[index];
                contents[index] = contents[index + 1];
                contents[index + 1] = temp;
            }
        }
    }

}

template <typename T>
void Vector<T>:: remove(const unsigned ndx) throw (out_of_range)
{
    if (ndx >= size())
    {
        throw out_of_range ("messed up in remove");
    }

    T* tempA = new T[sz-1];

    for (unsigned int i=0; i < size(); i++)
    {
        if (i < ndx)
        {
            tempA[i]= this->at(i);
        }

        if (i == ndx)
        {

        }

        if (i> ndx)
        {
            tempA[i-1] = this->at(i);
        }
    }

    //delete contents[ndx];

    sz--;

    for (unsigned int i =0; i< size(); i++)
    {
        this->at(i)= tempA[i];
    }

    delete [] tempA;

}

// private methods

template <typename T>
void Vector<T>::increaseCapacity() throw ( bad_alloc )
{
    if (cap ==0)
    {
        cap =1;
        contents = new T[cap];
    }
    else
    {
        cap =2*cap;
        T*temp=new T[cap];
        for  (unsigned long i=0; i<size(); i++)
        {
            temp[i] =at(i);
        }
        delete []contents;
        contents =temp;

    }
}

#endif // __vector_h__





