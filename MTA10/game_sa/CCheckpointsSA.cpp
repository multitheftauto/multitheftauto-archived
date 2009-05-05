/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		game_sa/CCheckpointsSA.cpp
*  PURPOSE:		Checkpoint entity manager
*  DEVELOPERS:	Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

// constructor
CCheckpointsSA::CCheckpointsSA()
{
	DEBUG_TRACE("CCheckpointsSA::CCheckpointsSA()");
	for(int i = 0;i< MAX_CHECKPOINTS;i++)
		this->Checkpoints[i] = new CCheckpointSA((CCheckpointSAInterface *)(ARRAY_CHECKPOINTS + i * sizeof(CCheckpointSAInterface)));
}

CCheckpointsSA::~CCheckpointsSA ( void )
{
    for ( int i = 0; i < MAX_CHECKPOINTS; i++ )
    {
        delete Checkpoints [i];
    }
}

/**
 * \todo Update default color to SA's orange instead of VC's pink
 */
CCheckpoint * CCheckpointsSA::CreateCheckpoint( DWORD Identifier, WORD wType, const CVector& vecPosition, const CVector& vecPointDir, FLOAT fSize, FLOAT fPulseFraction, RGBA Color )
{
	CCheckpoint * Checkpoint = FindFreeMarker();
	if(Checkpoint)
	{
        ((CCheckpointSA *)(Checkpoint))->SetIdentifier( Identifier );
		((CCheckpointSA *)(Checkpoint))->Activate();
		((CCheckpointSA *)(Checkpoint))->SetType( wType );
		Checkpoint->SetPosition( vecPosition );
		Checkpoint->SetPointDirection( vecPointDir );
		Checkpoint->SetSize( fSize );
		Checkpoint->SetColor( Color );
		Checkpoint->SetPulsePeriod( 1024 );
		((CCheckpointSA *)(Checkpoint))->SetPulseFraction( fPulseFraction );
		Checkpoint->SetRotateRate( 1 );

		return Checkpoint;
	}

	return NULL;
}

CCheckpoint * CCheckpointsSA::FindFreeMarker()
{
	DEBUG_TRACE("CCheckpoint * CCheckpointsSA::FindFreeMarker()");
	for(int i = 0; i<MAX_CHECKPOINTS;i++)
	{
		if(!Checkpoints[i]->IsActive()) 
			return Checkpoints[i];
	}
	return NULL;
}