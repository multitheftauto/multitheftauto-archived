/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CPickup.h
*  PURPOSE:		Pickup entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_PICKCUP
#define __CGAME_PICKCUP

#include <windows.h>
#include <CVector.h>
#include "Common.h"

class CObject;

class CPickup
{
public:
    virtual CObject *           GetObject( void ) = 0;

	virtual void				SetPosition( const CVector& vecPosition ) = 0;
	virtual const CVector		GetPosition( void ) = 0;
	
	virtual ePickupType			GetType( void ) = 0;
	virtual void				SetType( ePickupType type ) = 0;
	virtual float				GetCurrentValue( void ) = 0;
	virtual void				SetCurrentValue( float fCurrentValue ) = 0;
	virtual void				SetRegenerationTime( DWORD dwTime ) = 0;
	virtual void				SetMoneyPerDay( short wMoneyPerDay ) = 0;
	virtual short				GetMoneyPerDay( void ) = 0;
	virtual short				GetModel( void ) = 0;
	virtual void				SetModel( short wModelIndex ) = 0;
	virtual ePickupState		GetState( void ) = 0;
	virtual void				SetState( ePickupState bState ) = 0;
	virtual BYTE				GetAmmo( void ) = 0;
	virtual void				SetAmmo( BYTE bAmmo ) = 0;
	virtual long				GetMonetaryValue( void ) = 0;
	virtual void				SetMonetaryValue( long lMonetaryValue ) = 0;
	virtual BYTE				IsNearby( void ) = 0;
    virtual void                Remove( void ) = 0;
    virtual void				GiveUsAPickUpObject( int ForcedObjectIndex = -1 ) = 0;
    virtual void				GetRidOfObjects( void ) = 0;

};

// not used
typedef bool (*CBPickup) (CPickup *);

#endif