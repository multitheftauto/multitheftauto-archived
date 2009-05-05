/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CRestartSA.cpp
*  PURPOSE:     Restart points
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

/**
 * Prevent the next restart from being overridden and instead use the closest police or hospital restart point
 */
void CRestartSA::CancelOverrideRestart (  )
{
	DEBUG_TRACE("void CRestartSA::CancelOverrideRestart (  )");
	*(BYTE *)VAR_OverrideNextRestart = 0;
}

/**
 * Override the next restart, so that the player restarts at a specific position instead of the nearest
 * police or hospital restart point
 * @param vecPosition CVector * containing the position to restart at
 * @param fRotation Rotation in radians to face once restarted
 */
void CRestartSA::OverrideNextRestart ( CVector * vecPosition, FLOAT fRotation )
{
	DEBUG_TRACE("void CRestartSA::OverrideNextRestart ( CVector * vecPosition, FLOAT fRotation )");
	*(BYTE *)VAR_OverrideNextRestart = 1;
	memcpy((void *)VAR_OverrideNextRestartPosition, vecPosition, sizeof(CVector));
	*(FLOAT *)VAR_OverrideNextRestartRotation = fRotation;
}

/**
 * Find the closest police restart point to a specific point
 * @param vecClosestTo CVector * containing the position you want to find the closest restart point to
 * @param vecClosestRestartPoint CVector * that returns the position of the closest restart point
 * @param fRotation FLOAT * that returns the rotation at which the restart point restarts the player
 */
void CRestartSA::FindClosestPoliceRestartPoint ( CVector * vecClosestTo, CVector * vecClosestRestartPoint, FLOAT * fRotation )
{
	DEBUG_TRACE("void CRestartSA::FindClosestPoliceRestartPoint ( CVector * vecClosestTo, CVector * vecClosestRestartPoint, FLOAT * fRotation )");
	DWORD dwFunction = FUNC_FindClosestPoliceRestartPoint;
	_asm
	{
		push	fRotation
		push	vecClosestRestartPoint
		push	vecClosestTo
		call	dwFunction
		add		esp, 0xC
	}
}

/**
 * Find the closest hospital restart point to a specific point
 * @param vecClosestTo CVector * containing the position you want to find the closest restart point to
 * @param vecClosestRestartPoint CVector * that returns the position of the closest restart point
 * @param fRotation FLOAT * that returns the rotation at which the restart point restarts the player
 */
void CRestartSA::FindClosestHospitalRestartPoint ( CVector * vecClosestTo, CVector * vecClosestRestartPoint, FLOAT * fRotation )
{
	DEBUG_TRACE("void CRestartSA::FindClosestHospitalRestartPoint ( CVector * vecClosestTo, CVector * vecClosestRestartPoint, FLOAT * fRotation )");
	DWORD dwFunction = FUNC_FindClosestHospitalRestartPoint;
	_asm
	{
		push	fRotation
		push	vecClosestRestartPoint
		push	vecClosestTo
		call	dwFunction
		add		esp, 0xC
	}
}

/**
 * Add a police restart point so that the player restarts here (if its their nearest restart point) when they've
 * been "busted".
 * @param vecPosition CVector * containing the desired position for the restart point
 * @param fRotation FLOAT containing the desired initial rotation for the player
 */
void CRestartSA::AddPoliceRestartPoint ( CVector * vecPosition, FLOAT fRotation )
{
	DEBUG_TRACE("void CRestartSA::AddPoliceRestartPoint ( CVector * vecPosition, FLOAT fRotation )");
	DWORD dwFunction = FUNC_AddPoliceRestartPoint;
	_asm
	{
		push	fRotation
		push	vecPosition
		call	dwFunction
		add		esp, 8
	}
}

/**
 * Add a hospital restart point so that the player restarts here (if its their nearest restart point) when they've
 * been "wasted".
 * @param vecPosition CVector * containing the desired position for the restart point
 * @param fRotation FLOAT containing the desired initial rotation for the player
 */
void CRestartSA::AddHospitalRestartPoint ( CVector * vecPosition, FLOAT fRotation )
{
	DEBUG_TRACE("void CRestartSA::AddHospitalRestartPoint ( CVector * vecPosition, FLOAT fRotation )");
	DWORD dwFunction = FUNC_AddHospitalRestartPoint;
	_asm
	{
		push	fRotation
		push	vecPosition
		call	dwFunction
		add		esp, 8
	}
}

/**
 * Checks if the player is in the process of respawning after being arrested
 * @return bool TRUE if they have just been arested and not yet respawned, FALSE otherwise.
 */
bool CRestartSA::IsRestartingAfterArrest  (  )
{
	DEBUG_TRACE("bool CRestartSA::IsRestartingAfterArrest  (  )");
	DWORD dwFunction = FUNC_IsRestartingAfterArrest;
	bool bReturn = false;
	_asm
	{
		call	dwFunction
		mov		bReturn, al
	}
	return bReturn;
}

/**
 * Checks if the player is in the process of respawning after dying
 * @return bool TRUE if they have just died and not yet respawned, FALSE otherwise.
 */
bool CRestartSA::IsRestartingAfterDeath (  )
{
	DEBUG_TRACE("bool CRestartSA::IsRestartingAfterDeath (  )");
	DWORD dwFunction = FUNC_IsRestartingAfterDeath;
	bool bReturn = false;
	_asm
	{
		call	dwFunction
		mov		bReturn, al
	}
	return bReturn;
}