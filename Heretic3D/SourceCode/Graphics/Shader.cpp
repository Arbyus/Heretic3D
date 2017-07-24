#include "Shader.h"
#include "Shader_interface.hpp"


namespace Heretic3D
{
		
	decltype( Shader::CreateShader ) Shader::CreateShader;
	
	
	Shader::Shader( std::shared_ptr<Shader_interface> impl )
	{
		m_Pimpl = impl;
	}

	void Shader::SetShaderValue( const std::string & variableName, const Matrix4x4<float>& newValue )
	{
		m_Pimpl->SetShaderValue( variableName, newValue );
	}

	void Shader::SetShaderValue( const std::string & variableName, const int & newValue )
	{
		m_Pimpl->SetShaderValue( variableName, newValue );
	}

	void Shader::SetShaderValue( const std::string & variableName, const float & newValue )
	{
		m_Pimpl->SetShaderValue( variableName, newValue );
	}

	void Shader::SetShaderValue( const std::string & variableName, const Vector2<float>& newValue )
	{
		m_Pimpl->SetShaderValue( variableName, newValue );
	}

	void Shader::SetShaderValue( const std::string & variableName, const Vector3 & newValue )
	{
		m_Pimpl->SetShaderValue( variableName, newValue );
	}

	void Shader::SetShaderValue( const std::string & variableName, const Vector4<float>& newValue )
	{
		m_Pimpl->SetShaderValue( variableName, newValue );
	}

	void Shader::SetShaderValue( const std::string & variableName, const Matrix3x3 & newValue )
	{
		m_Pimpl->SetShaderValue( variableName, newValue );
	}
	
	unsigned int Shader::GetShaderID( )
	{
		return m_Pimpl->GetShaderID( );
	}

}