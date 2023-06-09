/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "productor.h"    // class Productor (Marcelo Gilman)
#include "proc.h"    // class Proc (Marcelo Gilman)
#include "cola.h"    // class Cola (Marcelo Gilman)
#include "distribuidor.h"    // class Cola (Marcelo Gilman)

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Productor>() , "Productor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Proc>() , "Proc" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Cola>() , "Cola" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Distribuidor>() , "Distribuidor" ) ;
}
