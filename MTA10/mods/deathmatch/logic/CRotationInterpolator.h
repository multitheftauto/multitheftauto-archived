/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/deathmatch/logic/CRotationInterpolator.h
*  PURPOSE:     Header for rotation interpolator class
*  DEVELOPERS:  Alberto Alonso <rydencillo@gmail.com>
*               
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#pragma once

#include "CInterpolator.h"

template < unsigned int uiMaxElements = 256 >
class CRotationInterpolator : public CInterpolator < CVector, uiMaxElements >
{
protected:
    bool                    Eval                ( const VecMap& Left,
                                                  const VecMap& Right,
                                                  unsigned long ulTimeEval,
                                                  CVector* output )
    {
        // Check for being the same or maybe wrap around
        if ( Left.m_ulTime >= Right.m_ulTime )
        {
            *output = Right.data;
            return true;
        }

        // Find the relative position of ulTimeEval between R.m_ulTimeStamp and L.m_ulTimeStamp
        float fAlpha = Unlerp ( Left.m_ulTime, ulTimeEval, Right.m_ulTime );

        // Lerp between Right.pos and Left.pos
        CVector vecTemp;
        float fZero = 0.0f;
        vecTemp.fX = GetOffsetDegrees ( Left.data.fX, Right.data.fX );
        vecTemp.fY = GetOffsetDegrees ( Left.data.fY, Right.data.fY );
        vecTemp.fZ = GetOffsetDegrees ( Left.data.fZ, Right.data.fZ );
        vecTemp.fX = Lerp ( fZero, fAlpha, vecTemp.fX );
        vecTemp.fY = Lerp ( fZero, fAlpha, vecTemp.fY );
        vecTemp.fZ = Lerp ( fZero, fAlpha, vecTemp.fZ );

        *output = Left.data + vecTemp;

        return true;
    }
};