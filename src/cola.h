/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cola
*
*  AUTHOR: Marcelo Gilman
*
*  EMAIL: mailto://mgilman@dc.uba.ar
*
*******************************************************************/

#ifndef __COLA_H
#define __COLA_H

#include <list>
#include "atomic.h"     // class Atomic

class Cola : public Atomic
{
public:
	Cola( const string &name = "Cola" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	// State
	typedef list<Value> ElementList ;
	ElementList elements ;

	// Ports
	Port &in;
	Port &out;
	Port &r;

};	// class Cola

// ** inline ** // 
inline
string Cola::className() const
{
	return "Cola" ;
}

#endif   //__COLA_H
