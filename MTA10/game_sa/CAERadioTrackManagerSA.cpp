/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CAERadioTrackManagerSA.cpp
*  PURPOSE:		Audio entity radio track manager
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

BYTE CAERadioTrackManagerSA::GetCurrentRadioStationID()
{
    DWORD dwThis = ( DWORD ) m_pInterface;
	DWORD dwFunc = FUNC_CAERadioTrackManager_GetCurrentRadioStationID;
	BYTE bReturn = 0;
	_asm
	{
		mov		ecx, dwThis
		call	dwFunc
		mov		bReturn, al
	}

	return bReturn;
}

BYTE CAERadioTrackManagerSA::IsVehicleRadioActive()
{
    DWORD dwThis = ( DWORD ) m_pInterface;
	DWORD dwFunc = FUNC_CAERadioTrackManager_IsVehicleRadioActive;
	BYTE bReturn = 0;
	_asm
	{
		mov		ecx, dwThis
		call	dwFunc
		mov		bReturn, al
	}

	return bReturn;
}

char * CAERadioTrackManagerSA::GetRadioStationName(BYTE bStationID)
{
    DWORD dwThis = ( DWORD ) m_pInterface;
	DWORD dwFunc = FUNC_CAERadioTrackManager_GetRadioStationName;
	char * cReturn = 0;
	DWORD dwStationID = bStationID;
	_asm
	{
		mov		ecx, dwThis
		push	dwStationID
		call	dwFunc
		mov		cReturn, eax
	}

	return cReturn;
}

BOOL CAERadioTrackManagerSA::IsRadioOn()
{
    DWORD dwThis = ( DWORD ) m_pInterface;
	DWORD dwFunc = FUNC_CAERadioTrackManager_IsRadioOn;
	BYTE bReturn = 0;
	_asm
	{
		mov		ecx, dwThis
		call	dwFunc
		mov		bReturn, al
	}

	return bReturn;
}

void CAERadioTrackManagerSA::SetBassSetting(DWORD dwBass)
{
    DWORD dwThis = ( DWORD ) m_pInterface;
	DWORD dwFunc = FUNC_CAERadioTrackManager_SetBassSetting;
	_asm
	{
		mov		ecx, dwThis
		push	0x3F800000 // 1.0f
		push	dwBass
		call	dwFunc
	}
}

void CAERadioTrackManagerSA::Reset()
{
    DWORD dwThis = ( DWORD ) m_pInterface;
	DWORD dwFunc = FUNC_CAERadioTrackManager_Reset;
	_asm
	{
		mov		ecx, dwThis
		call	dwFunc
	}
}

void CAERadioTrackManagerSA::StartRadio(BYTE bStationID, BYTE bUnknown)
{
    DWORD dwThis = ( DWORD ) m_pInterface;
	DWORD dwFunc = FUNC_CAERadioTrackManager_StartRadio;
	DWORD dwStationID = bStationID;
	DWORD dwUnknown = bUnknown;
	_asm
	{
		mov		ecx, dwThis
		push	0
		push	0
		push	dwUnknown
		push	dwStationID
		call	dwFunc
	}
}
