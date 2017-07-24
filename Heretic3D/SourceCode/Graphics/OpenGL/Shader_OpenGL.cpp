#include <glm/glm.hpp>
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "../../Input/InputStructs.h"
#include "Shader_OpenGL.hpp"

namespace Heretic3D
{
	Shader_OpenGL::Shader_OpenGL( const std::string & vertexIn, const std::string & fragmentIn )
	{
		// 1. Retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// ensures ifstream objects can throw exceptions:
		vShaderFile.exceptions( std::ifstream::badbit );
		fShaderFile.exceptions( std::ifstream::badbit );
		try
		{
			// Open files
			vShaderFile.open( vertexIn );
			fShaderFile.open( fragmentIn );
			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf( );
			fShaderStream << fShaderFile.rdbuf( );
			// close file handlers
			vShaderFile.close( );
			fShaderFile.close( );
			// Convert stream into string
			vertexCode = vShaderStream.str( );
			fragmentCode = fShaderStream.str( );
		}
		catch ( std::ifstream::failure e )
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const GLchar* vShaderCode = vertexCode.c_str( );
		const GLchar * fShaderCode = fragmentCode.c_str( );
		// 2. Compile shaders
		GLuint vertex, fragment;
		GLint success;
		GLchar infoLog[ 512 ];
		// Vertex Shader
		vertex = glCreateShader( GL_VERTEX_SHADER );
		glShaderSource( vertex, 1, &vShaderCode, NULL );
		glCompileShader( vertex );
		// Print compile errors if any
		glGetShaderiv( vertex, GL_COMPILE_STATUS, &success );
		if ( !success )
		{
			glGetShaderInfoLog( vertex, 512, NULL, infoLog );
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// Fragment Shader
		fragment = glCreateShader( GL_FRAGMENT_SHADER );
		glShaderSource( fragment, 1, &fShaderCode, NULL );
		glCompileShader( fragment );
		// Print compile errors if any
		glGetShaderiv( fragment, GL_COMPILE_STATUS, &success );
		if ( !success )
		{
			glGetShaderInfoLog( fragment, 512, NULL, infoLog );
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// Shader Program
		this->m_ShaderID = glCreateProgram( );
		glAttachShader( this->m_ShaderID, vertex );
		glAttachShader( this->m_ShaderID, fragment );
		glLinkProgram( this->m_ShaderID );
		// Print linking errors if any
		glGetProgramiv( this->m_ShaderID, GL_LINK_STATUS, &success );
		if ( !success )
		{
			glGetProgramInfoLog( this->m_ShaderID, 512, NULL, infoLog );
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		// Delete the shaders as they're linked into our program now and no longer necessery
		glDeleteShader( vertex );
		glDeleteShader( fragment );

	}
	void Shader_OpenGL::SetShaderValue( const std::string & variableName, const Matrix4x4<float>& newValue )
	{
		glUniformMatrix4fv( glGetUniformLocation( m_ShaderID, variableName.c_str() ) , 1, GL_FALSE, &newValue.r1.x );
	}

	void Shader_OpenGL::SetShaderValue( const std::string & variableName, const int & newValue )
	{
		glUniform1i( glGetUniformLocation( m_ShaderID, variableName.c_str( ) ), newValue );
	}

	void Shader_OpenGL::SetShaderValue( const std::string & variableName, const float & newValue )
	{
		glUniform1f( glGetUniformLocation( m_ShaderID, variableName.c_str( ) ), newValue );
	}

	void Shader_OpenGL::SetShaderValue( const std::string & variableName, const Vector2<float>& newValue )
	{
		glUniform2fv( glGetUniformLocation( m_ShaderID, variableName.c_str( ) ), 1, glm::value_ptr( glm::vec2( newValue.x, newValue.y) ) );
	}

	void Shader_OpenGL::SetShaderValue( const std::string & variableName, const Vector3 & newValue )
	{
		glUniform3fv( glGetUniformLocation( m_ShaderID, variableName.c_str( ) ), 1, glm::value_ptr( glm::vec3( newValue.x, newValue.y, newValue.z ) ) );
	}

	void Shader_OpenGL::SetShaderValue( const std::string & variableName, const Vector4<float>& newValue )
	{
		glUniform4fv( glGetUniformLocation( m_ShaderID, variableName.c_str( ) ), 1, glm::value_ptr( glm::vec4( newValue.x,newValue.y, newValue.z, newValue.w ) ) );
	}

	void Shader_OpenGL::SetShaderValue( const std::string & variableName, const Matrix3x3 & newValue )
	{
		glUniformMatrix3fv( glGetUniformLocation( m_ShaderID, variableName.c_str( ) ), 1, GL_FALSE, &newValue.r1.x );
	}

	unsigned int Shader_OpenGL::GetShaderID( )
	{
		return m_ShaderID;
	}

}