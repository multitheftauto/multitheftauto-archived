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

class CClientManager;

class CClientRopeLink
{
public:
                            CClientRopeLink     ( void )    { pNextLink = pPreviousLink = NULL; }

    CClientRopeLink         * pNextLink, *pPreviousLink;
    CVector                 vecPosition, vecSpeed;
};

class CClientRope : public CClientEntity
{
public:
                            CClientRope         ( CClientManager * pManager, unsigned int links, float fLinkDistance );
                            ~CClientRope        ( void );

    eClientEntityType       GetType             ( void ) const      { return CCLIENTROPE; }
    void                    Unlink              ( void );

    unsigned int            GetLinks            ( void )            { return m_uiLinks; }

    void                    DoPulse             ( void );
    void                    Render              ( void );
    void                    DoPhysics           ( void );

    void                    GetPosition         ( CVector & vecPosition ) const;
    void                    GetEndPosition      ( CVector & vecPosition ) const;
    void                    SetPosition         ( const CVector & vecPosition );

    void                    AddLink             ( void );
    void                    RemoveLinks         ( void );

    void                    Drag                ( CVector & vecDirection );
    void                    DragTo              ( CVector vecPosition );
    void                    DragEndTo           ( CVector vecPosition );
    void                    Stretch             ( CVector & vecDirection );

    void                    ApplyForce          ( CVector & vecDirection );
    void                    ApplyConstantForce  ( CVector & vecDirection );
    void                    ApplyLinkForce      ( unsigned int link, CVector & vecDirection );

    void                    GetLinkSpeed        ( unsigned int link, CVector & vecSpeed );
    void                    SetLinkSpeed        ( unsigned int link, CVector & vecSpeed );

private:
    CClientRopeLink *       GetLink             ( unsigned int link );

    unsigned int            m_uiLinks;
    float                   m_fLinkDistance;
    CClientRopeLink *       m_pFirstLink;
    CClientRopeLink *       m_pLastLink;
    CPhysical *             m_pPhysical;
    CVector                 m_vecConstantForce;
};

#endif