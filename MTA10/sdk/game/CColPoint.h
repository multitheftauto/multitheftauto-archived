/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CColPoint.h
*  PURPOSE:		Collision point interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_CCOLPOINT
#define __CGAME_CCOLPOINT

#include <CVector.h>

// ChrML: Dunno where to put this, so I put it here.. but I guess this should be in some
//        kind of global section..

class CColPointSAInterface;

class CColPoint
{
public:
    virtual							~CColPoint( void ) {};

    virtual CColPointSAInterface*	GetInterface( void ) = 0;
	virtual const CVector			GetPosition( void ) = 0;
	virtual void					SetPosition( const CVector& vecPosition ) = 0;

	virtual const CVector			GetNormal( void ) = 0;
	virtual void					SetNormal( const CVector& vecNormal ) = 0;

	virtual BYTE					GetSurfaceTypeA( void ) = 0;
	virtual BYTE					GetSurfaceTypeB( void ) = 0;

	virtual void					SetSurfaceTypeA( BYTE bSurfaceType ) = 0;
	virtual void					SetSurfaceTypeB( BYTE bSurfaceType ) = 0;

	virtual	BYTE					GetPieceTypeA( void ) = 0;
	virtual BYTE					GetPieceTypeB( void ) = 0;

	virtual void					SetPieceTypeA( BYTE bPieceType ) = 0;
	virtual void					SetPieceTypeB( BYTE bPieceType ) = 0;

	virtual BYTE					GetLightingA( void ) = 0;
	virtual BYTE					GetLightingB( void ) = 0;

	virtual void					SetLightingA( BYTE bLighting ) = 0;
	virtual void					SetLightingB( BYTE bLighting ) = 0;

	virtual FLOAT					GetDepth( void ) = 0;
	virtual void					SetDepth( FLOAT fDepth ) = 0;

	virtual void					Destroy( void ) = 0;
};

#endif
