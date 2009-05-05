/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CExplosionSA.cpp
*  PURPOSE:		Explosion
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

eExplosionType CExplosionSA::GetExplosionType( void )
{
	return internalInterface->m_ExplosionType;
}

const CVector CExplosionSA::GetExplosionPosition( void )
{
	return CVectorGTA::unwrap( internalInterface->m_vecPosition );
}

void CExplosionSA::SetExplosionPosition( const CVector& vecPosition )
{
    internalInterface->m_vecPosition = vecPosition;
}

/**
 * \todo Handle objects creating explosions
 */
CEntity* CExplosionSA::GetExplosionCreator( void )
{
	// we create a temporary entity to take care of finding the type of entity it is
	CEntitySA * entity = new CEntitySA;
	entity->m_pInterface = this->GetInterface()->m_pEntExplosionOwner;
	eEntityType entityType = entity->GetEntityType();
	delete entity;

	CPoolsSA * pools = (CPoolsSA*)pGame->GetPools();

	switch(entityType)
	{
	case ENTITY_TYPE_PED:
		return (CEntity *)(pools->GetPed((DWORD *)this->GetInterface()->m_pEntExplosionOwner));
		break;
	case ENTITY_TYPE_VEHICLE:
		return (CEntity *)(pools->GetVehicle((DWORD *)this->GetInterface()->m_pEntExplosionOwner));
		break;
	case ENTITY_TYPE_OBJECT:
		break;
	}
	return NULL;
}

CEntity* CExplosionSA::GetExplodingEntity( void )
{
    return NULL;
}

bool CExplosionSA::IsActive( void )
{
	return internalInterface->m_cExplosionActive ? true : false;
}

void CExplosionSA::Remove( void )
{
	internalInterface->m_cExplosionActive = 0;
}

float CExplosionSA::GetExplosionForce( void )
{
	return this->GetInterface()->m_fExplosionForce;
}

void CExplosionSA::SetExplosionForce( float fForce )
{
	this->GetInterface()->m_fExplosionForce = fForce;
}

void CExplosionSA::SetSilent( bool bSilent )
{
	this->GetInterface()->m_bMakeSound = !bSilent;
}

unsigned long CExplosionSA::GetActivationTimer( void )
{
	return this->GetInterface()->m_ActivationTime;
}

void CExplosionSA::SetActivationTimer( unsigned long ulActivationTime )
{
	this->GetInterface()->m_ActivationTime = ulActivationTime;
}

DWORD CExplosionSA::GetExpiryTime( void )
{
	return this->GetInterface()->m_TimeExpires;
}

void CExplosionSA::SetExpiryTime( DWORD dwExpiryTime )
{
	this->GetInterface()->m_TimeExpires = dwExpiryTime;
}

float CExplosionSA::GetExplosionRadius( void )
{
	return this->GetInterface()->m_fExplosionRadius;
}

void CExplosionSA::SetExplosionRadius( float fRadius )
{
	this->GetInterface()->m_fExplosionRadius = fRadius;
}
