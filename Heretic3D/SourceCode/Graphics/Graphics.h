#pragma once
#include <functional>
#include <memory>
#include "GraphicsStructs.h"

#undef CreateWindow

namespace Heretic3D
{

	class Graphics_interface;
	class Model;

	class Graphics
	{
	public:

		__declspec( dllexport ) Graphics( std::shared_ptr<Graphics_interface> );

		__declspec( dllexport ) static std::function<unsigned int( const std::string& imagePath )> CreateTexture;
		__declspec( dllexport ) static std::function<std::shared_ptr<Graphics>( const std::string& path, const std::string& dire )> CreateGraphicsImplementation;

		// Draws the model, and thus all its meshes
		__declspec( dllexport ) void Draw( const unsigned int shaderID );
		__declspec( dllexport ) void SetupModel( std::weak_ptr<Model> modelToSetup );
		__declspec( dllexport ) int CreateWindow( );
		__declspec( dllexport ) Vector2<double> GetCursorPositionOnScreen( );
		__declspec( dllexport ) bool WantsToClose( );

		__declspec( dllexport ) void EndFrame( );

		__declspec( dllexport ) void SetKeyCallback( keyCallbackFunc callbackFunc );

		__declspec( dllexport ) unsigned int LoadTexture( const std::string& imagePath );

	private:

		std::shared_ptr<Graphics_interface> m_Pimpl;
	};

}