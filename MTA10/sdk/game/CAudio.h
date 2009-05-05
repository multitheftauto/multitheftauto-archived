/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/game/CAudio.h
*  PURPOSE:		Game audio interface
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAME_AUDIO
#define __CGAME_AUDIO

#include <windows.h>
#include "CVehicle.h"

class CAudio
{
public:
	virtual void PlayFrontEndSound(DWORD dwSound)=0;
	virtual void PlayBeatTrack ( short iTrack )=0;
	virtual void SetEffectsMasterVolume ( BYTE bVolume )=0; // 64 = max volume
	virtual void SetMusicMasterVolume ( BYTE bVolume )=0;
	virtual void ClearMissionAudio ( int slot = 1)=0;
	virtual void PreloadMissionAudio ( unsigned short usAudioEvent, int slot = 1 )=0;
	virtual unsigned char GetMissionAudioLoadingStatus ( int slot = 1 )=0;
	virtual bool IsMissionAudioSampleFinished ( int slot = 1 )=0;
	virtual void AttachMissionAudioToPhysical ( CPhysical * physical, int slot = 1 )=0;
	virtual void SetMissionAudioPosition ( CVector * position, int slot = 1 )=0;
	virtual bool PlayLoadedMissionAudio ( int slot = 1 )=0;
    virtual void PauseAllSound ( bool bPaused )=0;
	virtual void StopRadio()=0;
    virtual void StartRadio( unsigned int station )=0;
};

#endif