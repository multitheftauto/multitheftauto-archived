/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CWeapon.h
*  PURPOSE:		Weapon entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_CWEAPON
#define __CGAME_CWEAPON

#include "Common.h"

#include "CWeaponInfo.h"

class CPed;
class CColPoint;

class CWeapon
{
public:
	virtual eWeaponType		GetType(  )=0;
	virtual void			SetType( eWeaponType type )=0;
	virtual eWeaponState	GetState(  )=0;
    virtual void            SetState ( eWeaponState state )=0;
	virtual DWORD			GetAmmoInClip(  )=0;
	virtual void			SetAmmoInClip( DWORD dwAmmoInClip )=0;
	virtual DWORD			GetAmmoTotal(  )=0;
	virtual void			SetAmmoTotal( DWORD dwAmmoTotal )=0;
	virtual CPed			* GetPed()=0;
	virtual eWeaponSlot		GetSlot()=0;
	virtual void			SetAsCurrentWeapon()=0;
	virtual CWeaponInfo		* GetInfo()=0;
    virtual void            Remove ()=0;
};

#endif