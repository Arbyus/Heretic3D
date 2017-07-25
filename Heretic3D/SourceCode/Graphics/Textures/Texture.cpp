#include "Texture.h"

namespace Heretic3D
{
	decltype( Texture::CreateTexture ) Texture::CreateTexture;

	Texture::Texture( const unsigned int textureID )
		: m_ID( textureID )
	{}

	unsigned int Texture::GetTextureID( )
	{
		return m_ID;
	}

}