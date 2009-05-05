/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CFireManager.h
*  PURPOSE:		Fire entity manager interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_FIREMANAGER
#define __CGAME_FIREMANAGER

#include <CVector.h>
#include "CFire.h"
#include "CEntity.h"


class CFireManager
{
public:
	virtual void	ExtinguishPoint( const CVector& vecPosition, float fRadius ) = 0;
	virtual CFire*	StartFire( const CVector& vecPosition, float fSize ) = 0;
	virtual void	ExtinguishAllFires( void ) = 0;
	virtual CFire*	GetFire( DWORD ID ) = 0;
};

#endif