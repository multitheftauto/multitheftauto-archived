/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CClientRope.cpp
*  PURPOSE:     Rope class
*  DEVELOPERS:  Jax <>
*
*****************************************************************************/

#include "StdInc.h"

CClientRope::CClientRope ( unsigned int links, float fLinkDistance ) : CClientEntity ( INVALID_ELEMENT_ID )
{
    m_uiLinks = links;
    m_fLinkDistance = fLinkDistance;
    m_pFirstLink = m_pLastLink = NULL;

    for ( unsigned int i = 0 ; i < links ; i++ ) AddLink ();
}


CClientRope::~CClientRope ( void )
{
    RemoveLinks ();
}


void CClientRope::Unlink ( void )
{
}


void CClientRope::DoPulse ( void )
{
    DoAttaching ();
}


void CClientRope::Render ( void )
{
    /*
    float boxSize = 0.1f;
    CVector * pvecPos;
    CClientRopeLink * pLink = m_pFirstLink;
    while ( pLink )
    {
        pvecPos = &pLink->vecPosition;
        g_pCore->GetGraphics ()->Draw3DBox ( pvecPos->fX, pvecPos->fY, pvecPos->fZ, boxSize, boxSize, boxSize, 0xFFFFFF00, false );
        pLink = pLink->pNextLink;
    }*/

    CVector * pvecBegin = NULL, * pvecEnd = NULL;
    CClientRopeLink * pLink = m_pFirstLink;
    while ( pLink )
    {
        if ( !pvecBegin ) pvecBegin = &pLink->vecPosition;
        else if ( !pvecEnd ) pvecEnd = &pLink->vecPosition;

        if ( pvecBegin && pvecEnd )
        {
            g_pCore->GetGraphics ()->DrawLine3D ( *pvecBegin, *pvecEnd, 0xFFFFFF00, 3 );
            pvecBegin = pvecEnd;
            pvecEnd = NULL;
        }
        pLink = pLink->pNextLink;
    }
}


void CClientRope::GetPosition ( CVector & vecPosition ) const
{
    if ( m_pFirstLink ) vecPosition = m_pFirstLink->vecPosition;
    else vecPosition = CVector ();
}


void CClientRope::GetEndPosition ( CVector & vecPosition ) const
{
    if ( m_pLastLink ) vecPosition = m_pLastLink->vecPosition;
    else vecPosition = CVector ();
}


void CClientRope::SetPosition ( const CVector & vecPosition )
{
    DragTo ( vecPosition );
}


void CClientRope::AddLink ( void )
{
    CClientRopeLink * pLink = new CClientRopeLink;
    if ( m_pLastLink )
    {
        pLink->vecPosition = m_pLastLink->vecPosition;
        m_pLastLink->pNextLink = pLink;
    }
    else m_pFirstLink = pLink;
    m_pLastLink = pLink;
}


void CClientRope::RemoveLinks ( void )
{
    CClientRopeLink * pLink = m_pFirstLink, * pNext;
    while ( pLink )
    {
        pNext = pLink->pNextLink;
        delete pLink;
        pLink = pNext;
    }
    m_pFirstLink = m_pLastLink = NULL;
}


void CClientRope::Drag ( CVector & vecDirection )
{
    if ( m_pFirstLink )
    {
        CVector vecPosition = m_pFirstLink->vecPosition + vecDirection;
        DragTo ( vecPosition );
    }
}


void CClientRope::DragTo ( CVector vecPosition )
{
    if ( m_pFirstLink )
    {
        CVector vecDirection;

        m_pFirstLink->vecPosition = vecPosition;
        CClientRopeLink * pLink = m_pFirstLink->pNextLink;
        while ( pLink )
        {
            if ( DistanceBetweenPoints3D ( pLink->vecPosition, vecPosition ) <= m_fLinkDistance ) break;

            vecDirection = vecPosition - pLink->vecPosition;
            vecDirection.Normalize ();
            vecDirection *= m_fLinkDistance;
            vecPosition -= vecDirection;
            pLink->vecPosition = vecPosition;
            pLink = pLink->pNextLink;
        }
    }
}


void CClientRope::Stretch ( CVector & vecDirection )
{
    if ( m_uiLinks >= 2 )
    {
        vecDirection.Normalize ();
        vecDirection *= m_fLinkDistance;

        CVector vecPosition = m_pFirstLink->vecPosition;
        CClientRopeLink * pLink = m_pFirstLink->pNextLink;
        while ( pLink )
        {
            vecPosition += vecDirection;
            pLink->vecPosition = vecPosition;
            pLink = pLink->pNextLink;
        }
    }
}