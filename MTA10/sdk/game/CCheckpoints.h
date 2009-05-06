/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CCheckpoints.h
*  PURPOSE:		Checkpoint entity manager interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_CHECKPOINTS
#define __CGAME_CHECKPOINTS

#include <CVector.h>
#include "CCheckpoint.h"

class CCheckpoints
{
public:
	virtual CCheckpoint*	CreateCheckpoint( DWORD Identifier, short wType, const CVector& vecPosition, const CVector& vecPointDir, float fSize, float fPulseFraction, RGBA Color ) = 0;
	virtual CCheckpoint*	FindFreeMarker( void ) = 0;
};

#endif