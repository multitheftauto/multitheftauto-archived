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

CPickupSA::CPickupSA(CPickupSAInterface * pickupInterface)
{
	DEBUG_TRACE("CPickupSA::CPickupSA(CPickupSAInterface * pickupInterface)");
	this->internalInterface = pickupInterface;
	this->callback = 0;
	this->object = 0;
}

void CPickupSA::SetPosition(CVector * vecPosition)
{
	DEBUG_TRACE("void CPickupSA::SetPosition(CVector * vecPosition)");
	this->GetInterface()->bIsPickupNearby = 0;

	CPickupSAInterface * iPickup = this->GetInterface();
	iPickup->CoorsX = (short)(vecPosition->getX() * 8);
	iPickup->CoorsY = (short)(vecPosition->getY() * 8);
	iPickup->CoorsZ = (short)(vecPosition->getZ() * 8);
}

CVector * CPickupSA::GetPosition(CVector * vecPosition)
{	
	DEBUG_TRACE("CVector * CPickupSA::GetPosition(CVector * vecPosition)");
	CPickupSAInterface * iPickup = this->GetInterface();
	vecPosition->setX( iPickup->CoorsX / 8.0f );
	vecPosition->setY( iPickup->CoorsY / 8.0f );
	vecPosition->setZ( iPickup->CoorsZ / 8.0f );
	return vecPosition;
}

ePickupType	CPickupSA::GetType()
{
	DEBUG_TRACE("ePickupType CPickupSA::GetType()");
	return (ePickupType) this->GetInterface()->Type;
}

void CPickupSA::SetType(ePickupType type)
{
	DEBUG_TRACE("void CPickupSA::SetType(ePickupType type)");
	this->GetInterface()->Type = type;
}

FLOAT CPickupSA::GetCurrentValue()
{
	DEBUG_TRACE("FLOAT CPickupSA::GetCurrentValue()");
	return this->GetInterface()->CurrentValue;
}

void CPickupSA::SetCurrentValue(FLOAT fCurrentValue)
{
	DEBUG_TRACE("void CPickupSA::SetCurrentValue(FLOAT fCurrentValue)");
	this->GetInterface()->CurrentValue = fCurrentValue;	
}

void CPickupSA::SetRegenerationTime(DWORD dwTime)
{
	DEBUG_TRACE("void CPickupSA::SetRegenerationTime(DWORD dwTime)");
	this->GetInterface()->RegenerationTime = dwTime;
}

void CPickupSA::SetMoneyPerDay(WORD wMoneyPerDay)
{
	DEBUG_TRACE("void CPickupSA::SetMoneyPerDay(WORD wMoneyPerDay)");
	this->GetInterface()->MoneyPerDay = wMoneyPerDay;
}

WORD CPickupSA::GetMoneyPerDay()
{
	DEBUG_TRACE("WORD CPickupSA::GetMoneyPerDay()");
	return this->GetInterface()->MoneyPerDay;
}

WORD CPickupSA::GetModel()
{
	DEBUG_TRACE("WORD CPickupSA::GetModel()");
	return this->GetInterface()->MI;
}

void CPickupSA::SetModel(WORD wModelIndex)
{
	DEBUG_TRACE("void CPickupSA::SetModel(WORD wModelIndex)");
	this->GetInterface()->MI = wModelIndex;
}

ePickupState CPickupSA::GetState()
{
	DEBUG_TRACE("ePickupState CPickupSA::GetState()");
	return (ePickupState)this->GetInterface()->State;
}

void CPickupSA::SetState(ePickupState bState)
{
	DEBUG_TRACE("void CPickupSA::SetState(ePickupState bState)");
	this->GetInterface()->State = (BYTE)bState;
}

BYTE CPickupSA::GetAmmo()
{
	DEBUG_TRACE("BYTE CPickupSA::GetAmmo()");
	return this->GetInterface()->bNoAmmo;
}

void CPickupSA::SetAmmo(BYTE bAmmo)
{
	DEBUG_TRACE("void CPickupSA::SetAmmo(BYTE bAmmo)");
	this->GetInterface()->bNoAmmo = bAmmo;
}

long CPickupSA::GetMonetaryValue()
{
	DEBUG_TRACE("long CPickupSA::GetMonetaryValue()");
	return this->GetInterface()->MonetaryValue;
}

void CPickupSA::SetMonetaryValue(long lMonetaryValue)
{
	DEBUG_TRACE("void CPickupSA::SetMonetaryValue(long lMonetaryValue)");
	this->GetInterface()->MonetaryValue = lMonetaryValue;
}

BYTE CPickupSA::IsNearby()
{
	DEBUG_TRACE("BYTE CPickupSA::IsNearby()");
	return this->GetInterface()->bIsPickupNearby;
}


void CPickupSA::GiveUsAPickUpObject(int ForcedObjectIndex)
{
	DEBUG_TRACE("void CPickupSA::GiveUsAPickUpObject(int ForcedObjectIndex)");
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

void CPickupSA::GetRidOfObjects()
{
	DEBUG_TRACE("void CPickupSA::GetRidOfObjects()");
	if(this->GetInterface()->pObject)
		((CWorldSA *)pGame->GetWorld())->Remove(this->GetInterface()->pObject);
	
	if(this->object)
    {
		delete this->object;
        this->object = NULL;
    }
}

void CPickupSA::Remove()
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