#pragma once
#include "../../config.h"
#include "Mesh/Mesh.h"

#include <functional>
#include <memory>

namespace Heretic3D
{

	class Model_interface;

	class Model
	{
	public:

		HERETIC3D Model( std::shared_ptr<Model_interface> );

		HERETIC3D static std::function< std::shared_ptr< Heretic3D::Model >( const std::string& path, const std::string& dire, const int ) > CreateModel;

		// Draws the model, and thus all its meshes
		HERETIC3D void Draw( const unsigned int shaderID );

		HERETIC3D std::vector<Mesh> GetMesh( );
		HERETIC3D std::vector<TextureStruct> GetTextures( );
		HERETIC3D void SetTextures( std::vector<TextureStruct> );
		HERETIC3D void LoadModel( const std::string& path, const std::string& dirr );
		HERETIC3D void SetupMeshes( );

	private:

		std::shared_ptr<Model_interface> m_Pimpl;
	};

}