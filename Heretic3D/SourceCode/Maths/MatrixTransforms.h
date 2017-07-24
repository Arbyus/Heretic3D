#pragma once

#include "MathsStructs.h"

namespace Heretic3D
{

	template <typename T>
	inline Matrix4x4<T> Translate( Matrix4x4<T> const & m, Vector3 const& v )
	{
		Matrix4x4<T> Result( m );

		Result.r4 =
			( m.r1 * v.x ) +
			( m.r2 * v.y ) +
			( m.r3 * v.z ) +
			m.r4;
		return Result;
	}

	template <typename T>
	inline Matrix4x4<T> Scale( Matrix4x4<T> m, Vector3 v )
	{
		Matrix4x4<T> Result( 0 );
		Result.r1 = m.r1 * v.x;
		Result.r2 = m.r2 * v.y;
		Result.r3 = m.r3 * v.z;
		Result.r4 = m.r4;
		return Result;
	}

}