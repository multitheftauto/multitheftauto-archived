/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CWaterManager.h
*  PURPOSE:		Water interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CWATERMANAGER_H
#define __CWATERMANAGER_H

#include "CWater.h"

class CWaterManager
{
public:
    virtual CWaterPoly*		GetPolyAtPoint( const CVector& vecPosition ) = 0;
    virtual CWaterPoly*		CreateQuad( const CVector& vecBL, const CVector& vecBR, const CVector& vecTL, const CVector& vecTR, bool bShallow = false ) = 0;
    virtual CWaterPoly*		CreateTriangle( const CVector& vec1, const CVector& vec2, const CVector& vec3, bool bShallow = false ) = 0;
    virtual bool			DeletePoly( CWaterPoly* pPoly ) = 0;

    virtual bool			GetWaterLevel( CVector& vecPosition, float* pfLevel, bool bCheckWaves, CVector* pvecUnknown ) = 0;
    virtual bool			SetWaterLevel( CVector* pvecPosition, float fLevel, void* pChangeSource = NULL ) = 0;
    virtual bool			SetWaterLevel( CWaterPoly* pPoly, float fLevel, void* pChangeSource = NULL ) = 0;
    virtual float			GetWaveLevel( void ) = 0;
    virtual void			SetWaveLevel( float fWaveLevel ) = 0;

    virtual bool			TestLineAgainstWater( const CVector& vecStart, const CVector& vecEnd, CVector& vecCollision ) = 0;

    virtual void			UndoChanges( void* pChangeSource = NULL ) = 0;
							// Call this after moving a polygon's vertices
    virtual void			RebuildIndex( void ) = 0;
							// Reset all water to SA default
    virtual void			Reset( void ) = 0;
};

#endif