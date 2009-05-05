/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CRopes.h
*  PURPOSE:		Rope entity interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CRopes_H
#define __CRopes_H

#include "Common.h"
#include <CVector.h>

class CRopes
{
public:
    virtual int     CreateRopeForSwatPed        ( const CVector & vecPosition ) = 0;
};

#endif