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

void CCheckpointSA::SetPosition(CVector * vecPosition)
{
	DEBUG_TRACE("void CCheckpointSA::SetPosition(CVector * vecPosition)");
	memcpy(&this->GetInterface()->m_pos, vecPosition, sizeof(CVector));
}

CVector * CCheckpointSA::GetPosition()
{
	DEBUG_TRACE("CVector * CCheckpointSA::GetPosition()");
	return &this->GetInterface()->m_pos;
}

void CCheckpointSA::SetPointDirection(CVector * vecPointDirection)
{
	DEBUG_TRACE("void CCheckpointSA::SetPointDirection(CVector * vecPointDirection)");
	memcpy(&this->GetInterface()->m_pointDir, vecPointDirection, sizeof(CVector));
}

CVector * CCheckpointSA::GetPointDirection()
{
	DEBUG_TRACE("CVector * CCheckpointSA::GetPointDirection()");
	return &this->GetInterface()->m_pointDir;
}

DWORD CCheckpointSA::GetType()
{
	DEBUG_TRACE("DWORD CCheckpointSA::GetType()");
	return this->GetInterface()->m_nType;
}

void CCheckpointSA::SetType(WORD wType)
{
	DEBUG_TRACE("void CCheckpointSA::SetType(DWORD dwType)");
	this->GetInterface()->m_nType = wType;
}

bool CCheckpointSA::IsActive()
{
	DEBUG_TRACE("bool CCheckpointSA::IsActive()");
	return (bool)this->GetInterface()->m_bIsUsed;
}

void CCheckpointSA::Activate()
{
	DEBUG_TRACE("void CCheckpointSA::Activate()");
	this->GetInterface()->m_bIsUsed = true;
}

DWORD CCheckpointSA::GetIdentifier()
{
	DEBUG_TRACE("DWORD CCheckpointSA::GetIdentifier()");
	return this->GetInterface()->m_nIdentifier;
}

void CCheckpointSA::SetIdentifier(DWORD dwIdentifier)
{
	DEBUG_TRACE("void CCheckpointSA::SetIdentifier(DWORD dwIdentifier)");
	this->GetInterface()->m_nIdentifier = dwIdentifier;
}

RGBA CCheckpointSA::GetColor()
{
	DEBUG_TRACE("RGBA CCheckpointSA::GetColor()");
	return this->GetInterface()->rwColour;
}

void CCheckpointSA::SetColor(RGBA color)
{
	DEBUG_TRACE("void CCheckpointSA::SetColor(RGBA color)");
	this->GetInterface()->rwColour = color;
}

void CCheckpointSA::SetPulsePeriod(WORD wPulsePeriod)
{
	DEBUG_TRACE("void CCheckpointSA::SetPulsePeriod(WORD wPulsePeriod)");
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

FLOAT CCheckpointSA::GetSize()
{
	DEBUG_TRACE("FLOAT CCheckpointSA::GetSize()");
	return this->GetInterface()->m_fSize;
}

void CCheckpointSA::SetSize(FLOAT fSize)
{
	DEBUG_TRACE("void CCheckpointSA::SetSize(FLOAT fSize)");
	this->GetInterface()->m_fSize = fSize;
}

void CCheckpointSA::SetCameraRange(FLOAT fCameraRange)
{
	DEBUG_TRACE("void CCheckpointSA::SetCameraRange(FLOAT fCameraRange)");
	this->GetInterface()->m_fCameraRange = fCameraRange;
}

void CCheckpointSA::SetPulseFraction(FLOAT fPulseFraction)
{
	DEBUG_TRACE("void CCheckpointSA::SetPulseFraction(FLOAT fPulseFraction)");
	this->GetInterface()->m_fPulseFraction = fPulseFraction;
}

FLOAT CCheckpointSA::GetPulseFraction()
{
	DEBUG_TRACE("FLOAT CCheckpointSA::GetPulseFraction()");
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
