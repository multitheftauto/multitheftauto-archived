/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CWorld.h
*  PURPOSE:		Game world interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_WORLD
#define __CGAME_WORLD

#include "CEntity.h"
#include "CColPoint.h"

class CWorld
{
public:
	virtual void		Add                         ( CEntity * entity ) = 0;
	virtual void		Remove                      ( CEntity * entity ) = 0;
	virtual void		IgnoreEntity                ( CEntity * entity ) = 0;

	virtual bool		ProcessLineOfSight          ( const CVector& vecStart, const CVector& vecEnd, CColPoint ** colCollision, CEntity ** CollisionEntity, bool bCheckBuildings = true, bool bCheckVehicles = true, bool bCheckPeds = true, bool bCheckObjects = true, bool bCheckDummies = true, bool bSeeThroughStuff = false, bool bIgnoreSomeObjectsForCamera = false, bool bShootThroughStuff = false ) = 0;
    // THIS FUNCTION IS INCOMPLETE AND SHOULD NOT BE USED ----------v
    virtual bool        TestLineSphere              ( const CVector& vecStart, const CVector& vecEnd, const CVector& vecSphereCenter, float fSphereRadius, CColPoint ** colCollision ) = 0;
	virtual bool		IsLineOfSightClear          ( const CVector& vecStart, const CVector& vecEnd, bool bCheckBuildings = true, bool bCheckVehicles = true, bool bCheckPeds = true, bool bCheckObjects = true, bool bCheckDummies = true, bool bSeeThroughStuff = false, bool bIgnoreSomeObjectsForCamera = false ) = 0;

	virtual float		FindGroundZForPosition      ( float fX, float fY ) = 0;
	virtual float		FindGroundZFor3DPosition    ( const CVector& vecPosition ) = 0;
	virtual BYTE		GetLevelFromPosition        ( const CVector& vecPosition ) = 0;

	virtual void		LoadMapAroundPoint          ( const CVector& vecPosition, float fRadius ) = 0;
    virtual bool        HasCollisionBeenLoaded      ( const CVector& vecPosition ) = 0;

	virtual DWORD       GetCurrentArea              ( void ) = 0;
    virtual void        SetCurrentArea              ( DWORD dwArea ) = 0;
};

#endif