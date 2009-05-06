/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CFireSA.cpp
*  PURPOSE:		Fire
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*               Jax <>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*               Alberto Alonso <rydencillo@gmail.com>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

/**
 * Put the fire out
 */
void CFireSA::Extinguish( void )
{
	DWORD dwFunction = FUNC_Extinguish;
    DWORD dwPointer = (DWORD)this->internalInterface;
	_asm
	{
		mov		ecx, dwPointer
		call	dwFunction
	}
    this->internalInterface->bActive = FALSE;
}

/**
 * Gets the position the fire is burning at
 * @return CVector * containing the fire's position
 */
const CVector CFireSA::GetPosition( void )
{
	return CVectorGTA::unwrap( internalInterface->vecPosition );
}

/**
 * Set the position the fire is burning at. This won't have any effect if this fire has a target set
 * @param vecPosition CVector * containing the desired position for the fire.
 * @see CFireSA::SetTarget
 */
void CFireSA::SetPosition( const CVector& vecPosition )
{
	this->internalInterface->entityTarget = 0;
	internalInterface->vecPosition = vecPosition;
}

/**
 * Set the time that the fire will be extinguished.
 * @param dwTime DWORD containing the time that the fire will be extinguished.  This is in game-time units which can be got from CGame::GetSystemTime;
 */
void CFireSA::SetTimeToBurnOut( DWORD dwTime )
{
	internalInterface->nTimeToBurn = dwTime;
}

DWORD CFireSA::GetTimeToBurnOut( void )
{
	return internalInterface->nTimeToBurn;
}

CEntity * CFireSA::GetCreator( void )
{
	CEntity * creatorEntity = NULL;
	CEntitySAInterface * createEntitySA = internalInterface->entityCreator;
	CPoolsSA * pPools = ((CPoolsSA *)pGame->GetPools());
	if ( pPools && createEntitySA )
	{
		switch ( createEntitySA->nType )
		{
		case ENTITY_TYPE_PED:
			creatorEntity = pPools->GetPed((DWORD *)createEntitySA);
            break;
		case ENTITY_TYPE_VEHICLE:
			creatorEntity = pPools->GetVehicle((DWORD *)createEntitySA);
            break;
        default:
            creatorEntity = NULL;
		}
	}
	return creatorEntity;
}

CEntity	* CFireSA::GetEntityOnFire( void )
{
	CEntity * TargetEntity = NULL;
    CEntitySAInterface * TargetEntitySA = internalInterface->entityTarget;
	CPoolsSA * pPools = ((CPoolsSA *)pGame->GetPools());
	if ( pPools && TargetEntitySA )
	{
		switch ( TargetEntitySA->nType )
		{
		case ENTITY_TYPE_PED:
			TargetEntity = pPools->GetPed((DWORD *)TargetEntitySA);
            break;
		case ENTITY_TYPE_VEHICLE:
			TargetEntity = pPools->GetVehicle((DWORD *)TargetEntitySA);
            break;
        default:
            TargetEntity = NULL;
		}
	}
	return TargetEntity;
}

void CFireSA::SetTarget( CEntity * entity )
{
    if ( entity )
    {
        CEntitySA* pEntitySA = dynamic_cast < CEntitySA* > ( entity );
	    if ( pEntitySA )
		    internalInterface->entityTarget = pEntitySA->GetInterface();
    }
    else
    {
        internalInterface->entityTarget = NULL;
    }
}

bool CFireSA::IsIgnited( void )
{
	return internalInterface->bActive;
}

bool CFireSA::IsFree( void )
{
	if( !internalInterface->bActive && !internalInterface->bCreatedByScript )
		return true;
	else
		return false;
}

void CFireSA::SetSilent( bool bSilent )
{
	internalInterface->bMakesNoise = !bSilent;
}

bool CFireSA::IsBeingExtinguished( void )
{
	return internalInterface->bBeingExtinguished;
}

void CFireSA::Ignite( void )
{
	this->internalInterface->bActive = TRUE;

	CVectorGTA* vecPosition = &(internalInterface->vecPosition);
	DWORD dwFunc = FUNC_CreateFxSysForStrength;
    DWORD dwThis = (DWORD)this->internalInterface;
	_asm
	{
		mov		ecx, dwThis
		push	0
		push	vecPosition
		call	dwFunc
	}
	this->internalInterface->bBeingExtinguished = 0;
	this->internalInterface->bFirstGeneration = 1;
	this->internalInterface->nNumGenerationsAllowed = 100;
}

float CFireSA::GetStrength( void )
{
	return this->internalInterface->Strength;
}

void CFireSA::SetStrength( float fStrength )
{
	this->internalInterface->Strength = fStrength;
}

void CFireSA::SetNumGenerationsAllowed( char nGenerations )
{
    this->internalInterface->nNumGenerationsAllowed = nGenerations;
}
