/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CFx.h
*  PURPOSE:		Game effects interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CFX
#define __CFX

#include "RenderWare.h"

class CEntity;
class CVehicle;

class CFx
{
public:
    virtual void                AddBlood                ( const CVector& vecPosition, const CVector& vecDirection, int iCount, float fBrightness ) = 0;
    virtual void                AddWood                 ( const CVector& vecPosition, const CVector& vecDirection, int iCount, float fBrightness ) = 0;
    virtual void                AddSparks               ( const CVector& vecPosition, const CVector& vecDirection, float fForce, int iCount, CVector vecAcrossLine, unsigned char ucBlurIf0, float fSpread, float fLife ) = 0;
    virtual void                AddTyreBurst            ( const CVector& vecPosition, const CVector& vecDirection ) = 0;
    virtual void                AddBulletImpact         ( const CVector& vecPosition, const CVector& vecDirection, int iSmokeSize, int iSparkCount, float fSmokeIntensity ) = 0;
    virtual void                AddPunchImpact          ( const CVector& vecPosition, const CVector& vecDirection, int i ) = 0;
    virtual void                AddDebris               ( const CVector& vecPosition, const RwColor& rwColor, float fScale, int iCount ) = 0;
    virtual void                AddGlass                ( const CVector& vecPosition, const RwColor& rwColor, float fScale, int iCount ) = 0;
    virtual void                TriggerWaterHydrant     ( const CVector& vecPosition ) = 0;
    virtual void                TriggerGunshot          ( CEntity * pEntity, const CVector& vecPosition, const CVector& vecDirection, bool bIncludeSparks ) = 0;
    virtual void                TriggerTankFire         ( const CVector& vecPosition, const CVector& vecDirection ) = 0;
    virtual void                TriggerWaterSplash      ( const CVector& vecPosition ) = 0;
    virtual void                TriggerBulletSplash     ( const CVector& vecPosition ) = 0;
    virtual void                TriggerFootSplash       ( const CVector& vecPosition ) = 0;
};

#endif