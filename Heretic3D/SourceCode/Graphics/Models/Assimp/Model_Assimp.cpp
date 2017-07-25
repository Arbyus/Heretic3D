#include "Model_Assimp.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../../Graphics.h"
#include "../../Textures/Texture.h"

#undef LoadImage

namespace Heretic3D
{

	Model_Assimp::Model_Assimp( const std::string& path, const std::string& dire )
	{
		this->LoadModel( path, dire );
	}

	Model_Assimp::Model_Assimp( )
	{
		dir = "";
	}

	void Model_Assimp::SetupMeshes( )
	{
		std::vector<TextureStruct> textures;

		for ( int i = 0; i < texturesStrings.size( ); ++i )
		{
			TextureStruct texture;
			texture.id = Heretic3D::Texture::CreateTexture( dir + "/" + texturesStrings[ i ] )->GetTextureID();
			texture.type = aiTextureType_DIFFUSE;
			texture.path = texturesStrings[ i ].c_str( );
			textures.push_back( texture );
			this->textures_loaded.push_back( texture );
		}
		for ( unsigned int i = 0; i < this->meshes.size( ); i++ )
		{
			this->meshes[ i ].SetTextures( textures );
		}
	}

	// Draws the model, and thus all its meshes
	void Model_Assimp::Draw( unsigned int shaderID )
	{
		//for ( GLuint i = 0; i < this->meshes.size( ); i++ )
		//	this->meshes[ i ].Draw( shaderID );
	}

	void Model_Assimp::LoadModel( const std::string& path, const std::string& dirr )
	{
		dir = path;

		// Read file via ASSIMP
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile( dirr, aiProcess_Triangulate | aiProcess_FlipUVs );
		// Check for errors
		if ( !scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode ) // if is Not Zero
		{
			std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString( ) << std::endl;
			return;
		}
		// Retrieve the directory path of the filepath
		this->directory = path.substr( 0, path.find_last_of( '/' ) );

		// Process ASSIMP's root node recursively
		this->ProcessNode( scene->mRootNode, scene );
	}

	std::vector<Mesh> Model_Assimp::GetMesh( )
	{
		return meshes;
	}

	std::vector<TextureStruct> Model_Assimp::GetTextures( )
	{
		return meshes[ 0 ].GetTextures( );
	}

	void Model_Assimp::SetTextures( std::vector<TextureStruct> newVec )
	{
		meshes[ 0 ].SetTextures( newVec );
	}

	void Model_Assimp::ProcessNode( aiNode* node, const aiScene* scene )
	{
		// Process each mesh located at the current node
		for ( unsigned int i = 0; i < node->mNumMeshes; i++ )
		{
			// The node object only contains indices to index the actual objects in the scene. 
			// The scene contains all the data, node is just to keep stuff organized (like relations between nodes).
			aiMesh* mesh = scene->mMeshes[ node->mMeshes[ i ] ];
			this->meshes.push_back( this->ProcessMesh( mesh, scene ) );
		}
		// After we've processed all of the meshes (if any) we then recursively process each of the children nodes
		for ( unsigned int i = 0; i < node->mNumChildren; i++ )
		{
			this->ProcessNode( node->mChildren[ i ], scene );
		}

	}

	Mesh Model_Assimp::ProcessMesh( aiMesh* mesh, const aiScene* scene )
	{
		// Data to fill
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<TextureStruct> textures;

		// Walk through each of the mesh's vertices
		for ( unsigned int i = 0; i < mesh->mNumVertices; i++ )
		{
			Vertex vertex;
			Vector3 vector; // We declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
			// Positions
			vector.x = mesh->mVertices[ i ].x;
			vector.y = mesh->mVertices[ i ].y;
			vector.z = mesh->mVertices[ i ].z;
			vertex.Position = vector;
			// Normals
			vector.x = mesh->mNormals[ i ].x;
			vector.y = mesh->mNormals[ i ].y;
			vector.z = mesh->mNormals[ i ].z;
			vertex.Normal = vector;
			// Texture Coordinates
			if ( mesh->mTextureCoords[ 0 ] ) // Does the mesh contain texture coordinates?
			{
				Vector2<float> vec;
				// A vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
				// use models where a vertex can have multiple texture coordinates so we always take the first set (0).
				vec.x = mesh->mTextureCoords[ 0 ][ i ].x;
				vec.y = mesh->mTextureCoords[ 0 ][ i ].y;
				vertex.TexCoords = vec;
			}
			else
				vertex.TexCoords = Vector2<float>( 0.0f, 0.0f );
			vertices.push_back( vertex );
		}
		// Now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
		for ( unsigned int i = 0; i < mesh->mNumFaces; i++ )
		{
			aiFace face = mesh->mFaces[ i ];
			// Retrieve all indices of the face and store them in the indices vector
			for ( unsigned int j = 0; j < face.mNumIndices; j++ )
				indices.push_back( face.mIndices[ j ] );
		}
		// Process materials
		if ( mesh->mMaterialIndex >= 0 )
		{
			for ( unsigned int i = 0; i < scene->mMaterials[ mesh->mMaterialIndex ]->GetTextureCount( aiTextureType_DIFFUSE ); i++ )
			{
				aiString str;
				scene->mMaterials[ mesh->mMaterialIndex ]->GetTexture( aiTextureType_DIFFUSE, i, &str );
				texturesStrings.push_back( str.C_Str( ) );
			}
		}

		// Return a mesh object created from the extracted mesh data
		return Mesh( vertices, indices, textures );
	}
}