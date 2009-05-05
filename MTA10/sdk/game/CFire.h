/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CFire.h
*  PURPOSE:		Fire interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_FIRE
#define __CGAME_FIRE

#include <windows.h>
#include <CVector.h>
#include "CEntity.h"

class CFireInterface
{
public:
};

class CFire
{
public:
	virtual const CVector			GetPosition( void ) = 0;
	virtual void					SetPosition( const CVector& vecPosition ) = 0;

	virtual void					Extinguish( void ) = 0;
	virtual void					SetTimeToBurnOut( DWORD dwTime ) = 0;
	virtual DWORD					GetTimeToBurnOut( void ) = 0;
	virtual CEntity*				GetCreator( void ) = 0;
	virtual CEntity*				GetEntityOnFire( void ) = 0;
	virtual void					SetTarget( CEntity * entity ) = 0;
	virtual bool					IsIgnited( void ) = 0;
	virtual void					SetSilent( bool bSilent ) = 0;
	virtual bool					IsBeingExtinguished( void ) = 0;
	virtual void					Ignite( void ) = 0;
	virtual	FLOAT					GetStrength( void ) = 0;
	virtual	void					SetStrength( FLOAT fStrength ) = 0;
    virtual	void                    SetNumGenerationsAllowed( char generations ) = 0;
    virtual CFireInterface*         GetInterface( void ) = 0;
};

#endif