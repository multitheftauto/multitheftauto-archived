/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CClientRopeManager.h
*  PURPOSE:     Rope manager class
*  DEVELOPERS:  Jax <>
*
*****************************************************************************/

#ifndef __CCLIENTROPEMANAGER_H
#define __CCLIENTROPEMANAGER_H

#include <vector>
class CClientRope;

class CClientRopeManager
{
    friend CClientRope;
public:
                                    CClientRopeManager      ( class CClientManager * pManager );
                                    ~CClientRopeManager     ( void );

    void                            DoPulse                 ( void );
    void                            Render                  ( void );

private:
    void                            AddToList               ( CClientRope * pRope )     { m_Ropes.push_back ( pRope ); }
    void                            RemoveFromList          ( CClientRope * pRope );     
    
    CClientManager *                m_pManager;
    std::vector < CClientRope * >   m_Ropes;
    bool                            m_bDeleteAll;
};

#endif