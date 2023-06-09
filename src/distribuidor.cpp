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
#include "distribuidor.h"      // class Distribuidor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Distribuidor
* Description: 
********************************************************************/
Distribuidor::Distribuidor( const string &name ) : Atomic( name )
, in( addInputPort( "in" ) )
, out1( addOutputPort( "out1" ) )
, out2( addOutputPort( "out2" ) )
, out3( addOutputPort( "out3" ) )
, out4( addOutputPort( "out4" ) )
, r1( addInputPort( "r1" ) )
, r2( addInputPort( "r2" ) )
, r3( addInputPort( "r3" ) )
, r4( addInputPort( "r4" ) )
{
	try
	{
		p1 = 0;
		p2 = 0;
		p3 = 0;
		p4 = 0;
		if( MainSimulator::Instance().existsParameter( description(), "p1" ) ) {
			p1 = str2Int( MainSimulator::Instance().getParameter( description(), "p1" ) );
		} 
		if( MainSimulator::Instance().existsParameter( description(), "p2" ) ) {
			p2 = str2Int( MainSimulator::Instance().getParameter( description(), "p2" ) );
		} 
		if( MainSimulator::Instance().existsParameter( description(), "p3" ) ) {
			p3 = str2Int( MainSimulator::Instance().getParameter( description(), "p3" ) );
		} 
		if( MainSimulator::Instance().existsParameter( description(), "p4" ) ) {
			p4 = str2Int( MainSimulator::Instance().getParameter( description(), "p4" ) );
		} 

		pop[0] = p1;
		pop[1] = p2;
		pop[2] = p3;
		pop[3] = p4;
	} catch( MException &e ) {
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Distribuidor::initFunction()
{
	/*
	MainSimulator::Instance().outputStream() << this->className() << ":" << this->description() << "\n";
	MainSimulator::Instance().outputStream() << "p1=" << pop[0] << "\n";
	MainSimulator::Instance().outputStream() << "p2=" << pop[1] << "\n";
	MainSimulator::Instance().outputStream() << "p3=" << pop[2] << "\n";
	MainSimulator::Instance().outputStream() << "p4=" << pop[3] << "\n";
	*/

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Distribuidor::externalFunction( const ExternalMessage &msg )
{
	if(msg.port()==in) {
		v = msg.value();
		best = best_out();
		/*
		MainSimulator::Instance().outputStream() << "best=" << best << "\n";
		*/
		pop[best]++;
		holdIn(active, Time::Zero) ;
	}
	if(msg.port()==r1) {
		pop[0]--;
	}
	if(msg.port()==r2) {
		pop[1]--;
	}
	if(msg.port()==r3) {
		pop[2]--;
	}
	if(msg.port()==r4) {
		pop[3]--;
	}

	/*
	MainSimulator::Instance().outputStream() << this->className() << ":" << this->description() << "\n";
	MainSimulator::Instance().outputStream() << "p1=" << pop[0] << "\n";
	MainSimulator::Instance().outputStream() << "p2=" << pop[1] << "\n";
	MainSimulator::Instance().outputStream() << "p3=" << pop[2] << "\n";
	MainSimulator::Instance().outputStream() << "p4=" << pop[3] << "\n";
	*/

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Distribuidor::internalFunction( const InternalMessage &msg )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Distribuidor::outputFunction( const InternalMessage &msg )
{
	if(best==0) {
		sendOutput(msg.time(), out1, v) ;
	}
	if(best==1) {
		sendOutput(msg.time(), out2, v) ;
	}
	if(best==2) {
		sendOutput(msg.time(), out3, v) ;
	}
	if(best==3) {
		sendOutput(msg.time(), out4, v) ;
	}
	return *this ;
}

/*******************************************************************
* Function Name: best
* Description: Retorna el indice (-1) de la salida con menor poblacion
********************************************************************/
int Distribuidor::best_out() {
	int best = 0;
	int min_pop = pop[best];
	for (int i=1;i<4; i++) {
		for (int j=i;j<4; j++) {
			if (pop[j]<min_pop) {
				best = j;
				min_pop = pop[best];
			}
		}
	}
	return best;
}

