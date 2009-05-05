/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CCamSA.cpp
*  PURPOSE:		Camera entity
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*               Jax <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

const CVector CCamSA::GetFront( void )
{
	return CVectorGTA::unwrap( this->GetInterface()->Front );
}

const CVector CCamSA::GetUp( void )
{
	return CVectorGTA::unwrap( this->GetInterface()->Up );
}

const CVector CCamSA::GetSource( void )
{
	return CVectorGTA::unwrap( this->GetInterface()->Source );
}

const CVector CCamSA::GetFixedModeSource( void )
{
	CCamSAInterface * pCamInterface = this->GetInterface();
	return CVectorGTA::unwrap( pCamInterface->m_cvecCamFixedModeSource );
}

const CVector CCamSA::GetFixedModeVector( void )
{
	return CVectorGTA::unwrap( this->GetInterface()->m_cvecCamFixedModeVector );
}

CEntity* CCamSA::GetTargetEntity( void )
{
    CEntitySAInterface * pInterface = this->internalInterface->CamTargetEntity;
    CPoolsSA * pPools = ((CPoolsSA *)pGame->GetPools());
	CEntity * pReturn = NULL;

	if ( pPools && pInterface )
	{
		switch ( pInterface->nType )
		{
            case ENTITY_TYPE_PED:
                pReturn = (CEntity*)(pPools->GetPed((DWORD *)pInterface));
                break;
			case ENTITY_TYPE_VEHICLE:
				pReturn = (CEntity*)(pPools->GetVehicle((DWORD *)pInterface));
				break;
            case ENTITY_TYPE_OBJECT:
                pReturn = (CEntity*)(pPools->GetObject ((DWORD *)pInterface));
                break;
			default:
				break;
		}
	}
	return pReturn;
}
