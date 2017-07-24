#pragma once
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

		__declspec( dllexport ) Mesh( const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures );
		__declspec( dllexport ) ~Mesh( );

		__declspec( dllexport ) std::vector<Texture> GetTextures( );
		__declspec( dllexport ) void SetTextures( const std::vector<Texture>& texturesToSet );
		
		__declspec( dllexport ) BufferInformation& GetBufferInformation( );
		__declspec( dllexport ) ModelPack& GetModelInformation( );

	private:

		BufferInformation m_ModelBufferInfo;

		ModelPack m_ModelPack;

	};
}