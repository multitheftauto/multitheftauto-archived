/*****************************************************************************
*
*  PROJECT:		Multi Theft Auto v1.0
*  LICENSE:		See LICENSE in the top level directory
*  FILE:		sdk/CMatrix.h
*  PURPOSE:		4x3 GTA matrix class
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CMatrix_H
#define __CMatrix_H

/*
	Vector Math library for 3-D linear algebra (vector, matrix, quaternion)
	SIMD support for SSE, PowerPC (PPU) and the SPU.
	Also includes generic multi-platform scalar version. 

	Copyright (C) 2006, 2007 Sony Computer Entertainment Inc. 
	All rights reserved.
*/
#include <vectormath/cpp/vectormath_aos.h>
typedef Vectormath::Aos::Matrix3	CMatrix3;
typedef Vectormath::Aos::Matrix4	CMatrix4;

#define CMath Vectormath::Aos

#endif

#if 0

#include "CVector.h"

/**
 * Contains full positional data for a point
 */
class CMatrix
{
public:
	CVector vRoll;
	CVector vDirection;
	CVector vWas;
	CVector vPos;
};

#endif
