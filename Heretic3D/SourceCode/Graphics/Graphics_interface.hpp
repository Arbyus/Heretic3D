#pragma once

#include "Models/Model.h"

namespace Heretic3D
{
	class Graphics_interface
	{
		public:

		virtual void SetupModel( std::weak_ptr<Model> modelToSetup, std::weak_ptr<Shader> shader ) = 0;
		virtual void Draw( const unsigned int shaderID ) = 0;
		virtual int CreateWindow( ) = 0;
		virtual Vector2<double> GetCursorPositionOnScreen( ) = 0;
		virtual bool WantsToClose( ) = 0;

		virtual void BeginFrame( ) = 0;
		virtual void EndFrame( ) = 0;

		virtual void SetKeyCallback( keyCallbackFunc callbackFunc ) = 0;

		virtual unsigned int LoadTexture( const std::string& imagePath ) = 0;

		virtual void Cleanup( ) = 0;

		virtual Matrix4x4<> GetPerspectiveMatrix( const float& fovy, const float& aspectRatio, const float& nearPlane, const float& farPlane ) = 0;
		virtual Matrix4x4<> GetOrthographicMatrix( const float& left, const float& right, const float& bottom, const float& top, const float& nearPlane, const float& farPlane ) = 0;
		virtual Matrix4x4<> GetLookAtMatrix( const Vector3<>& eyePos, const Vector3<>& centerPos, const Vector3<>& upPos ) = 0;

	};
}