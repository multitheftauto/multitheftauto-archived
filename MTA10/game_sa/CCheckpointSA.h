/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CCheckpointSA.h
*  PURPOSE:		Header file for checkpoint entity class
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_CHECKPOINT
#define __CGAMESA_CHECKPOINT

#include <game/CCheckpoint.h>
#include "Common.h"

class CCheckpointSAInterface
{
public:
	short		m_nType;
	bool		m_bIsUsed;
	bool		m_rotFlag;
	DWORD		m_nIdentifier;
	RGBA		rwColour;
	short 		m_nPulsePeriod;
	short		m_nRotateRate;	// deg per frame (in either direction)
	CVectorGTA	m_pos;
	CVectorGTA	m_pointDir;
	float 		m_fPulseFraction;
	float 		m_fSize;
	float 		m_fCameraRange;
	float		m_multiSize;	
};

class CCheckpointSA : public CCheckpoint
{
private:
	CCheckpointSAInterface*	internalInterface;
public:
	CCheckpointSAInterface*	GetInterface( void ) { return internalInterface; }

	// constructor
					CCheckpointSA( CCheckpointSAInterface * checkpointInterface )
					{ internalInterface = checkpointInterface; };

	void			SetPosition( const CVector& vecPosition );
	const CVector	GetPosition( void );
	void			SetPointDirection( const CVector& vecPointDirection );
	const CVector	GetPointDirection( void );
	DWORD			GetType( void ); // TODO: use enum
	void			SetType( short wType ); // TODO: doesn't work properly (not virtual)
	bool			IsActive( void );
	void			Activate( void );
	DWORD			GetIdentifier( void );
	void			SetIdentifier( DWORD dwIdentifier );
	RGBA			GetColor( void );
	void			SetColor( RGBA color );
	void			SetPulsePeriod( short wPulsePeriod );
	void			SetRotateRate( short RotateRate );
	float			GetSize( void );
	void			SetSize( float fSize );
	void			SetCameraRange( float fCameraRange );
	void			SetPulseFraction( float fPulseFraction ); // TODO: doesn't work properly (not virtual)
	float			GetPulseFraction( void );
	void			Remove( void );
};

#endif