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
    this->GetInterface()->m_mat.setTranslation( vecPosition );
}

const CVector C3DMarkerSA::GetPosition( void )
{
	return this->GetInterface()->m_mat.getTranslation();
}

DWORD C3DMarkerSA::GetType( void )
{
	return this->GetInterface()->m_nType;
}

void C3DMarkerSA::SetType( DWORD dwType )
{
	this->GetInterface()->m_nType = (unsigned short)(dwType);
}

bool C3DMarkerSA::IsActive( void )
{
	return (bool)this->GetInterface()->m_bIsUsed;
}

DWORD C3DMarkerSA::GetIdentifier( void )
{
	return this->GetInterface()->m_nIdentifier;
}

RGBA C3DMarkerSA::GetColor( void )
{
	return this->GetInterface()->rwColour;
}

void C3DMarkerSA::SetColor( RGBA color )
{
	this->GetInterface()->rwColour = color;
}

void C3DMarkerSA::SetPulsePeriod( short wPulsePeriod )
{
	this->GetInterface()->m_nPulsePeriod = wPulsePeriod;
}

void C3DMarkerSA::SetRotateRate( short RotateRate )
{
	this->GetInterface()->m_nRotateRate = RotateRate;
}

float C3DMarkerSA::GetSize( void )
{
	return this->GetInterface()->m_fSize;
}

void C3DMarkerSA::SetSize( float fSize )
{
	this->GetInterface()->m_fSize = fSize;
}

float C3DMarkerSA::GetBrightness( void )
{
	return this->GetInterface()->m_fBrightness;
}

void C3DMarkerSA::SetBrightness( float fBrightness )
{
	this->GetInterface()->m_fBrightness = fBrightness;
}

void C3DMarkerSA::SetCameraRange( float fCameraRange )
{
	this->GetInterface()->m_fCameraRange = fCameraRange;
}

void C3DMarkerSA::SetPulseFraction( float fPulseFraction )
{
	this->GetInterface()->m_fPulseFraction = fPulseFraction;
}

float C3DMarkerSA::GetPulseFraction( void )
{
	return this->GetInterface()->m_fPulseFraction;
}

void C3DMarkerSA::Disable( void )
{
	this->GetInterface()->m_nIdentifier = 0;
}

void C3DMarkerSA::DeleteMarkerObject( void )
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

void C3DMarkerSA::Reset( void )
{
	this->internalInterface->m_mat.setTranslation( CVectorGTA::unwrap( this->internalInterface->m_lastPosition ) );
}
