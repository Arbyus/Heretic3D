#pragma once
#include "../config.h"
#include "GraphicsStructs.h"

#include <functional>
#include <memory>

namespace Heretic3D
{

	class Shader_interface;
	class Model;

	class Shader
	{
	public:

		HERETIC3D Shader( std::shared_ptr<Shader_interface> );

		HERETIC3D static std::function< std::shared_ptr< Shader >( const std::string& vertex, const std::string& fragment )> CreateShader;

		HERETIC3D void SetShaderValue( const std::string& variableName, const Matrix4x4<>& newValue );
		HERETIC3D void SetShaderValue( const std::string& variableName, const int& newValue );
		HERETIC3D void SetShaderValue( const std::string& variableName, const float& newValue );
		HERETIC3D void SetShaderValue( const std::string& variableName, const Vector2<>& newValue );
		HERETIC3D void SetShaderValue( const std::string& variableName, const Vector3<>& newValue );
		HERETIC3D void SetShaderValue( const std::string& variableName, const Vector4<>& newValue );
		HERETIC3D void SetShaderValue( const std::string& variableName, const Matrix3x3<>& newValue );
		HERETIC3D unsigned int GetShaderID( );

	private:

		std::shared_ptr<Shader_interface> m_Pimpl;
	};

}