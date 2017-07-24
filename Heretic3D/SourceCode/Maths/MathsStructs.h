#pragma once

namespace Heretic3D
{
	template <typename numType>
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

	struct Vector3
	{
		Vector3( float p_x, float p_y, float p_z )
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

		float x;
		float y;
		float z;

		Vector3& operator*( float&& other )
		{
			this->x *= other;
			this->y *= other;
			this->z *= other;
			return *this;
		}

	};


	template <typename numType>
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

	struct Matrix3x3
	{
		Matrix3x3( Vector3 row1, Vector3 row2, Vector3 row3 )
			: r1( row1 )
			, r2( row2 )
			, r3( row3 )
		{
		}

		Matrix3x3( )
			: r1( { 0,0,0 } )
			, r2( { 0,0,0 } )
			, r3( { 0,0,0 } )
		{
		}

		Vector3 r1;
		Vector3 r2;
		Vector3 r3;
	};

	template <typename numType>
	struct Matrix4x4
	{
		Matrix4x4( Vector4<numType> row1, Vector4<numType> row2, Vector4<numType> row3, Vector4<numType> row4 )
			: r1( row1 )
			, r2( row2 )
			, r3( row3 )
			, r4( row4 )
		{
		}

		Matrix4x4( numType typeToFill )
			: r1( { typeToFill, typeToFill, typeToFill, typeToFill } )
			, r2( { typeToFill, typeToFill, typeToFill, typeToFill } )
			, r3( { typeToFill, typeToFill, typeToFill, typeToFill } )
			, r4( { typeToFill, typeToFill, typeToFill, typeToFill } )
		{
		}

		Matrix4x4( )
			: r1( { 0,0,0,0 } )
			, r2( { 0,0,0,0 } )
			, r3( { 0,0,0,0 } )
			, r4( { 0,0,0,0 } )
		{
		}

		Vector4<numType> r1;
		Vector4<numType> r2;
		Vector4<numType> r3;
		Vector4<numType> r4;
	};
}