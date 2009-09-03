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
#include <list>

CClientRope::CClientRope ( CClientManager * pManager, unsigned int links, float fLinkDistance ) : CClientEntity ( INVALID_ELEMENT_ID )
{
    m_pManager = pManager;
    m_uiLinks = links;
    m_fLinkDistance = fLinkDistance;
    m_pFirstLink = m_pLastLink = NULL;

    for ( unsigned int i = 0 ; i < links ; i++ ) AddLink ();

    m_pManager->GetRopeManager ()->AddToList ( this );
}


CClientRope::~CClientRope ( void )
{    
    RemoveLinks ();
    m_pManager->GetRopeManager ()->RemoveFromList ( this );
}


void CClientRope::Unlink ( void )
{
}


void CClientRope::DoPulse ( void )
{
    DoAttaching ();
    DoPhysics ();

    CMatrix attachMatrix;
    if ( m_pAttachedToEntity ) m_pAttachedToEntity->GetMatrix ( attachMatrix );
    GetEndPosition ( attachMatrix.vPos );

    std::list < CClientEntity * > ::const_iterator iter = AttachedEntitiesBegin ();
    for ( ; iter != AttachedEntitiesEnd () ; iter++ )
    {
        (*iter)->SetMatrix ( attachMatrix );
    }
}


void CClientRope::Render ( void )
{
    if ( false )
    {
        float boxSize = 0.1f;
        CVector * pvecPos;
        CClientRopeLink * pLink = m_pFirstLink;
        while ( pLink )
        {
            pvecPos = &pLink->vecPosition;
            g_pCore->GetGraphics ()->Draw3DBox ( pvecPos->fX, pvecPos->fY, pvecPos->fZ, boxSize, boxSize, boxSize, 0xFFFFFF00, false );
            pLink = pLink->pNextLink;
        }
    }
    else
    {
        CVector * pvecBegin = NULL, * pvecEnd = NULL;
        CClientRopeLink * pLink = m_pFirstLink;
        while ( pLink )
        {
            if ( !pvecBegin ) pvecBegin = &pLink->vecPosition;
            else if ( !pvecEnd ) pvecEnd = &pLink->vecPosition;

            if ( pvecBegin && pvecEnd )
            {
                g_pCore->GetGraphics ()->DrawLine3D ( *pvecBegin, *pvecEnd, 0xFFFF0000, 5 );
                pvecBegin = pvecEnd;
                pvecEnd = NULL;
            }
            pLink = pLink->pNextLink;
        }
    }
}


void CClientRope::DoPhysics ( void )
{
    if ( m_pFirstLink )
    {
        m_pFirstLink->vecSpeed += m_vecConstantForce;
        m_pFirstLink->vecPosition += m_pFirstLink->vecSpeed;
        CVector vecPosition = m_pFirstLink->vecPosition, vecDirection, vecWantedPosition;

        CClientRopeLink * pLink = m_pFirstLink->pNextLink;
        while ( pLink )
        {
            pLink->vecSpeed += m_vecConstantForce;
            vecWantedPosition = pLink->vecPosition + pLink->vecSpeed;
            if ( DistanceBetweenPoints3D ( vecPosition, vecWantedPosition ) > m_fLinkDistance )
            {
                vecDirection = vecWantedPosition - vecPosition;
                vecDirection.Normalize ();
                vecDirection *= m_fLinkDistance;
                vecPosition += vecDirection;
            }
            else vecPosition = vecWantedPosition;

            pLink->vecPosition = vecPosition;
            pLink = pLink->pNextLink;
        }
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
        pLink->pPreviousLink = m_pLastLink;
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


void CClientRope::DragEndTo ( CVector vecPosition )
{
    if ( m_pFirstLink )
    {
        CVector vecDirection;

        m_pLastLink->vecPosition = vecPosition;
        CClientRopeLink * pLink = m_pLastLink->pPreviousLink;
        while ( pLink )
        {
            if ( DistanceBetweenPoints3D ( pLink->vecPosition, vecPosition ) <= m_fLinkDistance ) break;

            vecDirection = vecPosition - pLink->vecPosition;
            vecDirection.Normalize ();
            vecDirection *= m_fLinkDistance;
            vecPosition -= vecDirection;
            pLink->vecPosition = vecPosition;
            pLink = pLink->pPreviousLink;
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


void CClientRope::ApplyForce ( CVector & vecDirection )
{
    CClientRopeLink * pLink = m_pFirstLink;
    while ( pLink )
    {       
        pLink->vecSpeed += vecDirection;
        pLink = pLink->pNextLink;
    }
}


void CClientRope::ApplyConstantForce ( CVector & vecDirection )
{
    m_vecConstantForce += vecDirection;
}


void CClientRope::ApplyLinkForce ( unsigned int link, CVector & vecDirection )
{
    CClientRopeLink * pLink = GetLink ( link );
    if ( pLink ) pLink->vecSpeed += vecDirection;
}


void CClientRope::GetLinkSpeed ( unsigned int link, CVector & vecSpeed )
{
    CClientRopeLink * pLink = GetLink ( link );
    if ( pLink ) vecSpeed = pLink->vecSpeed;
    else vecSpeed = CVector ();
}


void CClientRope::SetLinkSpeed ( unsigned int link, CVector & vecSpeed )
{
    CClientRopeLink * pLink = GetLink ( link );
    if ( pLink ) pLink->vecSpeed = vecSpeed;
}


CClientRopeLink * CClientRope::GetLink ( unsigned int link )
{
    CClientRopeLink * pLink = NULL;
    if ( link < m_uiLinks )
    {
        pLink = m_pFirstLink;
        for ( unsigned int i = 0 ; i < link ; i++ ) pLink = pLink->pNextLink;
    }
    return pLink;
}