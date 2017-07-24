
#include "Mesh.h"

namespace Heretic3D
{

	Mesh::Mesh( const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures )
	{
		this->m_ModelPack.vertices = vertices;
		this->m_ModelPack.indices = indices;
		this->m_ModelPack.textures = textures;
	}

	Mesh::~Mesh( )
	{

	}

	std::vector<Texture> Mesh::GetTextures( )
	{
		return this->m_ModelPack.textures;
	}

	void Mesh::SetTextures( const std::vector<Texture>& newVec )
	{
		this->m_ModelPack.textures = newVec;
	}

	BufferInformation& Mesh::GetBufferInformation( )
	{
		return m_ModelBufferInfo;
	}

	ModelPack& Mesh::GetModelInformation( )
	{
		return m_ModelPack;
	}
}