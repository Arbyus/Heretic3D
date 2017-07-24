#pragma once
#include <string>
#include <functional>
#include <memory>

namespace Heretic3D
{

	class Model;
	class Graphics;

	struct ImplementationDetails
	{
		std::string modelType;
		std::string graphicsEngine;
	};

	class ImplementationDirector
	{


	public:
		__declspec( dllexport ) ImplementationDirector( const ImplementationDetails& impl );
		__declspec( dllexport ) void DrawShaderBatch( const unsigned int shaderId );
		__declspec( dllexport ) std::shared_ptr<Graphics> GetGraphicsDevice( );

	};

}