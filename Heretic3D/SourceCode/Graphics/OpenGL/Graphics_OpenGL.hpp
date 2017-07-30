#pragma once
// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>
#include <vector>


// GL Includes
#include "../Graphics_interface.hpp"

class GLFWwindow;

namespace Heretic3D
{

	class Graphics_OpenGL : public Graphics_interface
	{
	public:

		Graphics_OpenGL( );

		virtual void Draw( const unsigned int shaderID ) override;

		virtual void SetupModel( std::weak_ptr<Model> modelToSetup, std::weak_ptr<Shader> shader ) override;

		virtual int CreateWindow( ) override;

		virtual Vector2<double> GetCursorPositionOnScreen( ) override;

		virtual bool WantsToClose( ) override;

		virtual void BeginFrame( ) override;

		virtual void EndFrame( ) override;

		virtual void SetKeyCallback( keyCallbackFunc callbackFunc ) override;

		virtual unsigned int LoadTexture( const std::string& imagePath ) override;

		virtual void Cleanup( ) override;

		virtual Matrix4x4<> GetPerspectiveMatrix( const float& fovy, const float& aspectRatio, const float& nearPlane, const float& farPlane ) override;
		virtual Matrix4x4<> GetLookAtMatrix( const Vector3<>& eyePos, const Vector3<>& centerPos, const Vector3<>& upPos ) override;
		virtual Matrix4x4<> GetOrthographicMatrix( const float& left, const float& right, const float& bottom, const float& top, const float& nearPlane, const float& farPlane ) override;

	private:

		std::list< std::weak_ptr<Model> > m_RenderList;
		GLFWwindow* m_Window;
		double m_LastTime;
		float m_DeltaTime;
	};

}