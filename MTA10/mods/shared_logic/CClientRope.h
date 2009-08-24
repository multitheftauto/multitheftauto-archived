/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CClientRope.h
*  PURPOSE:     Rope class
*  DEVELOPERS:  Jax <>
*
*****************************************************************************/

#ifndef __CCLIENTROPE_H
#define __CCLIENTROPE_H

#include "CClientEntity.h"

class CClientRopeLink
{
public:
                            CClientRopeLink     ( void )    { pNextLink = NULL; }

    CClientRopeLink *       pNextLink;
    CVector                 vecPosition;
};

class CClientRope : public CClientEntity
{
public:
                            CClientRope     ( unsigned int links, float fLinkDistance );
                            ~CClientRope    ( void );

    eClientEntityType       GetType         ( void ) const      { return CCLIENTROPE; }
    void                    Unlink          ( void );

    void                    DoPulse         ( void );
    void                    Render          ( void );

    void                    GetPosition     ( CVector & vecPosition ) const;
    void                    GetEndPosition  ( CVector & vecPosition ) const;
    void                    SetPosition     ( const CVector & vecPosition );    

    void                    AddLink         ( void );
    void                    RemoveLinks     ( void );

    void                    Drag            ( CVector & vecDirection );
    void                    DragTo          ( CVector vecPosition );
    void                    Stretch         ( CVector & vecDirection );

private:
    unsigned int            m_uiLinks;
    float                   m_fLinkDistance;
    CClientRopeLink *       m_pFirstLink;
    CClientRopeLink *       m_pLastLink;
};

#endif