/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CPhysical.h
*  PURPOSE:		Physical entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_PHYSICAL
#define __CGAME_PHYSICAL

#include "CEntity.h"

class CPhysical : public virtual CEntity
{
public:
    virtual					~CPhysical( void ) {};

	virtual const CVector	GetMoveSpeed( void ) = 0;
	virtual const CVector	GetTurnSpeed( void ) = 0;
	virtual void			SetMoveSpeed( const CVector& vecMoveSpeed ) = 0;
	virtual void			SetTurnSpeed( const CVector& vecTurnSpeed ) = 0;

    virtual float			GetMass( void ) = 0;
    virtual float			GetTurnMass( void ) = 0;
    virtual void			SetMass( float fMass ) = 0;
    virtual void			SetTurnMass( float fTurnMass ) = 0;
    virtual float			GetElasticity( void ) = 0;
    virtual void			SetElasticity( float fElasticity ) = 0;
    virtual float			GetBuoyancyConstant( void ) = 0;
    virtual void			SetBuoyancyConstant( float fBuoyancyConstant ) = 0;

	virtual void			ProcessCollision( void )=0;

    virtual float			GetDamageImpulseMagnitude( void ) = 0;
    virtual void			SetDamageImpulseMagnitude( float fMagnitude ) = 0;
    virtual CEntity*		GetDamageEntity( void ) = 0;
    virtual void			SetDamageEntity( CEntity* pEntity ) = 0;
    virtual void			ResetLastDamage( void ) = 0;

    virtual CEntity*		GetAttachedEntity( void ) = 0;
    virtual void			AttachEntityToEntity( CPhysical& Entity, const CVector& vecPosition, const CVector& vecRotation ) = 0;
    virtual void			DetachEntityFromEntity( float fUnkX, float fUnkY, float fUnkZ, bool bUnk )=0;
    virtual void			GetAttachedOffsets( CVector& vecPosition, CVector& vecRotation )=0;
    virtual void			SetAttachedOffsets( const CVector& vecPosition, const CVector& vecRotation )=0;

/*	virtual void		SetMass(float fMass)=0;
	virtual float		GetMass()=0;
	virtual void		SetTurnMass(float fTurnMass)=0;
	virtual float		GetTurnMass()=0;
	virtual void		SetMassMultiplier(float fMassMultiplier)=0;
	virtual float		GetMassMultiplier()=0;
	virtual void		SetAirResistance(float fAirResistance)=0;
	virtual float		GetAirResistance()=0;
	virtual void		SetElasticity(float fElasticity)=0;
	virtual float		GetElasticity()=0;
	virtual void		SetBuoyancyConstant(float fBuoyancyConstant)=0;
	virtual float		GetBuoyancyConstant()=0;
	virtual void		SetCenterOfMass(CVector * vecCenterOfMass)=0;
	virtual CVector	* GetCenterOfMass()=0;
	virtual bool		GetExtraHeavy()=0;
	virtual void		SetExtraHeavy(bool bExtraHeavy)=0;
	virtual bool		GetDoGravity()=0;
	virtual void		SetDoGravity(bool bDoGravity)=0;
	virtual bool		GetInfiniteMass()=0;
	virtual void		SetInfiniteMass(bool bInfiniteMass)=0;
	virtual bool		GetPositionFrozen()=0;
	virtual void		SetPositionFrozen(bool bPositionFrozen)=0;
	virtual BYTE		GetLastMaterialToHaveBeenStandingOn()=0;*/

};

#endif