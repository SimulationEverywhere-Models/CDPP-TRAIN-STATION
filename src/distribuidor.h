/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cola
*
*  AUTHOR: Marcelo Gilman
*
*  EMAIL: mailto://mgilman@dc.uba.ar
*
*******************************************************************/

#ifndef __DIST_H
#define __DIST_H

#include <list>
#include "atomic.h"     // class Atomic

class Distribuidor : public Atomic
{
public:
	Distribuidor( const string &name = "Distribuidor" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
	int best_out();

private:
	// State
	Value v;
	int best;
	int pop[4];

	// Ports
	Port &in;
	Port &out1;
	Port &out2;
	Port &out3;
	Port &out4;
	Port &r1;
	Port &r2;
	Port &r3;
	Port &r4;

	//impl
	int p1;
	int p2;
	int p3;
	int p4;

};	// class Distribuidor

// ** inline ** // 
inline
string Distribuidor::className() const
{
	return "Distribuidor" ;
}

#endif   //__DIST_H
