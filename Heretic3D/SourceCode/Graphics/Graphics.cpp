#include "Graphics.h"
#include "Graphics_interface.hpp"


namespace Heretic3D
{
		
	decltype( Graphics::CreateGraphicsImplementation ) Graphics::CreateGraphicsImplementation;
	decltype( Graphics::CreateTexture ) Graphics::CreateTexture;
	
	
	Graphics::Graphics( std::shared_ptr<Graphics_interface> impl )
	{
		m_Pimpl = impl;
	}
	
	void Graphics::Draw( const unsigned int shaderID )
	{
		m_Pimpl->Draw( shaderID );
	}
	
	void Graphics::SetupModel( std::weak_ptr<Model> modelToSetup )
	{
		m_Pimpl->SetupModel( modelToSetup,0 );
	}

	int Graphics::CreateWindow( )
	{
		return m_Pimpl->CreateWindow( );
	}

	Vector2<double> Graphics::GetCursorPositionOnScreen( )
	{
		return m_Pimpl->GetCursorPositionOnScreen( );
	}

	bool Graphics::WantsToClose( )
	{
		return m_Pimpl->WantsToClose( );
	}

	void Graphics::EndFrame( )
	{
		m_Pimpl->EndFrame( );
	}

	void Graphics::SetKeyCallback( keyCallbackFunc callbackFunc )
	{
		m_Pimpl->SetKeyCallback( callbackFunc );
	}

	unsigned int Graphics::LoadTexture( const std::string & imagePath )
	{
		return m_Pimpl->LoadTexture( imagePath );
	}

}