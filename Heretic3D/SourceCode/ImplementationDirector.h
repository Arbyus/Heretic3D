#pragma once

#include "config.h"
#include "Graphics/Models/Model.h"
#include "Graphics/Shader.h"
#include "Graphics/Graphics.h"

#include <string>
#include <functional>
#include <memory>

namespace Heretic3D
{

	struct ImplementationDetails
	{
		std::string modelType;
		std::string graphicsEngine;
	};

	class ImplementationDirector
	{


	public:
		HERETIC3D ImplementationDirector( const ImplementationDetails& impl );
		HERETIC3D void DrawShaderBatch( const unsigned int shaderId );
		HERETIC3D std::shared_ptr<Graphics> GetGraphicsDevice( );
		HERETIC3D std::shared_ptr<Model> GetModel( const std::string& path, const std::string& dire, const int shaderID );


	};

}