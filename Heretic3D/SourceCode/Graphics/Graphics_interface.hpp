#pragma once

#include "Models/Model.h"

namespace Heretic3D
{
	class Graphics_interface
	{
		public:

		virtual void SetupModel( std::weak_ptr<Model> modelToSetup, const unsigned int shaderID ) = 0;
		virtual void Draw( const unsigned int shaderID ) = 0;
		virtual int CreateWindow( ) = 0;
		virtual Vector2<double> GetCursorPositionOnScreen( ) = 0;
		virtual bool WantsToClose( ) = 0;

		virtual void EndFrame( ) = 0;

		virtual void SetKeyCallback( keyCallbackFunc callbackFunc ) = 0;

		virtual unsigned int LoadTexture( const std::string& imagePath ) = 0;

	};
}