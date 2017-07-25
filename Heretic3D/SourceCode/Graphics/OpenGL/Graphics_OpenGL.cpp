#include "Graphics_OpenGL.hpp"

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "../../Input/InputStructs.h"

#undef CreateWindow

namespace Heretic3D
{
	namespace
	{
		keyCallbackFunc m_OnKeyPress;

		void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods )
		{
			//the value of our keypresses match glfw
			if ( !m_OnKeyPress )
			{
				throw std::exception( "Key callback function not specified" );
			}


			m_OnKeyPress( static_cast<KeyInput>(key), static_cast<KeyAction>( action ) );
		}
	}

	Graphics_OpenGL::Graphics_OpenGL( )
	{
		m_LastTime = glfwGetTime();
	}

	void Graphics_OpenGL::Draw( const unsigned int shaderID )
	{
		const auto& renderList = m_RenderMapByShaderID.at( shaderID );

		for ( auto& model : renderList )
		{
			for ( auto& mesh : model.lock( )->GetMesh( ) )
			{

				auto buffInfo = mesh.GetBufferInformation( );
				auto modelInfo = mesh.GetModelInformation( );

				// Bind appropriate textures
				GLuint diffuseNr = 1;
				GLuint specularNr = 1;
				for ( GLuint i = 0; i < modelInfo.textures.size( ); i++ )
				{
					glActiveTexture( GL_TEXTURE0 + i ); // Active proper texture unit before binding
														// Retrieve texture number (the N in diffuse_textureN)
														// Now set the sampler to the correct texture unit
					glUniform1i( glGetUniformLocation( shaderID, "diffuseTexture" ), i );
					// And finally bind the texture
					glBindTexture( GL_TEXTURE_2D, model.lock( )->GetTextures( )[ i ].id );
				}
				// Draw mesh
				glBindVertexArray( buffInfo.vAO );
				glDrawElements( GL_TRIANGLES, modelInfo.indices.size( ), GL_UNSIGNED_INT, 0 );
				glBindVertexArray( 0 );

				// Always good practice to set everything back to defaults once configured.
				for ( GLuint i = 0; i < modelInfo.textures.size( ); i++ )
				{
					glActiveTexture( GL_TEXTURE0 + i );
					glBindTexture( GL_TEXTURE_2D, 0 );
				}
			}
		}
	}

	void Graphics_OpenGL::SetupModel( std::weak_ptr<Model> modelToSetup, const unsigned int shaderID )
	{
		for ( auto& mesh : modelToSetup.lock( )->GetMesh( ) )
		{

			auto buffInfo = mesh.GetBufferInformation( );
			auto modelInfo = mesh.GetModelInformation( );

			glGenVertexArrays( 1, &buffInfo.vAO );
			glGenBuffers( 1, &buffInfo.vBO );
			glGenBuffers( 1, &buffInfo.eBO );

			glBindVertexArray( buffInfo.vAO );
			// Load data into vertex buffers
			glBindBuffer( GL_ARRAY_BUFFER, buffInfo.vBO );
			// A great thing about structs is that their memory layout is sequential for all its items.
			// The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
			// again translates to 3/2 floats which translates to a byte array.
			glBufferData( GL_ARRAY_BUFFER, modelInfo.vertices.size( ) * sizeof( Vertex ), &modelInfo.vertices[ 0 ], GL_STATIC_DRAW );

			glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffInfo.eBO );
			glBufferData( GL_ELEMENT_ARRAY_BUFFER, modelInfo.indices.size( ) * sizeof( GLuint ), &modelInfo.indices[ 0 ], GL_STATIC_DRAW );

			// Set the vertex attribute pointers
			// Vertex Positions
			glEnableVertexAttribArray( 0 );
			glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid* )0 );
			// Vertex Normals
			glEnableVertexAttribArray( 1 );
			glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid* )offsetof( Vertex, Normal ) );
			// Vertex Texture Coords
			glEnableVertexAttribArray( 2 );
			glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid* )offsetof( Vertex, TexCoords ) );

			glBindVertexArray( 0 );
		}

		if ( m_RenderMapByShaderID.find( shaderID ) == m_RenderMapByShaderID.end( ) )
		{
			m_RenderMapByShaderID.insert( std::pair<unsigned int, std::vector< std::weak_ptr<Model> > >( shaderID, { modelToSetup } ) );
		}
		else
		{
			m_RenderMapByShaderID.at( shaderID ).push_back( modelToSetup );
		}

	}

	int Graphics_OpenGL::CreateWindow( )
	{
		// Initialise GLFW
		if ( !glfwInit( ) )
		{
			fprintf( stderr, "Failed to initialize GLFW\n" );
			return -1;
		}
		glfwWindowHint( GLFW_SAMPLES, 4 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
		glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
		glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

		GLFWmonitor* monitor = glfwGetPrimaryMonitor( );
		const GLFWvidmode* mode = glfwGetVideoMode( monitor );
		glfwWindowHint( GLFW_RED_BITS, mode->redBits );
		glfwWindowHint( GLFW_GREEN_BITS, mode->greenBits );
		glfwWindowHint( GLFW_BLUE_BITS, mode->blueBits );
		glfwWindowHint( GLFW_REFRESH_RATE, mode->refreshRate );
		//window = glfwCreateWindow(mode->width, mode->height, "My Title", monitor, NULL);
		m_Window = glfwCreateWindow( 1280, 720, "My Title", NULL, NULL );

		if ( m_Window == NULL ) {
			fprintf( stderr, "Failed to open GLFW window. \n" );
			glfwTerminate( );
			return -1;
		}
		glfwMakeContextCurrent( m_Window );
		if ( !gladLoadGLLoader( ( GLADloadproc )glfwGetProcAddress ) ) {
			return -1;
		}
		glfwSetInputMode( m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED );
		glfwSetCursorPos( m_Window, 0, 0 );
		glViewport( 0, 0, 1280, 720 );
		glEnable( GL_DEPTH_TEST );
		glDepthFunc( GL_LESS );

		glfwSetKeyCallback( m_Window, key_callback );

		return 0;
	}

	Vector2<double> Graphics_OpenGL::GetCursorPositionOnScreen( )
	{
		Vector2<double> returnVal;
		glfwGetCursorPos( m_Window, &returnVal.x, &returnVal.y );
		return returnVal;
	}

	bool Graphics_OpenGL::WantsToClose( )
	{
		const auto escapePressed = glfwGetKey( m_Window, GLFW_KEY_ESCAPE ) == GLFW_PRESS;
		const auto windowShouldClose = glfwWindowShouldClose( m_Window ) != 0;

		return escapePressed || windowShouldClose;
	}

	void Graphics_OpenGL::BeginFrame( )
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		double currentTime = glfwGetTime( );

		m_DeltaTime = float( currentTime - m_LastTime );

		m_LastTime = currentTime;
	}

	void Graphics_OpenGL::EndFrame( )
	{
		// Swap buffers
		glfwSwapBuffers( m_Window );
		glfwPollEvents( );
	}

	void Graphics_OpenGL::SetKeyCallback( keyCallbackFunc callbackFunc )
	{
		m_OnKeyPress = callbackFunc;
	}

	unsigned int Graphics_OpenGL::LoadTexture( const std::string & imagePath )
	{
	
		int width, height;
		unsigned char* image;
		int comp;

		image = stbi_load( imagePath.c_str( ), &width, &height, &comp, STBI_rgb_alpha );

		GLuint textureID;

		if ( image )
		{
		
			glGenTextures( 1, &textureID );

			// Bind the texture to a name
			glBindTexture( GL_TEXTURE_2D, textureID );

			// Set texture clamping method
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );

			// Set texture interpolation method to use linear interpolation (no MIPMAPS)
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

			if ( comp == 3 )
			{
				glTexImage2D( GL_TEXTURE_2D, 
					0,
					GL_RGB, 
					width, 
					height, 
					0, 
					GL_RGB,
					GL_UNSIGNED_BYTE, 
					image );
			}
			else if ( comp == 4 )
			{
				glTexImage2D( GL_TEXTURE_2D, 
					0, 
					GL_RGBA, 
					width,
					height,
					0,
					GL_RGBA,
					GL_UNSIGNED_BYTE, 
					image );
			}
		}
		else
		{
			MessageBox( NULL, TEXT( "error" ), TEXT( "error" ), MB_OK | MB_ICONINFORMATION );

		}

		std::cout << "Texture creation successful." << std::endl;

		return textureID;
	}

	void Graphics_OpenGL::Cleanup( )
	{
		glfwTerminate( );
	}

}