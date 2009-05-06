/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CColPointSA.h
*  PURPOSE:		Header file for collision point class
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_COLPOINT
#define __CGAMESA_COLPOINT

#include <game/CColPoint.h>
#include <CVector.h>

class CColPointSAInterface
{
public:
	CVectorGTA Position;
	float fUnknown1;
	CVectorGTA Normal;
	float fUnknown2;
	BYTE bSurfaceTypeA;
	BYTE bPieceTypeA;
	BYTE bLightingA;
	BYTE bSurfaceTypeB;
	BYTE bPieceTypeB;
	BYTE bLightingB;
	float fDepth;
/*
	+0 Position (12 Bytes  Vector)
	+12?
	+16 Normal (12 Bytes  Vector)
	+32 SurfaceTypeA
	+33 PieceTypeA
	+34 LightingA (assumed)
	+35 SurfaceTypeB 
	+36 PieceTypeB
	+37 LightingB 
	+40 Depth (float)*/
};

class CColPointSA : public CColPoint
{
private:
	CColPointSAInterface * internalInterface;
public:
	CColPointSAInterface * GetInterface() { return this->internalInterface; }
	CColPointSA();
    CColPointSA(CColPointSAInterface * pInterface ) { this->internalInterface = pInterface; };

	const CVector GetPosition( void ) { return CVectorGTA::unwrap( this->GetInterface()->Position ); };
	void SetPosition( const CVector& vecPosition ) { this->GetInterface()->Position = vecPosition; };

	const CVector GetNormal( void ) { return CVectorGTA::unwrap( this->GetInterface()->Normal ); };
	void SetNormal( const CVector& vecNormal ) { this->GetInterface()->Normal = vecNormal; };

	BYTE GetSurfaceTypeA() { return this->GetInterface()->bSurfaceTypeA; };
	BYTE GetSurfaceTypeB() { return this->GetInterface()->bSurfaceTypeB; };

	void SetSurfaceTypeA(BYTE bSurfaceType) { this->GetInterface()->bSurfaceTypeA = bSurfaceType; };
	void SetSurfaceTypeB(BYTE bSurfaceType) { this->GetInterface()->bSurfaceTypeB = bSurfaceType; };

	BYTE GetPieceTypeA() { return this->GetInterface()->bPieceTypeA; };
	BYTE GetPieceTypeB() { return this->GetInterface()->bPieceTypeB; };

	void SetPieceTypeA(BYTE bPieceType) { this->GetInterface()->bPieceTypeA = bPieceType; };
	void SetPieceTypeB(BYTE bPieceType) { this->GetInterface()->bPieceTypeB = bPieceType; };

	BYTE GetLightingA() { return this->GetInterface()->bLightingA; };
	BYTE GetLightingB() { return this->GetInterface()->bLightingB;};

	void SetLightingA(BYTE bLighting) { this->GetInterface()->bLightingA = bLighting; };
	void SetLightingB(BYTE bLighting) { this->GetInterface()->bLightingB = bLighting; };

	float GetDepth() { return this->GetInterface()->fDepth; };
	void SetDepth(float fDepth) { this->GetInterface()->fDepth = fDepth; };

	void Destroy() { if ( this->internalInterface ) delete this->internalInterface; delete this; }
};

#endif