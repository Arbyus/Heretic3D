#pragma once

#include "Mesh/Mesh.h"

#include <vector>

namespace Heretic3D
{

	class Shader;

	class Model_interface
	{
	public:
		virtual std::vector<Mesh>& GetMesh( ) = 0;
		virtual std::vector<TextureStruct> GetTextures( ) = 0;
		virtual void SetTextures( std::vector<TextureStruct> ) = 0;
		virtual void LoadModel( const std::string& path, const std::string& dirr ) = 0;
		virtual void SetupMeshes( ) = 0;

		virtual void SetPosition( const Vector3<>& ) = 0;
		virtual void SetRotation( const Vector3<>& ) = 0;
		virtual void SetScale( const Vector3<>& ) = 0;

		virtual void SetShader( std::weak_ptr<Shader> newShader ) = 0;
		virtual std::weak_ptr<Shader> GetShader( ) = 0;
		virtual void SetShaderVars( ) = 0;

	protected:
		/*  Model Data  */
		std::vector<std::string> texturesStrings;
		std::vector<Mesh> meshes;
		std::string dir;
		std::string directory;
		std::vector<TextureStruct> textures_loaded;

	private:

	};
}