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
	WORD		m_nType;
	bool		m_bIsUsed;
	bool		m_rotFlag;
	DWORD		m_nIdentifier;
	RGBA		rwColour;
	WORD 		m_nPulsePeriod;
	short		m_nRotateRate;	// deg per frame (in either direction)
	CVectorGTA	m_pos;
	CVectorGTA	m_pointDir;
	FLOAT 		m_fPulseFraction;
	FLOAT 		m_fSize;
	FLOAT 		m_fCameraRange;
	FLOAT		m_multiSize;	
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
	void			SetType( WORD wType ); // TODO: doesn't work properly (not virtual)
	bool			IsActive( void );
	void			Activate( void );
	DWORD			GetIdentifier( void );
	void			SetIdentifier( DWORD dwIdentifier );
	RGBA			GetColor( void );
	void			SetColor( RGBA color );
	void			SetPulsePeriod( WORD wPulsePeriod );
	void			SetRotateRate( short RotateRate );
	FLOAT			GetSize( void );
	void			SetSize( FLOAT fSize );
	void			SetCameraRange( FLOAT fCameraRange );
	void			SetPulseFraction( FLOAT fPulseFraction ); // TODO: doesn't work properly (not virtual)
	FLOAT			GetPulseFraction( void );
	void			Remove( void );
};

#endif