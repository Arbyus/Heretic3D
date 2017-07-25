#include "Model.h"
#include "../Models/Mesh/Mesh.h"

#include "Model_interface.hpp"

namespace Heretic3D
{

	decltype ( Model::CreateModel ) Model::CreateModel;

	Model::Model( std::shared_ptr<Model_interface> impl )
	{
		m_Pimpl = impl;
	}

	void Model::SetupMeshes( )
	{
		m_Pimpl->SetupMeshes( );
	}

	// Draws the model, and thus all its meshes
	void Model::Draw( const unsigned int shaderID )
	{
		m_Pimpl->Draw( shaderID );
	}

	void Model::LoadModel( const std::string& path, const std::string& dirr )
	{
		m_Pimpl->LoadModel( path, dirr );
	}

	std::vector<Mesh> Model::GetMesh( )
	{
		return m_Pimpl->GetMesh( );
	}

	std::vector<TextureStruct> Model::GetTextures( )
	{
		return m_Pimpl->GetTextures( );

	}

	void Model::SetTextures( std::vector<TextureStruct> newVec )
	{
		m_Pimpl->SetTextures( newVec );
	}
}