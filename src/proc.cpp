/*******************************************************************
*
*  DESCRIPTION: Atomic Model Proc
*
*  AUTHOR: Marcelo Gilman
*
*  EMAIL: mailto://mgilman@dc.uba.ar
*
*******************************************************************/

/** include files **/
#include <math.h>        // fabs( ... )
#include "proc.h"           // base header
#include "message.h"       // InternalMessage ....
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Description: constructor
********************************************************************/
Proc::Proc( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
{
	try
	{
		if( MainSimulator::Instance().existsParameter( description(), "tproc" ) )
			tproc = str2float( MainSimulator::Instance().getParameter( description(), "tproc" ) );
		else
			tproc = 1;
	} catch( MException &e ) {
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Proc::initFunction()
{
	/*
	MainSimulator::Instance().outputStream() << this->className() << ":" << this->description() << "\n";
	MainSimulator::Instance().outputStream() << "tproc=" << tproc << "\n";
	*/

	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Proc::externalFunction( const ExternalMessage &msg )
{
	if (state()==passive) {
		v = (int)msg.value();
		holdIn(active, Time(tproc)) ;
	}
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Proc::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Proc::outputFunction( const InternalMessage &msg )
{
	sendOutput(msg.time(), out, v);
	return *this;
}

Proc::~Proc()
{}
