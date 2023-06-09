/*******************************************************************
*
*  DESCRIPTION: class Productor
*
*  AUTHOR: Marcelo Gilman
*
*  EMAIL: mailto://mgilman@dc.uba.ar
*
*******************************************************************/

/** include files **/
#include "productor.h"       // base header
#include "message.h"       // class InternalMessage 
#include "mainsimu.h"      // class Simulator
#include "distri.h"        // class Distribution 
#include "strutil.h"       // str2Value( ... )

/*******************************************************************
* Function Name: Productor
* Description: constructor
********************************************************************/
Productor::Productor( const string &name )
: Atomic( name )
, out( addOutputPort( "out" ) )
{
	try
	{
		if( MainSimulator::Instance().existsParameter( description(), "tact" ) )
			tact = str2float( MainSimulator::Instance().getParameter( description(), "tact" ) );
		else
			tact = 1;
		if( MainSimulator::Instance().existsParameter( description(), "tpas" ) )
			tpas = str2float( MainSimulator::Instance().getParameter( description(), "tpas" ) );
		else
			tpas = 1;
		if( MainSimulator::Instance().existsParameter( description(), "cp" ) )
			cp = str2float( MainSimulator::Instance().getParameter( description(), "cp" ) );
		else
			cp = 1;
	} catch( MException &e ) {
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Productor::initFunction()
{
	kp = tact*cp;
	f=tact/(kp-1);

	/*
	MainSimulator::Instance().outputStream() << this->className() << ":" << this->description() << "\n";
	MainSimulator::Instance().outputStream() << "tact=" << tact << "\n";
	MainSimulator::Instance().outputStream() << "tpas=" << tpas << "\n";
	MainSimulator::Instance().outputStream() << "cp=" << cp << "\n";
	MainSimulator::Instance().outputStream() << "kp=" << kp << "\n";
	MainSimulator::Instance().outputStream() << "f=" << f << "\n";
	*/

	k = (int)kp;
	if (kp>0) {
		holdIn(active,Time::Zero);
	}

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Productor::internalFunction( const InternalMessage & )
{
	if (state()==passive) {
		k = (int)kp;
		holdIn(active, Time::Zero);
	} else if (state()==active) {
		if (k==1) {
			holdIn(passive, Time(tpas));
		} else {
			k--;
			holdIn(active, Time(f));
		}
	}
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Productor::outputFunction( const InternalMessage &msg )
{
	if (state()==active) {
		sendOutput( msg.time(), out, k) ;
	}
	return *this ;
}

Productor::~Productor()
{}
