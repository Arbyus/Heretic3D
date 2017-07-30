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

	void Model::SetPosition( const Vector3<>& newPosition )
	{
		m_Pimpl->SetPosition( newPosition );
	}

	void Model::SetRotation( const Vector3<>& newRotation )
	{
		m_Pimpl->SetRotation( newRotation );
	}

	void Model::SetScale( const Vector3<>& newScale )
	{
		m_Pimpl->SetScale( newScale );
	}

	void Model::SetShader( std::weak_ptr<Shader> newShader )
	{
		m_Pimpl->SetShader( newShader );
	}

	std::weak_ptr<Shader> Model::GetShader( )
	{
		return m_Pimpl->GetShader( );
	}

	HERETIC3D void Model::SetShaderVars( )
	{
		m_Pimpl->SetShaderVars( );
	}

	void Model::LoadModel( const std::string& path, const std::string& dirr )
	{
		m_Pimpl->LoadModel( path, dirr );
	}

	std::vector<Mesh>& Model::GetMesh( )
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