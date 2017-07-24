#pragma once
#include "Mesh/Mesh.h"

#include <functional>
#include <memory>

namespace Heretic3D
{

	class Model_interface;

	class Model
	{
	public:

		__declspec( dllexport ) Model( std::shared_ptr<Model_interface> );


		__declspec( dllexport ) static std::function<std::shared_ptr<Heretic3D::Model>( const std::string& path, const std::string& dire, const int )> CreateModel;

		// Draws the model, and thus all its meshes
		__declspec( dllexport ) void Draw( const unsigned int shaderID );

		__declspec( dllexport ) std::vector<Mesh> GetMesh( );
		__declspec( dllexport ) std::vector<Texture> GetTextures( );
		__declspec( dllexport ) void SetTextures( std::vector<Texture> );
		__declspec( dllexport ) void LoadModel( const std::string& path, const std::string& dirr );
		__declspec( dllexport ) void SetupMeshes( );

	private:

		std::shared_ptr<Model_interface> m_Pimpl;
	};

}