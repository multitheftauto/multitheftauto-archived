/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/C3DMarkerSA.cpp
*  PURPOSE:		3D Marker entity
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

void C3DMarkerSA::SetPosition( const CVector& vecPosition )
{
	DEBUG_TRACE("void C3DMarkerSA::SetPosition( const CVector& vecPosition )");
    this->GetInterface()->m_mat.setTranslation( vecPosition );
}

const CVector C3DMarkerSA::GetPosition( void )
{
	DEBUG_TRACE("const CVector& C3DMarkerSA::GetPosition( void )");
	return this->GetInterface()->m_mat.getTranslation();
}

DWORD C3DMarkerSA::GetType()
{
	DEBUG_TRACE("DWORD C3DMarkerSA::GetType()");
	return this->GetInterface()->m_nType;
}

void C3DMarkerSA::SetType(DWORD dwType)
{
	DEBUG_TRACE("void C3DMarkerSA::SetType(DWORD dwType)");
	this->GetInterface()->m_nType = (unsigned short)(dwType);
}

bool C3DMarkerSA::IsActive()
{
	DEBUG_TRACE("bool C3DMarkerSA::IsActive()");
	return (bool)this->GetInterface()->m_bIsUsed;
}

DWORD C3DMarkerSA::GetIdentifier()
{
	DEBUG_TRACE("DWORD C3DMarkerSA::GetIdentifier()");
	return this->GetInterface()->m_nIdentifier;
}

RGBA C3DMarkerSA::GetColor()
{
	DEBUG_TRACE("RGBA C3DMarkerSA::GetColor()");
	return this->GetInterface()->rwColour;
}

void C3DMarkerSA::SetColor(RGBA color)
{
	this->GetInterface()->rwColour = color;
}

void C3DMarkerSA::SetPulsePeriod(WORD wPulsePeriod)
{
	DEBUG_TRACE("void C3DMarkerSA::SetPulsePeriod(WORD wPulsePeriod)");
	this->GetInterface()->m_nPulsePeriod = wPulsePeriod;
}

void C3DMarkerSA::SetRotateRate(short RotateRate)
{
	DEBUG_TRACE("void C3DMarkerSA::SetRotateRate(short RotateRate)");
	this->GetInterface()->m_nRotateRate = RotateRate;
}

FLOAT C3DMarkerSA::GetSize()
{
	DEBUG_TRACE("FLOAT C3DMarkerSA::GetSize()");
	return this->GetInterface()->m_fSize;
}

void C3DMarkerSA::SetSize(FLOAT fSize)
{
	DEBUG_TRACE("void C3DMarkerSA::SetSize(FLOAT fSize)");
	this->GetInterface()->m_fSize = fSize;
}

FLOAT C3DMarkerSA::GetBrightness()
{
	DEBUG_TRACE("FLOAT C3DMarkerSA::GetBrightness()");
	return this->GetInterface()->m_fBrightness;
}

void C3DMarkerSA::SetBrightness(FLOAT fBrightness)
{
	DEBUG_TRACE("void C3DMarkerSA::SetBrightness(FLOAT fBrightness)");
	this->GetInterface()->m_fBrightness = fBrightness;
}

void C3DMarkerSA::SetCameraRange(FLOAT fCameraRange)
{
	DEBUG_TRACE("void C3DMarkerSA::SetCameraRange(FLOAT fCameraRange)");
	this->GetInterface()->m_fCameraRange = fCameraRange;
}

void C3DMarkerSA::SetPulseFraction(FLOAT fPulseFraction)
{
	DEBUG_TRACE("void C3DMarkerSA::SetPulseFraction(FLOAT fPulseFraction)");
	this->GetInterface()->m_fPulseFraction = fPulseFraction;
}

FLOAT C3DMarkerSA::GetPulseFraction()
{
	DEBUG_TRACE("FLOAT C3DMarkerSA::GetPulseFraction()");
	return this->GetInterface()->m_fPulseFraction;
}

void C3DMarkerSA::Disable ()
{
	DEBUG_TRACE("void C3DMarkerSA::Disable ()");
	this->GetInterface()->m_nIdentifier = 0;
}

void C3DMarkerSA::DeleteMarkerObject ()
{
	if ( this->GetInterface()->m_pRwObject )
	{
		DWORD dwFunc = FUNC_DeleteMarkerObject;
		DWORD dwThis = (DWORD)this->GetInterface();
		_asm
		{
			mov		ecx, dwThis
			call	dwFunc
		}

		//OutputDebugString ( "Object destroyed!" );
	}
	else
	{
		//OutputDebugString ( "No object to destroy!" );
	}
}

void C3DMarkerSA::Reset()
{
	this->internalInterface->m_mat.setTranslation( CVectorGTA::unwrap( this->internalInterface->m_lastPosition ) );
}
