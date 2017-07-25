#pragma once

#include "Mesh/Mesh.h"

#include <vector>

namespace Heretic3D
{

	class Model_interface
	{
	public:
		// Draws the model, and thus all its meshes
		virtual void Draw( const unsigned int shaderID ) = 0;

		virtual std::vector<Mesh> GetMesh( ) = 0;
		virtual std::vector<TextureStruct> GetTextures( ) = 0;
		virtual void SetTextures( std::vector<TextureStruct> ) = 0;
		virtual void LoadModel( const std::string& path, const std::string& dirr ) = 0;
		virtual void SetupMeshes( ) = 0;

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