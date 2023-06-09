/*******************************************************************
*
*  DESCRIPTION: class Productor
*
*  AUTHOR: Marcelo Gilman
*
*  EMAIL: mailto://mgilman@dc.uba.ar
*
*******************************************************************/

#ifndef __PRODUCTOR_H
#define __PRODUCTOR_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** declarations **/
class Productor : public Atomic
{
public:
	Productor( const string &name = "Productor" );				  // Default constructor

	~Productor();

	virtual string className() const
		{return "Productor";}

protected:
	Model &initFunction() ;

	Model &externalFunction( const ExternalMessage & )
			{throw InvalidMessageException();}

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	// state
	int k;

	// parameters
	float tact;
	float tpas;
	float cp;

	// consts
	float kp;
	float f;

	// ports
	Port &out ;
			
};	// class Productor


#endif   //__PRODUCTOR_H 
