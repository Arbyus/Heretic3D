#pragma once

#include "MathsStructs.h"

namespace Heretic3D
{

	template <typename T>
	inline Matrix4x4<T> Translate( Matrix4x4<T> const & m, Vector3<> const& v )
	{
		Matrix4x4<T> Result( m );
		Result.c4 = m.c1 * v.x + m.c2 * v.y + m.c3 * v.z + m.c4; 
		return Result;
	} 

	template <typename T>
	inline Matrix4x4<T> Scale( Matrix4x4<T> m, Vector3<> v )
	{
		Matrix4x4<T> Result( static_cast<T>( 0 ) );
		Result.c1 = m.c1 * v.x;
		Result.c2 = m.c2 * v.y;
		Result.c3 = m.c3 * v.z;
		Result.c4 = m.c4;
		return Result;
	}

}