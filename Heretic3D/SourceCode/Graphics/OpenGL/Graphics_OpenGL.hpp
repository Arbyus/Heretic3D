#pragma once
// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

// GL Includes
#include "../Graphics_interface.hpp"

class GLFWwindow;

namespace Heretic3D
{

	class Graphics_OpenGL : public Graphics_interface
	{
	public:

		virtual void Draw( const unsigned int shaderID ) override;

		virtual void SetupModel( std::weak_ptr<Model> modelToSetup, const unsigned int shaderID ) override;

		virtual int CreateWindow( ) override;

		virtual Vector2<double> GetCursorPositionOnScreen( ) override;

		virtual bool WantsToClose( ) override;

		virtual void EndFrame( ) override;

		virtual void SetKeyCallback( keyCallbackFunc callbackFunc ) override;

		virtual unsigned int LoadTexture( const std::string& imagePath ) override;

	private:

		std::map<unsigned int, std::vector< std::weak_ptr<Model> > > m_RenderMapByShaderID;
		GLFWwindow* m_Window;

	};

}