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
		HERETIC3D int CreateWindow( );
		HERETIC3D Vector2<double> GetCursorPositionOnScreen( );
		HERETIC3D bool WantsToClose( );

		HERETIC3D void BeginFrame( );
		HERETIC3D void EndFrame( );

		HERETIC3D void SetKeyCallback( keyCallbackFunc callbackFunc );

		HERETIC3D unsigned int LoadTexture( const std::string& imagePath );

		HERETIC3D void Cleanup( );

		HERETIC3D Matrix4x4<float> GetPerspectiveMatrix( const float& fovy, const float& aspectRatio, const float& nearPlane, const float& farPlane );
		HERETIC3D Matrix4x4<float> GetLookAtMatrix( const Vector3<>& eyePos, const Vector3<>& centerPos, const Vector3<>& upPos );
		HERETIC3D Matrix4x4<float> GetOrthographicMatrix( const float& left, const float& right, const float& bottom, const float& top, const float& nearPlane, const float& farPlane );

	private:

		std::shared_ptr<Graphics_interface> m_Pimpl;
	};

}