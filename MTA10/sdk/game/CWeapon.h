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
class CVector2D;
enum ePedPieceTypes;

class CWeapon
{
public:
    virtual void                    Destroy             ( void ) = 0;

    virtual eWeaponType		        GetType             ( void ) = 0;
	virtual void			        SetType             ( eWeaponType type ) = 0;
	virtual eWeaponState	        GetState            ( void ) = 0;
    virtual void                    SetState            ( eWeaponState state ) = 0;
	virtual DWORD			        GetAmmoInClip       ( void ) = 0;
	virtual void			        SetAmmoInClip       ( DWORD dwAmmoInClip ) = 0;
	virtual DWORD			        GetAmmoTotal        ( void ) = 0;
	virtual void			        SetAmmoTotal        ( DWORD dwAmmoTotal ) = 0;
	
	virtual CPed *                  GetPed              ( void ) = 0;
	virtual eWeaponSlot		        GetSlot             ( void ) = 0;

	virtual void			        SetAsCurrentWeapon  ( void ) = 0;
	virtual CWeaponInfo *           GetInfo             ( void ) = 0;

    virtual void                    Remove              ( void ) = 0;

    virtual void                    Initialize          ( eWeaponType type, unsigned int uiAmmo, CPed * pPed ) = 0;
    virtual void                    Update              ( CPed * pPed ) = 0;
    virtual bool                    Fire                ( CEntity * pFiringEntity, CVector * pvecOrigin, CVector * pvecOffset, CEntity * pTargetEntity, CVector * pvec_1, CVector * pvec2 ) = 0;
    virtual void                    AddGunshell         ( CEntity * pFiringEntity, CVector * pvecOrigin, CVector2D * pvecDirection, float fSize ) = 0;
    virtual void                    DoBulletImpact      ( CEntity * pFiringEntity, CEntity * pEntity, CVector * pvecOrigin, CVector * pvecTarget, CColPoint * pColPoint, int i_1 ) = 0;
    virtual unsigned char           GenerateDamageEvent ( CPed * pPed, CEntity * pResponsible, eWeaponType weaponType, int iDamagePerHit, ePedPieceTypes hitZone, int i_2 ) = 0;
};

#endif