/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CDoor.h
*  PURPOSE:		Door entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_DOOR
#define __CGAME_DOOR

#include <windows.h>

#include "Common.h"

class CDoor
{
public:
	virtual float			GetAngleOpenRatio ( )=0;
	virtual bool			IsClosed (  )=0;
	virtual bool			IsFullyOpen (  )=0;
	virtual void			Open ( float fUnknown )=0;
	virtual eDoorState		GetDoorState()=0;
};

#endif