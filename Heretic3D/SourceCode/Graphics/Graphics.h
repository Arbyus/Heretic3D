#pragma once
#include "../config.h"
#include "GraphicsStructs.h"

#include <functional>
#include <memory>

#undef CreateWindow

namespace Heretic3D
{

	class Graphics_interface;
	class Model;

	class Graphics
	{
	public:

		HERETIC3D Graphics( std::shared_ptr<Graphics_interface> );

		HERETIC3D static std::function< std::shared_ptr< Graphics >( const std::string& path, const std::string& dire ) > CreateGraphicsImplementation;

		// Draws the model, and thus all its meshes
		HERETIC3D void Draw( const unsigned int shaderID );
		HERETIC3D void SetupModel( std::weak_ptr<Model> modelToSetup );
		HERETIC3D int CreateWindow( );
		HERETIC3D Vector2<double> GetCursorPositionOnScreen( );
		HERETIC3D bool WantsToClose( );

		HERETIC3D void BeginFrame( );
		HERETIC3D void EndFrame( );

		HERETIC3D void SetKeyCallback( keyCallbackFunc callbackFunc );

		HERETIC3D unsigned int LoadTexture( const std::string& imagePath );

		HERETIC3D void Cleanup( );

	private:

		std::shared_ptr<Graphics_interface> m_Pimpl;
	};

}