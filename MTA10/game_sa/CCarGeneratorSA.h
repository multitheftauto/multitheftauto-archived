/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CCarEnterExitSA.h
*  PURPOSE:		Header file for car generator class
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_CARGENERATOR
#define __CGAMESA_CARGENERATOR

#define WIN32_LEAN_AND_MEAN

#include <game/CCarGenerator.h>
#include <CVector.h>

#include <windows.h>

class CCarGeneratorSAInterface
{
	short VisibleModel;
	unsigned char car_remap1, car_remap2;

	short nX, nY, nZ;
	unsigned char rot;
	unsigned char ChanceOfCarAlarm;
	unsigned char ChanceOfCarLocked;
	
	unsigned char bWaitUntilFarFromPlayer:1;
	unsigned char bHighPriority:1;
	unsigned char bActive:1;
	unsigned char bPlayerHasAlreadyOwnedCar:1;
	unsigned char bIgnorePopulationLimit:1;
	
	unsigned short MinDelay;
	unsigned short MaxDelay;
	unsigned int NextGen;
	
	short LatestCarID;
	unsigned short GenerateCount;
	unsigned char m_level;
	unsigned char m_used;
};

class CCarGeneratorSA : public CCarGenerator
{
private:
	CCarGeneratorSAInterface * internalInterface;
public:
	CCarGeneratorSA(CCarGeneratorSAInterface * CarGeneratorInterface) { this->internalInterface = CarGeneratorInterface; }

	DWORD		GetModelIndex();
	void		SetModelIndex(DWORD dwModelIndex);
	CVector&	GetPosition( CVector& position );
	void		SetPosition( const CVector& position );
	BYTE		GetChanceOfCarAlarm();
	void		SetChanceOfCarAlarm(BYTE bChance);
	BYTE		GetChanceOfCarLocked();
	void		SetChanceOfCarLocked(BYTE bChance);
	bool		GetWaitUntilFarFromPlayer();
	void		SetWaitUntilFarFromPlayer(bool bWaitUntilFarFromPlayer);
	bool		IsHighPriority();
	void		SetHighPriority(bool bHighPriority);
	bool		IsActive();
	void		SetActive(bool bActive);
	bool		HasPlayerAlreadyOwnedCar();
	void		SetHasPlayerAlreadyOwnedCar(bool bAlreadyOwnedByPlayer);
	bool		GetIgnorePopulationLimit();
	void		SetIgnorePopulationLimit(bool bIgnorePopulationLimit);
	DWORD		GetMinimumDelay();
	void		SetMinimumDelay(DWORD dwMinimumDelay);
	DWORD		GetMaximumDelay();
	void		SetMaximumDelay(DWORD dwMaximumDelay);
	DWORD		GetNextGenTime();
	void		SetNextGenTime(DWORD dwNextGenTime);
};

#endif