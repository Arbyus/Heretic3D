#pragma once
#include <functional>
#include <memory>
#include "GraphicsStructs.h"

#undef CreateWindow

namespace Heretic3D
{

	class Shader_interface;
	class Model;

	class Shader
	{
	public:

		__declspec( dllexport ) Shader( std::shared_ptr<Shader_interface> );

		__declspec( dllexport ) static std::function<std::shared_ptr<Shader>( const std::string& vertex, const std::string& fragment )> CreateShader;

		__declspec( dllexport ) void SetShaderValue( const std::string& variableName, const Matrix4x4<float>& newValue );
		__declspec( dllexport ) void SetShaderValue( const std::string& variableName, const int& newValue );
		__declspec( dllexport ) void SetShaderValue( const std::string& variableName, const float& newValue );
		__declspec( dllexport ) void SetShaderValue( const std::string& variableName, const Vector2<float>& newValue );
		__declspec( dllexport ) void SetShaderValue( const std::string& variableName, const Vector3& newValue );
		__declspec( dllexport ) void SetShaderValue( const std::string& variableName, const Vector4<float>& newValue );
		__declspec( dllexport ) void SetShaderValue( const std::string& variableName, const Matrix3x3& newValue );
		__declspec( dllexport ) unsigned int GetShaderID( );

	private:

		std::shared_ptr<Shader_interface> m_Pimpl;
	};

}