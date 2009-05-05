/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CProjectileInfoSA.h
*  PURPOSE:     Header file for projectile type information class
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*               Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_PROJECTILEINFO
#define __CGAMESA_PROJECTILEINFO

#include <game/CProjectileInfo.h>
#include "CProjectileSA.h"
#include "Common.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define PROJECTILE_COUNT					32
#define PROJECTILE_INFO_COUNT               32

#define FUNC_RemoveAllProjectiles			0x5C69D0
#define FUNC_RemoveProjectile               0x7388F0 //##SA##
#define FUNC_AddProjectile					0x737C80 //##SA##

#define ARRAY_CProjectile					0xC89110 //##SA##
#define ARRAY_CProjectileInfo				0xC891A8 //##SA##

#define VTBL_CProjectile 0x867030

//#pragma pack(push,1)
class CProjectileInfoSAInterface
{
public:
	eWeaponType					dwProjectileType;
	CEntitySAInterface			* pEntProjectileOwner;
    CEntitySAInterface          * pEntProjectileTarget;
	DWORD						dwCounter;
	BYTE						bProjectileActive;
    BYTE                        bPad [ 3 ];
	CVectorGTA					OldCoors;
    DWORD                       dwUnk;
};
//#pragma pack(pop)

class CProjectileInfoSA : public CProjectileInfo
{
    CProjectileInfoSA*			projectileInfo[PROJECTILE_INFO_COUNT];
    CProjectileInfoSAInterface*	internalInterface;

public:
    CProjectileInfoSA( void )
    {
        for ( int i = 0; i < PROJECTILE_INFO_COUNT; i++ )
        {
            projectileInfo[i] = new CProjectileInfoSA((CProjectileInfoSAInterface*)(ARRAY_CProjectileInfo + i * sizeof(CProjectileInfoSAInterface)));
        }
    }

    CProjectileInfoSA( CProjectileInfoSAInterface * projectileInfoInterface )
    {
        internalInterface = projectileInfoInterface;
    }

	bool					AddProjectile( CEntity * creator, eWeaponType eWeapon, const CVector& vecOrigin, float fForce, CVector* target, CEntity * targetEntity );
    CProjectile *           GetProjectile( void * projectilePointer );
    void                    RemoveProjectile( CProjectileInfo * pProjectileInfo, CProjectile * pProjectile );
	void					RemoveAllProjectiles( void );

	CProjectile				* GetProjectile( DWORD ID );
    CProjectileInfo         * GetProjectileInfo( void * projectileInfoInterface );
    CProjectileInfo         * GetProjectileInfo( DWORD dwIndex );
    CProjectileInfo         * GetNextFreeProjectileInfo( void );

	CEntity*                GetTarget( void );
    void                    SetTarget( CEntity* pEntity );

    bool                    IsActive( void );
};

#endif