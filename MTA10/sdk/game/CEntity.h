/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CEntity.h
*  PURPOSE:		Base entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_ENTITY
#define __CGAME_ENTITY

#include "Common.h"
#include <CMatrix.h>
#include <CVector.h>
#include "RenderWare.h"

#include <windows.h>

enum eEntityType
{
    ENTITY_TYPE_NOTHING,
    ENTITY_TYPE_BUILDING,
    ENTITY_TYPE_VEHICLE,
    ENTITY_TYPE_PED,
    ENTITY_TYPE_OBJECT,
    ENTITY_TYPE_DUMMY,
    ENTITY_TYPE_NOTINPOOLS
};

enum eEntityStatus
{
	STATUS_PLAYER,
	STATUS_PLAYER_PLAYBACKFROMBUFFER,
	STATUS_SIMPLE,
	STATUS_PHYSICS,
	STATUS_ABANDONED,
	STATUS_WRECKED,
	STATUS_TRAIN_MOVING,
	STATUS_TRAIN_NOT_MOVING,
	STATUS_HELI,
	STATUS_PLANE,
	STATUS_PLAYER_REMOTE,
	STATUS_PLAYER_DISABLED,
	STATUS_TRAILER,
	STATUS_SIMPLE_TRAILER
};

class CEntity
{
public:
    virtual                             ~CEntity ( void ) {};

    //	virtual void						SetModelAlpha ( int iAlpha )=0;
    virtual class CEntitySAInterface *  GetInterface()=0;
	virtual void						ProcessControl ( void )=0;
	virtual void						SetupLighting ( )=0;
	virtual void						Render ( )=0;
	virtual void						SetOrientation ( float fX, float fY, float fZ )=0;
    virtual void                        FixBoatOrientation ( void ) = 0;
	virtual void						SetPosition ( const CVector& vecPosition )=0;
	virtual CVector&					GetPosition ( CVector& vector )=0;
	virtual CMatrix4&					GetMatrix ( CMatrix4& matrix )=0;
	virtual void						SetMatrix ( const CMatrix4& matrix )=0;
	virtual WORD						GetModelIndex ()=0;
	virtual eEntityType					GetEntityType ()=0;
	virtual FLOAT						GetDistanceFromCentreOfMassToBaseOfModel()=0;
	virtual void						SetEntityStatus( eEntityStatus bStatus )=0;
	virtual eEntityStatus			    GetEntityStatus( )=0;
	virtual bool						IsOnScreen ()=0;
	virtual void						SetUnderwater ( bool bUnderwater )=0;
	virtual bool						GetUnderwater ( void )=0;
    virtual RwFrame *                   GetFrameFromId ( int id )=0;
    virtual RwMatrix *                  GetLTMFromId ( int id )=0;

	virtual RpClump *					GetRpClump ( void ) = 0;

    virtual bool                        IsVisible ( void ) = 0;
    virtual void                        SetVisible ( bool bVisible ) = 0;

	virtual void						SetDoNotRemoveFromGameWhenDeleted ( bool bDoNotRemoveFromGame ) = 0;
	virtual void						SetUsesCollision( bool bUsesCollision ) = 0;
    virtual bool                        IsStatic( void ) = 0;
	virtual void						SetStatic( bool bStatic ) = 0;
	virtual void						SetAlpha( DWORD dwAlpha ) = 0;

    virtual bool                        IsPlayingAnimation( char * szAnimName ) = 0;

    virtual void*                       GetStoredPointer( void ) = 0;
    virtual void                        SetStoredPointer( void* pPointer ) = 0;

    virtual BYTE                        GetAreaCode( void ) = 0;
    virtual void                        SetAreaCode ( BYTE areaCode ) = 0;

    virtual bool                        IsStaticWaitingForCollision( void ) = 0;
    virtual void                        SetStaticWaitingForCollision( bool bStatic ) = 0;

    virtual void                        GetImmunities( bool & bNoClip, bool & bFrozen, bool & bBulletProof, bool & bFlameProof, bool & bUnk, bool & bUnk2, bool & bCollisionProof, bool & bExplosionProof ) = 0;
    virtual unsigned long               GetArrayID( void ) = 0;
};

#endif