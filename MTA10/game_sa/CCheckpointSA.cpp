/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CCheckpointSA.cpp
*  PURPOSE:		Checkpoint entity
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

void CCheckpointSA::SetPosition( const CVector& vecPosition )
{
	this->GetInterface()->m_pos = vecPosition;
}

const CVector CCheckpointSA::GetPosition( void )
{
	return CVectorGTA::unwrap( this->GetInterface()->m_pos );
}

void CCheckpointSA::SetPointDirection( const CVector& vecPointDirection )
{
	this->GetInterface()->m_pointDir = vecPointDirection;
}

const CVector CCheckpointSA::GetPointDirection( void )
{
	return CVectorGTA::unwrap( this->GetInterface()->m_pointDir );
}

DWORD CCheckpointSA::GetType( void )
{
	return this->GetInterface()->m_nType;
}

void CCheckpointSA::SetType( short wType )
{
	this->GetInterface()->m_nType = wType;
}

bool CCheckpointSA::IsActive( void )
{
	return (bool)this->GetInterface()->m_bIsUsed;
}

void CCheckpointSA::Activate( void )
{
	this->GetInterface()->m_bIsUsed = true;
}

DWORD CCheckpointSA::GetIdentifier( void )
{
	DEBUG_TRACE("DWORD CCheckpointSA::GetIdentifier()");
	return this->GetInterface()->m_nIdentifier;
}

void CCheckpointSA::SetIdentifier( DWORD dwIdentifier )
{
	this->GetInterface()->m_nIdentifier = dwIdentifier;
}

RGBA CCheckpointSA::GetColor( void )
{
	return this->GetInterface()->rwColour;
}

void CCheckpointSA::SetColor( RGBA color )
{
	this->GetInterface()->rwColour = color;
}

void CCheckpointSA::SetPulsePeriod(short wPulsePeriod)
{
	DEBUG_TRACE("void CCheckpointSA::SetPulsePeriod(short wPulsePeriod)");
	this->GetInterface()->m_nPulsePeriod = wPulsePeriod;
}

void CCheckpointSA::SetRotateRate(short RotateRate)
{
	DEBUG_TRACE("void CCheckpointSA::SetRotateRate(short RotateRate)");
	this->GetInterface()->m_nRotateRate = RotateRate;

	if ( RotateRate == 0 )
	{
		this->GetInterface()->m_rotFlag = true;
	}
	else
	{
		this->GetInterface()->m_rotFlag = false;
	}
}

float CCheckpointSA::GetSize()
{
	DEBUG_TRACE("float CCheckpointSA::GetSize()");
	return this->GetInterface()->m_fSize;
}

void CCheckpointSA::SetSize(float fSize)
{
	DEBUG_TRACE("void CCheckpointSA::SetSize(float fSize)");
	this->GetInterface()->m_fSize = fSize;
}

void CCheckpointSA::SetCameraRange(float fCameraRange)
{
	DEBUG_TRACE("void CCheckpointSA::SetCameraRange(float fCameraRange)");
	this->GetInterface()->m_fCameraRange = fCameraRange;
}

void CCheckpointSA::SetPulseFraction(float fPulseFraction)
{
	DEBUG_TRACE("void CCheckpointSA::SetPulseFraction(float fPulseFraction)");
	this->GetInterface()->m_fPulseFraction = fPulseFraction;
}

float CCheckpointSA::GetPulseFraction()
{
	DEBUG_TRACE("float CCheckpointSA::GetPulseFraction()");
	return this->GetInterface()->m_fPulseFraction;
}

void CCheckpointSA::Remove()
{
	DEBUG_TRACE("void CCheckpointSA::Remove()");
	this->GetInterface()->m_bIsUsed = false;
	this->GetInterface()->m_nType = 257;	
	this->GetInterface()->rwColour = 0;
	C3DMarkerSA * pMarker = (C3DMarkerSA * )(((C3DMarkersSA *)pGame->Get3DMarkers())->FindMarker ( this->GetIdentifier() ));
	if ( pMarker )
	{
		//pMarker->Disable();
		//pMarker->DeleteMarkerObject();
	}
	else
	{
		#ifdef _DEBUG
		//OutputDebugString ( "Couldn't find marker for checkpoint!" );
		#endif
	}
}
