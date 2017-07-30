#pragma once
#include "../../config.h"
#include "Mesh/Mesh.h"
#include "../Shader.h"
#include <functional>
#include <memory>

namespace Heretic3D
{

	class Model_interface;

	class Model
	{
	public:

		HERETIC3D Model( std::shared_ptr<Model_interface> );

		HERETIC3D static std::function< std::shared_ptr< Heretic3D::Model >( const std::string& path, const std::string& dire, 
			std::weak_ptr<Shader> shaderProgram, const Vector3<>& position, const Vector3<>& scale, const Vector3<>& rotation ) > CreateModel;

		HERETIC3D std::vector<Mesh>& GetMesh( );
		HERETIC3D std::vector<TextureStruct> GetTextures( );
		HERETIC3D void SetTextures( std::vector<TextureStruct> );
		HERETIC3D void LoadModel( const std::string& path, const std::string& dirr );
		HERETIC3D void SetupMeshes( );

		HERETIC3D void SetPosition( const Vector3<>& newPosition );
		HERETIC3D void SetRotation( const Vector3<>& newRotation );
		HERETIC3D void SetScale( const Vector3<>& newScale );

		HERETIC3D void SetShader( std::weak_ptr<Shader> newShader );
		HERETIC3D std::weak_ptr<Shader> GetShader( );

		HERETIC3D void SetShaderVars( );

	private:

		std::shared_ptr<Model_interface> m_Pimpl;
	};

}