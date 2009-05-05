/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CPadSA.cpp
*  PURPOSE:     Controller pad input logic
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

CControllerState * CPadSA::GetCurrentControllerState(CControllerState * ControllerState)
{
	DEBUG_TRACE("CControllerState * CPadSA::GetCurrentControllerState(CControllerState * ControllerState)");
	memcpy(ControllerState, &this->internalInterface->NewState, sizeof(CControllerState));
	return ControllerState;
}

CControllerState * CPadSA::GetLastControllerState(CControllerState * ControllerState)
{
	DEBUG_TRACE("CControllerState * CPadSA::GetLastControllerState(CControllerState * ControllerState)");
	memcpy(ControllerState, &this->internalInterface->OldState, sizeof(CControllerState));
	return ControllerState;
}

void CPadSA::SetCurrentControllerState(CControllerState * ControllerState)
{
	DEBUG_TRACE("void CPadSA::SetCurrentControllerState(CControllerState * ControllerState)");
	memcpy(&this->internalInterface->NewState, ControllerState, sizeof(CControllerState));
}

void CPadSA::SetLastControllerState(CControllerState * ControllerState)
{
	DEBUG_TRACE("void CPadSA::SetLastControllerState(CControllerState * ControllerState)");
	memcpy(&this->internalInterface->OldState, ControllerState, sizeof(CControllerState));
}

void CPadSA::Store()
{
	DEBUG_TRACE("void CPadSA::Store()");
	memcpy(&this->StoredPad, this->internalInterface, sizeof(CPadSAInterface));
}

void CPadSA::Restore()
{
	DEBUG_TRACE("void CPadSA::Restore()");
	memcpy(this->internalInterface, &this->StoredPad, sizeof(CPadSAInterface));
}

bool CPadSA::IsEnabled ( void )
{
    bool bEnabled = *(BYTE *)FUNC_CPad_UpdatePads == 0x56;
    return bEnabled;
}

void CPadSA::Disable( bool bDisable )
{
	if ( bDisable )
		*(BYTE *)FUNC_CPad_UpdatePads = 0xC3;
	else
		*(BYTE *)FUNC_CPad_UpdatePads = 0x56;

	//this->internalInterface->DisablePlayerControls = bDisable;
}

void CPadSA::Clear ( void )
{
	CControllerState cs; // create a null controller (class is inited to null)
	SetCurrentControllerState ( &cs );
	SetLastControllerState ( &cs );
}

void CPadSA::SetHornHistoryValue( bool value )
{
    internalInterface->iCurrHornHistory++;
    if ( internalInterface->iCurrHornHistory >= MAX_HORN_HISTORY )
        internalInterface->iCurrHornHistory = 0;
    internalInterface->bHornHistory[internalInterface->iCurrHornHistory] = value;
}

long CPadSA::GetAverageWeapon ( void )
{
    return internalInterface->AverageWeapon;
}

void CPadSA::SetLastTimeTouched ( DWORD dwTime )
{
    internalInterface->LastTimeTouched = dwTime;
}