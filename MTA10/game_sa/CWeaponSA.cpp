/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CWeaponSA.cpp
*  PURPOSE:     Weapon class
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*               Cecill Etheredge <ijsf@gmx.net>
*               Christian Myhre Lundheim <>
*               Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

CWeaponSA::CWeaponSA ( CWeaponSAInterface * pInterface, CPed * pOwner, eWeaponSlot weaponSlot )
{
	DEBUG_TRACE("CWeaponSA::CWeaponSA( CWeaponSAInterface * weaponInterface, CPed * ped, DWORD dwSlot )");
	
    m_pInterface = pInterface;
    m_pOwner = pOwner;
	m_weaponSlot = weaponSlot;
}

void CWeaponSA::Destroy ( void )
{
    if ( !m_pOwner )
    {
        delete m_pInterface;
        delete this;
    }
}

eWeaponType	CWeaponSA::GetType ( void )
{
	DEBUG_TRACE("eWeaponType CWeaponSA::GetType(  )");
	return m_pInterface->m_eWeaponType;
};

void CWeaponSA::SetType ( eWeaponType type )
{
	DEBUG_TRACE("void CWeaponSA::SetType( eWeaponType type )");
	m_pInterface->m_eWeaponType = type;
}

eWeaponState CWeaponSA::GetState ( void )
{
	DEBUG_TRACE("eWeaponState CWeaponSA::GetState(  )");
	return m_pInterface->m_eState;
}

void CWeaponSA::SetState ( eWeaponState state )
{
	DEBUG_TRACE("void CWeaponSA::SetState ( eWeaponState state )");
	m_pInterface->m_eState = state;
}

DWORD CWeaponSA::GetAmmoInClip ( void )
{
	DEBUG_TRACE("DWORD CWeaponSA::GetAmmoInClip(  )");
	return m_pInterface->m_nAmmoInClip;
}

void CWeaponSA::SetAmmoInClip ( DWORD dwAmmoInClip )
{
	DEBUG_TRACE("void CWeaponSA::SetAmmoInClip( DWORD dwAmmoInClip )");
	m_pInterface->m_nAmmoInClip = dwAmmoInClip;
}

DWORD CWeaponSA::GetAmmoTotal ( void )
{
	DEBUG_TRACE("DWORD CWeaponSA::GetAmmoTotal(  )");
	return m_pInterface->m_nAmmoTotal;
}

void CWeaponSA::SetAmmoTotal ( DWORD dwAmmoTotal )
{
	DEBUG_TRACE("void CWeaponSA::SetAmmoTotal( DWORD dwAmmoTotal )");
	m_pInterface->m_nAmmoTotal = dwAmmoTotal;
}

CPed * CWeaponSA::GetPed ( void )
{
	DEBUG_TRACE("CPed * CWeaponSA::GetPed()");
	return m_pOwner;
}

eWeaponSlot	CWeaponSA::GetSlot ( void )
{
	DEBUG_TRACE("eWeaponSlot CWeaponSA::GetSlot()");
	return m_weaponSlot;
}

void CWeaponSA::SetAsCurrentWeapon ( void )
{
	DEBUG_TRACE("void CWeaponSA::SetAsCurrentWeapon()");
	m_pOwner->SetCurrentWeaponSlot ( m_weaponSlot );
}


void CWeaponSA::Remove ( void )
{
    DEBUG_TRACE("void CWeaponSA::Remove ()");
    DWORD dwFunc = FUNC_Shutdown;
    DWORD dwThis = (DWORD)m_pInterface;
    _asm
    {
        mov     ecx, dwThis
        call    dwFunc
    }

    // If the removed weapon was the currently active weapon, switch to empty-handed
    if ( m_pOwner->GetCurrentWeaponSlot () == m_weaponSlot )
    {
        CWeaponInfo* pInfo = pGame->GetWeaponInfo ( GetType () );
        if ( pInfo )
        {
            int iModel = pInfo->GetModel ();
            m_pOwner->RemoveWeaponModel ( iModel );
        }
        m_pOwner->SetCurrentWeaponSlot ( WEAPONSLOT_TYPE_UNARMED );
    }
}


void CWeaponSA::Initialize ( eWeaponType type, unsigned int uiAmmo, CPed * pPed )
{
    DWORD dwPedInterface = 0;
    if ( pPed ) dwPedInterface = ( DWORD ) pPed->GetInterface ();
    unsigned int uiType = ( unsigned int ) type;
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CWeapon_Initialize;
    _asm
    {
        mov     ecx, dwThis
        push    dwPedInterface
        push    uiAmmo
        push    uiType
        call    dwFunc
    }
}


void CWeaponSA::Update ( CPed * pPed )
{
    // Note: CWeapon::Update is called mainly to check for reload
    DWORD dwPedInterface = ( DWORD ) pPed->GetInterface ();
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CWeapon_Update;
    _asm
    {
        mov     ecx, dwThis
        push    dwPedInterface
        call    dwFunc
    }
}


bool CWeaponSA::Fire ( CEntity * pFiringEntity, CVector * pvecOrigin, CVector * pvecTarget, CEntity * pTargetEntity, CVector * pvec_1, CVector * pvec_2 )
{
    bool bReturn;
    DWORD dwFiringInterface = 0;
    if ( pFiringEntity ) dwFiringInterface = ( DWORD ) pFiringEntity->GetInterface ();
    DWORD dwTargetInterface = 0;
    if ( pTargetEntity ) dwTargetInterface = ( DWORD ) pTargetEntity->GetInterface ();
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CWeapon_Fire;
    _asm
    {
        mov     ecx, dwThis
        push    pvec_2
        push    pvec_1
        push    dwTargetInterface
        push    pvecTarget
        push    pvecOrigin
        push    dwFiringInterface
        call    dwFunc
        mov     bReturn, al
    }
    return bReturn;
}


void CWeaponSA::AddGunshell ( CEntity * pFiringEntity, CVector * pvecOrigin, CVector2D * pvecDirection, float fSize )
{
    DWORD dwEntityInterface = 0;
    if ( pFiringEntity ) dwEntityInterface = ( DWORD ) pFiringEntity->GetInterface ();
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CWeapon_AddGunshell;
    _asm
    {
        mov     ecx, dwThis
        push    fSize
        push    pvecDirection
        push    pvecOrigin
        push    dwEntityInterface
        call    dwFunc
    }
}


void CWeaponSA::DoBulletImpact ( CEntity * pFiringEntity, CEntity * pEntity, CVector * pvecOrigin, CVector * pvecTarget, CColPoint * pColPoint, int i_1 )
{
    DWORD dwEntityInterface = 0;
    if ( pFiringEntity ) dwEntityInterface = ( DWORD ) pFiringEntity->GetInterface ();
    DWORD dwEntityInterface_2 = 0;
    if ( pEntity ) dwEntityInterface_2 = ( DWORD ) pEntity->GetInterface ();
    DWORD dwColPointInterface = 0;
    if ( pColPoint ) dwColPointInterface = ( DWORD )  pColPoint->GetInterface ();
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CWeapon_DoBulletImpact;
    _asm
    {
        mov     ecx, dwThis
        push    i_1
        push    dwColPointInterface
        push    pvecTarget
        push    pvecOrigin
        push    dwEntityInterface_2
        push    dwEntityInterface
        call    dwFunc
    }
}


unsigned char CWeaponSA::GenerateDamageEvent ( CPed * pPed, CEntity * pResponsible, eWeaponType weaponType, int iDamagePerHit, ePedPieceTypes hitZone, int i_2 )
{
    unsigned int ucReturn;
    DWORD dwPedInterface = ( DWORD ) pPed->GetInterface ();
    DWORD dwResponsibleInterface = 0;
    if ( pResponsible ) dwResponsibleInterface = ( DWORD ) pResponsible->GetInterface ();
    DWORD dwFunc = FUNC_CWeapon_GenerateDamageEvent;
    _asm
    {
        push    i_2
        push    hitZone
        push    iDamagePerHit
        push    weaponType
        push    dwResponsibleInterface
        push    dwPedInterface
        call    dwFunc
        add     esp, 24
        mov     ucReturn, eax
    }
    return ( unsigned char ) ucReturn;
}
