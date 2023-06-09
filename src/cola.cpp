/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cola
*
*  AUTHOR: Marcelo Gilman
*
*  EMAIL: mailto://mgilman@dc.uba.ar
*
*******************************************************************/

/** include files **/
#include "cola.h"      // class Cola
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Cola
* Description: 
********************************************************************/
Cola::Cola( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, r( addInputPort( "r" ) )
{}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Cola::initFunction()
{
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Cola::externalFunction( const ExternalMessage &msg )
{
	if(msg.port()==in) {
		elements.push_back( msg.value() ) ;
		if( elements.size() == 1 ) {
			holdIn(active, 0);
		}
	}

	if(msg.port()==r)	{
		elements.pop_front() ;
		if(!elements.empty() ) {
			holdIn(active, 0);
		}
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Cola::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Cola::outputFunction( const InternalMessage &msg )
{
	sendOutput(msg.time(), out, elements.front()) ;
	return *this ;
}
