/*******************************************************************
*
*  DESCRIPTION: class Proc
*
*  AUTHOR: Marcelo Gilman
*
*  EMAIL: mailto://mgilman@dc.uba.ar
*
*******************************************************************/

#ifndef __PROC_H
#define __PROC_H

/** include files **/
#include "atomic.h"  // class Atomic

/** declarations **/
class Proc : public Atomic
{
public:
	Proc( const string &name = "Proc" ) ;	 // Default constructor

	~Proc();					// Destructor

	virtual string className() const
		{return "Proc";}

protected:
	Model &initFunction();

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	// state
	int v;

	// parameters
	float tproc;

	// ports
	Port &in;
	Port &out;

};	// class PROC

#endif   //__PROC_H 

