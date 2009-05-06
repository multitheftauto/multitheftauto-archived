/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CPickupSA.cpp
*  PURPOSE:     Pickup entity
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

CPickupSA::CPickupSA( CPickupSAInterface* pickupInterface )
{
	this->internalInterface = pickupInterface;
	this->callback = 0;
	this->object = 0;
}

void CPickupSA::SetPosition( const CVector& vecPosition )
{
	this->GetInterface()->bIsPickupNearby = 0;

	CPickupSAInterface * iPickup = this->GetInterface();
	iPickup->CoorsX = (short)(vecPosition.getX() * 8);
	iPickup->CoorsY = (short)(vecPosition.getY() * 8);
	iPickup->CoorsZ = (short)(vecPosition.getZ() * 8);
}

const CVector CPickupSA::GetPosition( void )
{	
	CVector vecPosition;

	CPickupSAInterface * iPickup = this->GetInterface();
	vecPosition.setX( iPickup->CoorsX / 8.0f );
	vecPosition.setY( iPickup->CoorsY / 8.0f );
	vecPosition.setZ( iPickup->CoorsZ / 8.0f );

	return vecPosition;
}

ePickupType	CPickupSA::GetType( void )
{
	return (ePickupType) this->GetInterface()->Type;
}

void CPickupSA::SetType( ePickupType type )
{
	this->GetInterface()->Type = type;
}

float CPickupSA::GetCurrentValue( void )
{
	return this->GetInterface()->CurrentValue;
}

void CPickupSA::SetCurrentValue( float fCurrentValue )
{
	this->GetInterface()->CurrentValue = fCurrentValue;	
}

void CPickupSA::SetRegenerationTime( DWORD dwTime )
{
	this->GetInterface()->RegenerationTime = dwTime;
}

void CPickupSA::SetMoneyPerDay( short wMoneyPerDay )
{
	this->GetInterface()->MoneyPerDay = wMoneyPerDay;
}

short CPickupSA::GetMoneyPerDay( void )
{
	return this->GetInterface()->MoneyPerDay;
}

short CPickupSA::GetModel( void )
{
	return this->GetInterface()->MI;
}

void CPickupSA::SetModel( short wModelIndex )
{
	this->GetInterface()->MI = wModelIndex;
}

ePickupState CPickupSA::GetState( void )
{
	return (ePickupState)this->GetInterface()->State;
}

void CPickupSA::SetState( ePickupState bState )
{
	this->GetInterface()->State = (BYTE)bState;
}

BYTE CPickupSA::GetAmmo( void )
{
	return this->GetInterface()->bNoAmmo;
}

void CPickupSA::SetAmmo( BYTE bAmmo )
{
	this->GetInterface()->bNoAmmo = bAmmo;
}

long CPickupSA::GetMonetaryValue( void )
{
	return this->GetInterface()->MonetaryValue;
}

void CPickupSA::SetMonetaryValue( long lMonetaryValue )
{
	this->GetInterface()->MonetaryValue = lMonetaryValue;
}

BYTE CPickupSA::IsNearby( void )
{
	return this->GetInterface()->bIsPickupNearby;
}

void CPickupSA::GiveUsAPickUpObject( int ForcedObjectIndex )
{
	DWORD GiveUsAPickUpObject = FUNC_GIVEUSAPICKUP;
	DWORD dwObject = (DWORD)&(this->GetInterface()->pObject);
	DWORD dwThis = (DWORD)this->GetInterface();
	_asm
	{
		push	ForcedObjectIndex
		push	dwObject
		mov		ecx, dwThis
		call	GiveUsAPickUpObject
	}
	if(this->GetInterface()->pObject)
	{
        if ( this->object )
        {
            delete this->object;
        }

		this->object = new CObjectSA(this->GetInterface()->pObject);
	}
}

void CPickupSA::GetRidOfObjects( void )
{
	if(this->GetInterface()->pObject)
		((CWorldSA *)pGame->GetWorld())->Remove(this->GetInterface()->pObject);
	
	if(this->object)
    {
		delete this->object;
        this->object = NULL;
    }
}

void CPickupSA::Remove( void )
{
    DWORD dwFunc = FUNC_CPickup_Remove;
    DWORD dwThis = (DWORD)this->GetInterface();
    _asm
    {
        mov     ecx, dwThis
        call    dwFunc
    }

    // CPickup::Remove also destroys the owned object, so we need to delete our CObjectSA class
    if ( this->object )
    {
        ((CEntitySA*)this->object)->DoNotRemoveFromGame = true;
        delete this->object;
        this->object = NULL;
    }
}
