#pragma once
// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

// GL Includes
#include "../Model_interface.hpp"
#include "../Mesh/Mesh.h"

struct aiNode;
struct aiMesh;
struct aiScene;

namespace Heretic3D
{

	class Model_Assimp : public Model_interface
	{
	public:

		Model_Assimp( const std::string& path, const std::string& dire );
		Model_Assimp( );

		virtual void Draw( const unsigned int shaderID ) override;

		virtual std::vector<Mesh> GetMesh( ) override;
		virtual std::vector<Texture> GetTextures( ) override;
		virtual void SetTextures( std::vector<Texture> ) override;
		virtual void LoadModel( const std::string& path, const std::string& dirr ) override;
		virtual void SetupMeshes( ) override;

	private:

		void ProcessNode( aiNode* node, const aiScene* scene );

		Mesh ProcessMesh( aiMesh* mesh, const aiScene* scene );
	};

}