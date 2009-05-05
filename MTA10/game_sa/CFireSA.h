/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CFireSA.h
*  PURPOSE:		Header file for fire class
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*               Jax <>
*               Christian Myhre Lundheim <>
*               Cecill Etheredge <ijsf@gmx.net>
*               Alberto Alonso <rydencillo@gmail.com>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_FIRE
#define __CGAMESA_FIRE

#include <game/CFire.h>
#include "Common.h"
#include "CEntitySA.h"

#define FUNC_Extinguish					0x5393F0        //  ##SA##
#define	FUNC_CreateFxSysForStrength		0x539360		//  ##SA##

class FxSystem_c; // we don't actually define this anywhere

class CFireSAInterface : public CFireInterface
{
public:
	BYTE					bActive : 1;
	BYTE					bCreatedByScript : 1;
	BYTE					bMakesNoise : 1;
	BYTE					bBeingExtinguished : 1;
	BYTE					bFirstGeneration : 1;
	WORD                    ScriptReferenceIndex;
	CVectorGTA              vecPosition; 
	CEntitySAInterface*		entityTarget; 
	CEntitySAInterface*		entityCreator;	
	DWORD					nTimeToBurn; 
	FLOAT					Strength;
	signed char				nNumGenerationsAllowed; 
	BYTE					RemovalDist;

	FxSystem_c*				m_fxSysPtr;
};

class CFireSA : public CFire
{
	CFireSAInterface*		internalInterface;

public:
	// constructor
							CFireSA( CFireSAInterface * fireInterface )
							{ this->internalInterface = fireInterface; }

	void					Extinguish( void );
	const CVector			GetPosition( void );
	void					SetPosition( const CVector& vecPosition );
	void					SetTimeToBurnOut( DWORD dwTime );
	DWORD					GetTimeToBurnOut( void );
	CEntity*				GetCreator( void );
	CEntity*				GetEntityOnFire( void );
	void					SetTarget( CEntity * entity );
	bool					IsIgnited( void );
	bool					IsFree( void );
	void					SetSilent( bool bSilent );
	bool					IsBeingExtinguished( void );
	void					Ignite( void );
	FLOAT					GetStrength( void );
	void					SetStrength( float fStrength );
    void                    SetNumGenerationsAllowed( char nGenerations );
    inline CFireInterface*  GetInterface( void ) { return this->internalInterface; }
};

#endif