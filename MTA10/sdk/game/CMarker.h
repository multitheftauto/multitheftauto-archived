/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CMarker.h
*  PURPOSE:		Marker entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_MARKER
#define __CGAME_MARKER

#include "Common.h"
#include "CEntity.h"
#include "CObject.h"
#include "CPed.h"
#include "CVehicle.h"

#include <windows.h>

#define MARKER_SCALE_SMALL			1
#define MARKER_SCALE_NORMAL			2

class CMarker
{
public:
	virtual void			SetSprite( eMarkerSprite Sprite ) = 0;
	virtual void			SetDisplay( eMarkerDisplay wDisplay ) = 0;
	virtual void			SetScale( WORD wScale ) = 0;

	virtual void			SetColor( eMarkerColor color ) = 0;
	virtual void			SetColor( RGBA color ) = 0;

	virtual void			Remove( void ) = 0;
	virtual bool			IsActive( void ) = 0;

	virtual void			SetPosition( CVector* vecPosition ) = 0;
	virtual const CVector	GetPosition( void ) = 0;

	virtual void			SetEntity( CVehicle* vehicle ) = 0;
	virtual void			SetEntity( CPed* ped ) = 0;
	virtual void			SetEntity( CObject* object ) = 0;
	virtual CEntity*		GetEntity( void ) = 0;
};

#endif