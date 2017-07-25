#pragma once
#include "../Maths/MathsStructs.h"
#include "../Input/InputStructs.h"

#include <string>
#include <vector>
#include <functional>
#include <memory>

namespace Heretic3D
{
	typedef void( *keyCallbackFunc )( Heretic3D::KeyInput, Heretic3D::KeyAction );

	struct Vertex 
	{
		Vector3 Position;
		Vector3 Normal;
		Vector2<float> TexCoords;
	};

	struct TextureStruct
	{
		unsigned int id;
		std::string type;
		std::string path;
	};

	struct ModelPack
	{
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<TextureStruct> textures;
	};

}