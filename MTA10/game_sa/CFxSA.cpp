/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CFxSA.cpp
*  PURPOSE:		Game effects handling
*  DEVELOPERS:	Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

void CFxSA::AddBlood( const CVector& vecPosition, const CVector& vecDirection, int iCount, float fBrightness )
{
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddBlood;
    _asm
    {
        mov     ecx, dwThis
        push    fBrightness
        push    iCount
        push    pvecDirection
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::AddWood( const CVector& vecPosition, const CVector& vecDirection, int iCount, float fBrightness )
{
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddWood;
    _asm
    {
        mov     ecx, dwThis
        push    fBrightness
        push    iCount
        push    pvecDirection
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::AddSparks( const CVector& vecPosition, const CVector& vecDirection, float fForce, int iCount, CVector vecAcrossLine, unsigned char ucBlurIf0, float fSpread, float fLife )
{
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    float fX = vecAcrossLine.getX(), fY = vecAcrossLine.getY(), fZ = vecAcrossLine.getZ();
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddSparks;
    _asm
    {
        mov     ecx, dwThis
        push    fLife
        push    fSpread
        push    ucBlurIf0
        push    fZ
        push    fY
        push    fX
        push    iCount
        push    fForce
        push    pvecDirection
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::AddTyreBurst( const CVector& vecPosition, const CVector& vecDirection )
{
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddTyreBurst;
    _asm
    {
        mov     ecx, dwThis
        push    pvecDirection
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::AddBulletImpact( const CVector& vecPosition, const CVector& vecDirection, int iSmokeSize, int iSparkCount, float fSmokeIntensity )
{
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddBulletImpact;
    _asm
    {
        mov     ecx, dwThis
        push    fSmokeIntensity
        push    iSparkCount
        push    iSmokeSize
        push    pvecDirection
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::AddPunchImpact( const CVector& vecPosition, const CVector& vecDirection, int i )
{
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddPunchImpact;
    _asm
    {
        mov     ecx, dwThis
        push    i
        push    pvecDirection
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::AddDebris( const CVector& vecPosition, const RwColor& rwColor, float fDebrisScale, int iCount )
{
    const CVector * pvecPosition = &vecPosition;
    const RwColor * pColor = &rwColor;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddDebris;
    _asm
    {
        mov     ecx, dwThis
        push    iCount
        push    fDebrisScale
        push    pColor
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::AddGlass( const CVector& vecPosition, const RwColor& rwColor, float fDebrisScale, int iCount )
{
    const CVector * pvecPosition = &vecPosition;
    const RwColor * pColor = &rwColor;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_AddGlass;   
    _asm
    {
        mov     ecx, dwThis
        push    iCount
        push    fDebrisScale
        push    pColor
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::TriggerWaterHydrant( const CVector& vecPosition )
{
    const CVector * pvecPosition = &vecPosition;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_TriggerWaterHydrant; 
    _asm
    {
        mov     ecx, dwThis
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::TriggerGunshot( CEntity* pEntity, const CVector& vecPosition, const CVector& vecDirection, bool bIncludeSparks )
{
    DWORD dwEntity = ( pEntity ) ? ( DWORD ) pEntity->GetInterface () : NULL;
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_TriggerGunshot;
        _asm
    {
        mov     ecx, dwThis
        push    bIncludeSparks
        push    pvecDirection
        push    pvecPosition
        push    dwEntity
        call    dwFunc
    }
}


void CFxSA::TriggerTankFire( const CVector& vecPosition, const CVector& vecDirection )
{
    const CVector * pvecPosition = &vecPosition;
    const CVector * pvecDirection = &vecDirection;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_TriggerTankFire;
    _asm
    {
        mov     ecx, dwThis
        push    pvecDirection
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::TriggerWaterSplash( const CVector& vecPosition )
{
    const CVector * pvecPosition = &vecPosition;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_TriggerWaterSplash;
    _asm
    {
        mov     ecx, dwThis
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::TriggerBulletSplash( const CVector& vecPosition )
{
    const CVector * pvecPosition = &vecPosition;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_TriggerBulletSplash;
    _asm
    {
        mov     ecx, dwThis
        push    pvecPosition
        call    dwFunc
    }
}


void CFxSA::TriggerFootSplash( const CVector& vecPosition )
{
    const CVector * pvecPosition = &vecPosition;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CFx_TriggerFootSplash;    
    _asm
    {
        mov     ecx, dwThis
        push    pvecPosition
        call    dwFunc
    }
}
