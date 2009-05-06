/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/CVector.h
*  PURPOSE:		3D vector math wrapper
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CVector_H
#define __CVector_H

/*
	Vector Math library for 3-D linear algebra (vector, matrix, quaternion)
	SIMD support for SSE, PowerPC (PPU) and the SPU.
	Also includes generic multi-platform scalar version. 

	Copyright (C) 2006, 2007 Sony Computer Entertainment Inc. 
	All rights reserved.
*/
#include <vectormath/cpp/vectormath_aos.h>
typedef Vectormath::Aos::Vector3	CVector3;
typedef Vectormath::Aos::Vector4	CVector4;
typedef Vectormath::Aos::Point3		CPoint;

typedef CVector3 CVector;

/*
	Internal 3D vector wrapper

	Unaligned 12-byte vector representation used for storage purposes. Do
	not use outside of the game layer.
*/

class CVectorGTA {
	float	m_fX;
	float	m_fY;
	float	m_fZ;

public:
	inline CVectorGTA( void ) : m_fX( 0 ), m_fY( 0 ), m_fZ( 0 ) {};

	/*
	inline CVector( const CVector& vector ) {
		m_fX = vector.m_fX;
		m_fY = vector.m_fY;
		m_fZ = vector.m_fZ;
	}
	*/

	inline CVectorGTA( const CVector3& vector ) {
		m_fX = vector.getX();
		m_fY = vector.getY();
		m_fZ = vector.getZ();
	}

	inline const CVectorGTA& operator =( const CVector3& vector ) {
		m_fX = vector.getX();
		m_fY = vector.getY();
		m_fZ = vector.getZ();
		return *this;
	}

	static CVector3 unwrap( const CVectorGTA& vector ) {
		return CVector3( vector.m_fX, vector.m_fY, vector.m_fZ );
	}
};

#endif

#if 0

#ifdef WIN32
#include <windows.h>
#endif

#include <math.h>

#define FLOAT_EPSILON 0.0001f

/**
 * CVector Structure used to store a 3D vertex.
 */
class CVector
{
public:
	FLOAT fX, fY, fZ;
	
	CVector()
	{
		this->fX = 0;
		this->fY = 0;
		this->fZ = 0;
	};
	// contructor
	CVector(FLOAT fX, FLOAT fY, FLOAT fZ) 
	{ 
		this->fX = fX;
		this->fY = fY;
		this->fZ = fZ;
	}

    float Normalize ( void ) 
    { 
        double t = sqrt(fX*fX + fY*fY + fZ*fZ);
        if ( t > 0 )
        {
            double fX2 = fX / t;
            double fY2 = fY / t;
            double fZ2 = fZ / t;
            fX = (float)fX2;
            fY = (float)fY2;
            fZ = (float)fZ2;
        }
        return static_cast < float > ( t );
    }

	float Length ( void ) const
	{
		return sqrt((fX*fX) + (fY*fY) + (fZ*fZ));
	}

    float DotProduct ( CVector * param ) const
    {
        return fX*param->fX + fY*param->fY + fZ*param->fZ;
    }

    void CrossProduct ( CVector * param ) 
    { 
        float _fX = fX, _fY = fY, _fZ = fZ;
        fX = _fY * param->fZ - param->fY * _fZ;
        fY = _fZ * param->fX - param->fZ * _fX;
        fZ = _fX * param->fY - param->fX * _fY;
    }

    CVector operator + ( const CVector& vecRight ) const
    {
        return CVector ( fX + vecRight.fX, fY + vecRight.fY, fZ + vecRight.fZ );
    }

    CVector operator - ( const CVector& vecRight ) const
    {
        return CVector ( fX - vecRight.fX, fY - vecRight.fY, fZ - vecRight.fZ );
    }

    CVector operator * ( const CVector& vecRight ) const
    {
        return CVector ( fX * vecRight.fX, fY * vecRight.fY, fZ * vecRight.fZ );
    }

    CVector operator * ( float fRight ) const
    {
        return CVector ( fX * fRight, fY * fRight, fZ * fRight );
    }

    CVector operator / ( const CVector& vecRight ) const
    {
        return CVector ( fX / vecRight.fX, fY / vecRight.fY, fZ / vecRight.fZ );
    }

    void operator += ( float fRight )
    {
        fX += fRight;
        fY += fRight;
        fZ += fRight;
    }

    void operator += ( const CVector& vecRight )
    {
        fX += vecRight.fX;
        fY += vecRight.fY;
        fZ += vecRight.fZ;
    }

    void operator -= ( float fRight )
    {
        fX -= fRight;
        fY -= fRight;
        fZ -= fRight;
    }

    void operator -= ( const CVector& vecRight )
    {
        fX -= vecRight.fX;
        fY -= vecRight.fY;
        fZ -= vecRight.fZ;
    }

    void operator *= ( float fRight )
    {
        fX *= fRight;
        fY *= fRight;
        fZ *= fRight;
    }

    void operator *= ( const CVector& vecRight )
    {
        fX *= vecRight.fX;
        fY *= vecRight.fY;
        fZ *= vecRight.fZ;
    }

    void operator /= ( float fRight )
    {
        fX /= fRight;
        fY /= fRight;
        fZ /= fRight;
    }

    void operator /= ( const CVector& vecRight )
    {
        fX /= vecRight.fX;
        fY /= vecRight.fY;
        fZ /= vecRight.fZ;
    }

    bool operator== ( const CVector& param ) const
    {
        return ( ( abs ( fX - param.fX ) < FLOAT_EPSILON ) ||
                 ( abs ( fY - param.fY ) < FLOAT_EPSILON ) ||
                 ( abs ( fZ - param.fZ ) < FLOAT_EPSILON ) );
    }

    bool operator!= ( const CVector& param ) const
    {
        return ( ( abs ( fX - param.fX ) >= FLOAT_EPSILON ) ||
                 ( abs ( fY - param.fY ) >= FLOAT_EPSILON ) ||
                 ( abs ( fZ - param.fZ ) >= FLOAT_EPSILON ) );
    }
};

#endif
