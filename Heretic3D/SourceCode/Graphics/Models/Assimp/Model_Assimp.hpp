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

		Model_Assimp( const std::string& path, const std::string& dire, const Vector3<>& position, const Vector3<>& scale, const Vector3<>& rotation );
		Model_Assimp( );

		virtual std::vector<Mesh>& GetMesh( ) override;
		virtual std::vector<TextureStruct> GetTextures( ) override;
		virtual void SetTextures( std::vector<TextureStruct> ) override;
		virtual void LoadModel( const std::string& path, const std::string& dirr ) override;
		virtual void SetupMeshes( ) override;

		virtual void SetPosition( const Vector3<>& newPosition ) override;
		virtual void SetRotation( const Vector3<>& newRotation ) override;
		virtual void SetScale( const Vector3<>& newScale ) override;

		virtual void SetShader( std::weak_ptr<Shader> newShader ) override;
		virtual std::weak_ptr<Shader> GetShader( ) override;

		virtual void SetShaderVars( ) override;

	private:

		std::weak_ptr<Shader> m_ShaderUsing;

		Vector3<> m_ModelPosition;
		Vector3<> m_ModelScale;
		Vector3<> m_ModelRotate;

		void ProcessNode( aiNode* node, const aiScene* scene );

		Mesh ProcessMesh( aiMesh* mesh, const aiScene* scene );

	};

}