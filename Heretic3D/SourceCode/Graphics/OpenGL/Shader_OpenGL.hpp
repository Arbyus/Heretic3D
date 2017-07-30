#pragma once
// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <glm/glm.hpp>
// GL Includes
#include "../Shader_interface.hpp"

namespace Heretic3D
{

	class Shader_OpenGL : public Shader_interface
	{
		using ShaderMap = std::map<unsigned int, glm::mat4>;

	public:

		Shader_OpenGL( const std::string& vertex, const std::string& fragment );

		virtual void SetShaderValue( const std::string& variableName, const Matrix4x4<>& newValue ) override;
		virtual void SetShaderValue( const std::string& variableName, const int& newValue ) override;
		virtual void SetShaderValue( const std::string& variableName, const float& newValue ) override;
		virtual void SetShaderValue( const std::string& variableName, const Vector2<>& newValue ) override;
		virtual void SetShaderValue( const std::string& variableName, const Vector3<>& newValue ) override;
		virtual void SetShaderValue( const std::string& variableName, const Vector4<>& newValue ) override;
		virtual void SetShaderValue( const std::string& variableName, const Matrix3x3<>& newValue ) override;

		virtual unsigned int GetShaderID( ) override;

	private:
		unsigned int m_ShaderID;
		ShaderMap holdMats;


	};

}