/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CClientRopeManager.cpp
*  PURPOSE:     Rope manager class
*  DEVELOPERS:  Jax <>
*
*****************************************************************************/

#include "StdInc.h"
using namespace std;

CClientRopeManager::CClientRopeManager ( CClientManager * pManager )
{
    m_pManager = pManager;
    m_bDeleteAll = false;
}


CClientRopeManager::~CClientRopeManager ( void )
{
    m_bDeleteAll = true;
    vector < CClientRope * > ::iterator iter = m_Ropes.begin ();
    for ( ; iter != m_Ropes.end () ; iter++ ) delete *iter;
    m_bDeleteAll = false;
}


void CClientRopeManager::RemoveFromList ( CClientRope * pRope )
{
    if ( !m_bDeleteAll )
    {
        vector < CClientRope * > ::iterator iter = m_Ropes.begin ();
        for ( ; iter != m_Ropes.end () ; iter++ )
        {
             if ( *iter == pRope )
             {
                 m_Ropes.erase ( iter );
                 break;
             }
        }
    }
}


void CClientRopeManager::DoPulse ( void )
{    
    vector < CClientRope * > ::iterator iter = m_Ropes.begin ();
    for ( ; iter != m_Ropes.end () ; iter++ ) (*iter)->DoPulse ();
}


void CClientRopeManager::Render ( void )
{    
    vector < CClientRope * > ::iterator iter = m_Ropes.begin ();
    for ( ; iter != m_Ropes.end () ; iter++ ) (*iter)->Render ();
}