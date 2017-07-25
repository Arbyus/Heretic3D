#pragma once
#include "../../../config.h"
#include "../../GraphicsStructs.h"

#include <vector>

namespace Heretic3D
{
	struct BufferInformation
	{
		unsigned int vAO;
		unsigned int vBO;
		unsigned int eBO;
	};

	class Mesh 
	{
	public:

		HERETIC3D Mesh( const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<TextureStruct>& textures );
		HERETIC3D ~Mesh( );

		HERETIC3D std::vector<TextureStruct> GetTextures( );
		HERETIC3D void SetTextures( const std::vector<TextureStruct>& texturesToSet );
		
		HERETIC3D BufferInformation& GetBufferInformation( );
		HERETIC3D ModelPack& GetModelInformation( );

	private:

		BufferInformation m_ModelBufferInfo;

		ModelPack m_ModelPack;

	};
}