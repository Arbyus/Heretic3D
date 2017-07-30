#pragma once

#include "Models/Model.h"
#include <string>

namespace Heretic3D
{
	class Shader_interface
	{
		public:
		
			virtual void SetShaderValue( const std::string& variableName, const Matrix4x4<>& newValue ) = 0;
			virtual void SetShaderValue( const std::string& variableName, const int& newValue ) = 0;
			virtual void SetShaderValue( const std::string& variableName, const float& newValue ) = 0;
			virtual void SetShaderValue( const std::string& variableName, const Vector2<>& newValue ) = 0;
			virtual void SetShaderValue( const std::string& variableName, const Vector3<>& newValue ) = 0;
			virtual void SetShaderValue( const std::string& variableName, const Vector4<>& newValue ) = 0;
			virtual void SetShaderValue( const std::string& variableName, const Matrix3x3<>& newValue ) = 0;
			virtual unsigned int GetShaderID( ) = 0;

	};
}