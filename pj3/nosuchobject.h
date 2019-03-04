#ifndef NOSUCHOBJECT_H
#define NOSUCHOBJECT_H

#include <cstdlib>

using namespace std;



class NoSuchObject : public logic_error {
	public:
   		NoSuchObject() : logic_error( "stack is empty" ) {}
   		NoSuchObject( const string& what) : logic_error(what) {}

    
}; //END definition class no_such_object





#endif
