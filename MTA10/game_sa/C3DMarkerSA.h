/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/C3DMarkerSA.h
*  PURPOSE:		Header file for 3D Marker entity class
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_3DMARKER
#define __CGAMESA_3DMARKER

#include <game/C3DMarker.h>
#include "Common.h"

#define FUNC_DeleteMarkerObject			0x722390

class C3DMarkerSAInterface
{
public:
	CMatrix4		m_mat;	// local space to world space transform // 0
	DWORD			dwPad,dwPad2;	// not sure why we need these, it appears to be this way though (eAi)  // 64/68
	RpClump 		*m_pRwObject; // 72
	DWORD			*m_pMaterial; // 76
	
	short			m_nType; // 80
	bool			m_bIsUsed;	// has this marker been allocated this frame?	 // 82
	DWORD			m_nIdentifier; // 84

	RGBA			rwColour; // 88 
	short			m_nPulsePeriod; // 92
	short			m_nRotateRate;	// deg per frame (in either direction) // 94
	DWORD			m_nStartTime; // 96
	float			m_fPulseFraction;  // 100
	float			m_fStdSize; // 104
	float			m_fSize; // 108
	float			m_fBrightness; // 112
	float			m_fCameraRange; // 116

	CVectorGTA		m_normal;			// Normal of the object point at             // 120
	// the following variables remember the last time we read the heigh of the
	// map. Using this we don't have to do this every frame and we can still have moving markers.
	short			m_LastMapReadX, m_LastMapReadY; // 132 / 134
	float			m_LastMapReadResultZ; // 136
	float			m_roofHeight; // 140
	CVectorGTA		m_lastPosition; // 144
	DWORD			m_OnScreenTestTime;		// time last screen check was done // 156
};

class C3DMarkerSA : public C3DMarker
{
private:
	C3DMarkerSAInterface*		internalInterface;
public:
	// constructor
								C3DMarkerSA( C3DMarkerSAInterface* markerInterface )
								{ internalInterface = markerInterface; };

	C3DMarkerSAInterface*		GetInterface( void )	{ return internalInterface; }

	void						SetPosition( const CVector& vecPosition );
	const CVector				GetPosition( void );
	DWORD						GetType( void ); // TODO: needs enum
	void						SetType( DWORD dwType ); // TODO: not virtual, doesnt work properly
	bool						IsActive( void );
	DWORD						GetIdentifier( void );
	RGBA						GetColor( void );
	void						SetColor( RGBA color ); // TODO: actually BGRA
	void						SetPulsePeriod( short wPulsePeriod );
	void						SetRotateRate( short RotateRate );
	float						GetSize( void );
	void						SetSize( float fSize );
	float						GetBrightness( void );
	void						SetBrightness( float fBrightness );
	void						SetCameraRange( float fCameraRange );
	void						SetPulseFraction( float fPulseFraction ); // TODO: not virtual, doesnt work properly
	float						GetPulseFraction( void );
	void						Disable( void );
	void						DeleteMarkerObject( void );
    void						Reset( void );
    void						SetActive( void )	{ this->internalInterface->m_bIsUsed = true;};
    RpClump*					GetRwObject( void )	{ return this->internalInterface->m_pRwObject; }
};

#endif