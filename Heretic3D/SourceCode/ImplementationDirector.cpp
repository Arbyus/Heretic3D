#include "ImplementationDirector.h"

#include "Graphics/Models/Model.h"
#include "Graphics/Models/Assimp/Model_Assimp.hpp"
#include "Graphics/OpenGL/Graphics_OpenGL.hpp"
#include "Graphics/Graphics.h"
#include "Graphics/Shader.h"
#include "Graphics/Textures/Texture.h"
#include "Graphics/OpenGL/Shader_OpenGL.hpp"


namespace Heretic3D
{
	namespace
	{
		std::shared_ptr<Graphics_interface> graphicsImpl;

		static std::shared_ptr<Heretic3D::Model> AssimpModels( const std::string& path, const std::string& dire, std::weak_ptr<Shader> shaderID,
			const Vector3<>& position, const Vector3<>& scale, const Vector3<>& rotation )
		{
			auto assimpObj = std::make_shared<Heretic3D::Model_Assimp>( path, dire, position, scale, rotation );

			auto newModel = std::make_shared<Heretic3D::Model>( assimpObj );

			newModel->SetupMeshes( );
			graphicsImpl->SetupModel( newModel, shaderID );

			return newModel;
		}

		static std::shared_ptr<Heretic3D::Texture> OpenGLTextures( const std::string& texturePath )
		{
			return std::make_shared<Heretic3D::Texture>( graphicsImpl->LoadTexture( texturePath ) );
		}

		static std::shared_ptr<Heretic3D::Shader> OpenGLShaders( const std::string& vertexShader, const std::string& fragmentShader )
		{
			auto shaderObj = std::make_shared<Heretic3D::Shader_OpenGL>( vertexShader, fragmentShader );

			auto newShader = std::make_shared<Heretic3D::Shader>( shaderObj );

			return newShader;
		}
		
		void SetupAssimp( )
		{
			Heretic3D::Model::CreateModel = std::bind( &Heretic3D::AssimpModels, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
				std::placeholders::_4, std::placeholders::_5, std::placeholders::_6 );
		}

		void SetupGraphics( )
		{
			graphicsImpl = std::make_shared<Graphics_OpenGL>();
			
			Heretic3D::Shader::CreateShader = std::bind( &Heretic3D::OpenGLShaders, std::placeholders::_1, std::placeholders::_2 );
			Heretic3D::Texture::CreateTexture = std::bind( &Heretic3D::OpenGLTextures, std::placeholders::_1 );
		}


	}


	ImplementationDirector::ImplementationDirector( const ImplementationDetails& impl )
	{
		if ( impl.graphicsEngine == "opengl" )
		{
			SetupGraphics( );
		}
		else
		{
			//maybe default to something?
		}


		if ( impl.modelType == "assimp" )
		{
			SetupAssimp( );
		}

	}

	void ImplementationDirector::DrawShaderBatch( const unsigned int shaderId )
	{
		graphicsImpl->Draw( shaderId );
	}

	std::shared_ptr<Graphics> ImplementationDirector::GetGraphicsDevice( )
	{
		return std::make_shared<Graphics>(graphicsImpl);
	}

}