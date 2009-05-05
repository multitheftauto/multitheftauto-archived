/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CCheckpoint.h
*  PURPOSE:		Checkpoint entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_CHECKPOINT
#define __CGAME_CHECKPOINT

#include <CVector.h>
#include "Common.h"

/**
 * \todo fix SetColor/GetColor, the format is actually BGRA (strange)
 */

enum
{
	CHECKPOINT_TUBE,		// a long tube with arrow as direction
	CHECKPOINT_ENDTUBE,		// finish flag long tube checkpoint
	CHECKPOINT_EMPTYTUBE,	// just a long tube checkpoint
	CHECKPOINT_TORUS,
	CHECKPOINT_TORUS_NOFADE,
	CHECKPOINT_TORUSROT,
	CHECKPOINT_TORUSTHROUGH,
	CHECKPOINT_TORUS_UPDOWN,
	CHECKPOINT_TORUS_DOWN,
	CHECKPOINT_NUM
};

class CCheckpoint
{
public:
	virtual void			SetPosition( const CVector& vecPosition ) = 0;
	virtual const CVector	GetPosition( void ) = 0;
	virtual void			SetPointDirection( const CVector& vecPointDirection ) = 0;
	virtual const CVector	GetPointDirection( void ) = 0;
	virtual DWORD			GetType( void ) = 0; // TODO: needs enum
	virtual bool			IsActive( void ) = 0;
	virtual DWORD			GetIdentifier( void ) = 0;
	virtual RGBA			GetColor( void ) = 0;
	virtual void			SetColor( RGBA color ) = 0;
	virtual void			SetPulsePeriod( WORD wPulsePeriod ) = 0;
	virtual void			SetRotateRate( short RotateRate ) = 0;
	virtual FLOAT			GetSize( void ) = 0;
	virtual void			SetSize( FLOAT fSize ) = 0;
	virtual void			SetCameraRange( FLOAT fCameraRange ) = 0;
	virtual FLOAT			GetPulseFraction( void ) = 0;
	virtual void			Remove( void ) = 0;
};

#endif