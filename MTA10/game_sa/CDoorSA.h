/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CDoorSA.h
*  PURPOSE:		Header file for vehicle door entity class
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_DOOR
#define __CGAMESA_DOOR

#include <game/CDoor.h>
#include <CVector.h>
#include "Common.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//006f47e0		public: float __thiscall CDoor::GetAngleOpenRatio(void)const 
#define FUNC_GetAngleOpenRatio		0x6f47e0
//006f4800		public: bool __thiscall CDoor::IsClosed(void)const 
#define FUNC_IsClosed				0x6f4800
//006f4820		public: bool __thiscall CDoor::IsFullyOpen(void)const 
#define FUNC_IsFullyOpen			0x6f4820
//006f4790		public: void __thiscall CDoor::Open(float)
#define FUNC_Open					0x6f4790

class CDoorSAInterface
{
public:
	float m_fOpenAngle;
	float m_fClosedAngle;
	// got 2 8bit vars next so might as well make this 16bit and get more flags
	short m_nDirn;
	BYTE m_nAxis;
	BYTE m_nDoorState;
	// simulation variables
	float m_fAngle;
	float m_fPrevAngle;
	float m_fAngVel;
};

/**
 * \todo Why are some of these Get and some Ret, is there a difference?
 */
class CDoorSA : public CDoor
{
private:
	CDoorSAInterface		* internalInterface;
public:
	// constructor
	CDoorSA(CDoorSAInterface * doorInterface) { internalInterface = doorInterface; };

	CDoorSAInterface	* GetInterface() { return internalInterface; };
	float			GetAngleOpenRatio ( );
	bool			IsClosed (  );
	bool			IsFullyOpen (  );
	void			Open ( float fUnknown );
	eDoorState		GetDoorState() { return (eDoorState)this->GetInterface()->m_nDoorState; };
};

#endif