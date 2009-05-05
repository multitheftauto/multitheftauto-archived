/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CCam.h
*  PURPOSE:		Camera entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_CAM
#define __CGAME_CAM

#include "CCam.h"
#include <CVector.h>

class CCam
{
public:
	virtual const CVector	GetFront( void ) = 0;
	virtual const CVector	GetUp( void ) = 0;
	virtual const CVector	GetSource( void ) = 0;
	virtual const CVector	GetFixedModeSource( void ) = 0;
	virtual const CVector	GetFixedModeVector( void ) = 0;
    virtual unsigned int	GetMode( void ) = 0;
    virtual CEntity*		GetTargetEntity( void ) = 0;
};

#endif