/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CPickupSA.h
*  PURPOSE:     Header file for pickup entity class
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_PICKUP
#define __CGAMESA_PICKUP
	
#include <game/CPickup.h>
#include "CObjectSA.h"

#define FUNC_GIVEUSAPICKUP		0x4567e0
#define FUNC_CPickup_Remove     0x4556C0

class CObjectSAInterface;
class CObjectSA;


class CPickupSAInterface 
{
public:	
	float	CurrentValue;		// For the revenue pickups  0
	CObjectSAInterface *pObject; // 4
	long	MonetaryValue;  // 8
	DWORD	RegenerationTime; // 12
	short	CoorsX, CoorsY, CoorsZ; //16 // 18 // 20
	WORD	MoneyPerDay; //22
	WORD	MI; // 24
	WORD	ReferenceIndex; // 26
	BYTE	Type; // 28
	BYTE	State : 1; //29
	BYTE	bNoAmmo : 1;
	BYTE	bHelpMessageDisplayed : 1;
	BYTE	bIsPickupNearby : 1;	// If the pickup is nearby it will get an object and it will get updated.
	BYTE	TextIndex : 3;			// What text label do we print out above it.
};

class CPickupSA : public CPickup
{
	CPickupSAInterface*	internalInterface;
	CObjectSA*			object;
	CBPickup			callback; // function to call when the pickup is picked up [not used yet/ever]
public:
	// constructor	
						CPickupSA( CPickupSAInterface * pickupInterface );
	CPickupSAInterface*	GetInterface( void ) { return internalInterface; }; // not to be exported
    CObject*			GetObject( void ) { return object; };

	void				SetPosition( const CVector& vecPosition );
	const CVector		GetPosition( void );
	
	ePickupType			GetType( void );
	void				SetType( ePickupType type );
	FLOAT				GetCurrentValue( void );
	void				SetCurrentValue( FLOAT fCurrentValue );
	void				SetRegenerationTime( DWORD dwTime );
	WORD				GetMoneyPerDay( void );
	void				SetMoneyPerDay( WORD wMoneyPerDay );
	WORD				GetModel( void );
	void				SetModel( WORD wModelIndex ); // do not export
	ePickupState		GetState( void );
	void				SetState( ePickupState bState );
	BYTE				GetAmmo( void );
	void				SetAmmo( BYTE bAmmo );
	long				GetMonetaryValue( void );
	void				SetMonetaryValue( long lMonetaryValue );
	BYTE				IsNearby( void );
	void				GiveUsAPickUpObject( int ForcedObjectIndex = -1 );
	void				GetRidOfObjects( void );
    void                Remove( void );
};

#endif