/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CUtils.h
*  PURPOSE:     Util functions header
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*               Christian Myhre Lundheim <>
*               Jax <>
*               Kevin Whiteside <kevuwk@gmail.com>
*               Derek Abdine <>
*               Chris McArthur <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*****************************************************************************/

#ifndef __UTILS_H
#define __UTILS_H

#include "CClientCommon.h"

#ifndef PI
#define PI 3.14159265358979323846264338327950f
#endif

const char* GetFilenameFromPath( const char* szPath );

// Vector math
inline float DistanceBetweenPoints2D( const CVector& vecPosition1, const CVector& vecPosition2 )
{
	CPoint a( vecPosition1 ), b( vecPosition2 );
	a.setZ( 0 ); b.setZ( 0 );						// ignore Z dimension
	return CMath::dist( a, b );
}

inline float DistanceBetweenPoints3D( const CVector& vecPosition1, const CVector& vecPosition2 )
{
	return CMath::dist( CPoint( vecPosition1 ), CPoint( vecPosition2 ) );
}

inline bool IsPointNearPoint2D( const CVector& vecPosition1, const CVector& vecPosition2, float fDistance )
{
	float fDistanceX = vecPosition2.getX() - vecPosition1.getX();
	float fDistanceY = vecPosition2.getY() - vecPosition1.getY();

	return ( fDistanceX * fDistanceX + fDistanceY * fDistanceY <= fDistance * fDistance );
}

inline bool IsPointNearPoint3D( const CVector& vecPosition1, const CVector& vecPosition2, float fDistance )
{
	CVector vecDist = vecPosition2 - vecPosition1;
	return ( CMath::dot( vecDist, vecDist ) <= fDistance * fDistance );
}

inline float WrapAround( float fValue, float fHigh )
{
    return fValue - ( fHigh * floor ( static_cast < float > ( fValue / fHigh ) ) );
}

// Radians to degrees and vice versa
inline float ConvertRadiansToDegrees( float fEuler, bool bWrap = true )
{
    return ( bWrap )
		? WrapAround( static_cast < float > ( fEuler * 180.0f / PI + 360.0f ), 360.0f )
		: static_cast < float > ( fEuler * 180.0f / PI );
}

inline float ConvertDegreesToRadians( float fEuler, bool bWrap = true )
{
    return ( bWrap )
		? WrapAround ( static_cast < float > ( fEuler * PI / 180.0f + 2*PI ), static_cast < float > ( 2*PI ) )
		: static_cast < float > ( fEuler * PI / 180.0f );
}

inline CVector Extrapolate( const CVector& vecOld, const CVector& vecSpeed, long ul_delta_t )
{
    float fDelta_t = static_cast < float >( ul_delta_t );
	return vecOld + ( vecSpeed * fDelta_t );
}

inline CVector GetExtrapolatedSpeed( const CVector &vecOne, unsigned long ul_time_1, const CVector &vecTwo, unsigned long ul_time_2 )
{
    float dt = ul_time_2 - ul_time_1;
	return ( vecTwo - vecOne ) / dt;
}

inline float GetOffsetDegrees( float a, float b )
{
    float c = ( b > a ) ? b - a : 0.0f - ( a - b );
    if ( c > 180.0f )
        c = 0.0f - ( 360.0f - c );
    else if ( c <= -180.0f )
        c = ( 360.0f + c );
    return c;
}

bool            DoesFileExist( const char* szFilename );

// Misc utility functions
char*           ReplaceAnyStringOccurrence( char* szBuffer, const char* szWhat, const char* szWith, size_t sizeMax );
unsigned int    StripUnwantedCharacters( char* szText, unsigned char cReplace = ' ' );
bool            IsWantedCharacter( unsigned char c );
bool			IsValidFilePath( const char* szDir );

void            RaiseFatalError( unsigned int uiCode );
void            RaiseProtocolError( unsigned int uiCode );

void            RotateVector( CVector& vecLine, const CVector& vecRotation );

unsigned int    GetRandom( unsigned int uiLow, unsigned int uiHigh );
double          GetRandomDouble( void );
float           GetRandomFloat( void );

unsigned int    HashString( const char* szString );

SString         GetDataUnit( unsigned int uiInput );

unsigned int    HexToInt( const char* szHex );
bool            XMLColorToInt( const char* szColor, unsigned long& ulColor );
bool            XMLColorToInt( const char* szColor, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue, unsigned char& ucAlpha );

// Utility network functions
void            LongToDottedIP( unsigned long ulIP, char* szDottedIP );

bool            BitStreamReadUsString( class NetBitStreamInterface& bitStream, SString& strOut );

void            MakeSureDirExists( const char* szPath );

// Debugging purposes
#ifdef MTA_DEBUG
HMODULE RemoteLoadLibrary(HANDLE hProcess, const char* szLibPath);
#endif

#endif
