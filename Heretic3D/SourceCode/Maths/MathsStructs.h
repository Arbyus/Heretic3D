#pragma once

namespace Heretic3D
{
	template <typename numType = float>
	struct Vector4
	{
		Vector4( numType p_x, numType p_y, numType p_z, numType p_w )
			: x( p_x )
			, y( p_y )
			, z( p_z )
			, w( p_w )
		{
		}

		Vector4( )
			: x( 0 )
			, y( 0 )
			, z( 0 )
			, w( 0 )
		{
		}

		numType x;
		numType y;
		numType z;
		numType w;


		const Vector4<numType> operator*( const numType& rhs ) const
		{
			Vector4<numType> returnVal;

			returnVal.x = ( this->x * rhs );
			returnVal.y = ( this->y * rhs );
			returnVal.z = ( this->z * rhs );
			returnVal.w = ( this->w * rhs );
			return returnVal;
		}

		Vector4<numType> operator+( const Vector4<numType>& rhs ) const
		{
			Vector4<numType> returnVal;

			returnVal.x = this->x + rhs.x;
			returnVal.y = this->y + rhs.y;
			returnVal.z = this->z + rhs.z;
			returnVal.w = this->w + rhs.w;
			return returnVal;
		}

	};

	template <typename numType=float>
	struct Vector3
	{
		Vector3( numType p_x, numType p_y, numType p_z )
			: x( p_x )
			, y( p_y )
			, z( p_z )
		{
		}

		Vector3( )
			: x( 0 )
			, y( 0 )
			, z( 0 )
		{
		}

		numType x;
		numType y;
		numType z;

		Vector3& operator*( float&& other )
		{
			this->x *= other;
			this->y *= other;
			this->z *= other;
			return *this;
		}

	};


	template <typename numType = float>
	struct Vector2
	{
		Vector2( numType p_x, numType p_y )
			: x( p_x )
			, y( p_y )
		{
		}

		Vector2( )
			: x( 0 )
			, y( 0 )
		{
		}

		numType x;
		numType y;
	};

	template <typename numType = float>
	struct Matrix3x3
	{
		Matrix3x3( Vector3<numType> col1, Vector3<numType> col2, Vector3<numType> col3 )
			: c1( col1 )
			, c2( col2 )
			, c3( col3 )
		{
		}

		Matrix3x3( )
			: c1( { 0,0,0 } )
			, c2( { 0,0,0 } )
			, c3( { 0,0,0 } )
		{
		}

		Vector3<numType> c1;
		Vector3<numType> c2;
		Vector3<numType> c3;
	};

	template <typename numType = float>
	struct Matrix4x4
	{
		Matrix4x4( Vector4<numType> col1, Vector4<numType> col2, Vector4<numType> col3, Vector4<numType> col4 )
			: c1( col1 )
			, c2( col2 )
			, c3( col3 )
			, c4( col4 )
		{
		}

		Matrix4x4( numType typeToFill )
			: c1( { typeToFill, 0, 0, 0 } )
			, c2( { 0, typeToFill, 0, 0 } )
			, c3( { 0, 0, typeToFill, 0 } )
			, c4( { 0, 0, 0, typeToFill } )
		{
		}

		Matrix4x4( )
			: c1( { 0,0,0,0 } )
			, c2( { 0,0,0,0 } )
			, c3( { 0,0,0,0 } )
			, c4( { 0,0,0,0 } )
		{
		}

		typedef Vector4<numType> col_type;

		Vector4<numType> c1;
		Vector4<numType> c2;
		Vector4<numType> c3;
		Vector4<numType> c4;
	};

	template <typename T>
	Matrix4x4<T> operator*( Matrix4x4<T > const & m1, Matrix4x4<T> const & m2 )
	{

		typename Matrix4x4<T>::col_type const SrcA0 = m1.c1;
		typename Matrix4x4<T>::col_type const SrcA1 = m1.c2;
		typename Matrix4x4<T>::col_type const SrcA2 = m1.c3;
		typename Matrix4x4<T>::col_type const SrcA3 = m1.c4;

		typename Matrix4x4<T>::col_type const SrcB0 = m2.c1;
		typename Matrix4x4<T>::col_type const SrcB1 = m2.c2;
		typename Matrix4x4<T>::col_type const SrcB2 = m2.c3;
		typename Matrix4x4<T>::col_type const SrcB3 = m2.c4;

		Matrix4x4<T> Result( 0 );
		Result.c1 = SrcA0 * SrcB0.x + SrcA1 * SrcB0.y + SrcA2 * SrcB0.z + SrcA3 * SrcB0.w;
		Result.c2 = SrcA0 * SrcB1.x + SrcA1 * SrcB1.y + SrcA2 * SrcB1.z + SrcA3 * SrcB1.w;
		Result.c3 = SrcA0 * SrcB2.x + SrcA1 * SrcB2.y + SrcA2 * SrcB2.z + SrcA3 * SrcB2.w;
		Result.c4 = SrcA0 * SrcB3.x + SrcA1 * SrcB3.y + SrcA2 * SrcB3.z + SrcA3 * SrcB3.w;
		return Result;
	}

}