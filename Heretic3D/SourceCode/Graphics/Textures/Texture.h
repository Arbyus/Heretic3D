#pragma once
#include "../../config.h"

#include <functional>
#include <memory>

namespace Heretic3D
{
	class Texture
	{
	public:

		HERETIC3D static std::function< std::shared_ptr< Texture >( const std::string& texturePath ) > CreateTexture;

		HERETIC3D Texture( const unsigned int textureID );

		HERETIC3D unsigned int GetTextureID( );

	private:

		unsigned int m_ID;
	};

}