#include "Graphics.h"
#include "Graphics_interface.hpp"


namespace Heretic3D
{
		
	decltype( Graphics::CreateGraphicsImplementation ) Graphics::CreateGraphicsImplementation;
	
	Graphics::Graphics( std::shared_ptr<Graphics_interface> impl )
	{
		m_Pimpl = impl;
	}
	
	void Graphics::Draw( const unsigned int shaderID )
	{
		m_Pimpl->Draw( shaderID );
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

	void Graphics::BeginFrame( )
	{
		m_Pimpl->BeginFrame( );
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

	void Graphics::Cleanup( )
	{
		m_Pimpl->Cleanup( );
	}

	Matrix4x4<> Graphics::GetPerspectiveMatrix( const float & fovy, const float & aspectRatio, const float & nearPlane, const float & farPlane )
	{
		return m_Pimpl->GetPerspectiveMatrix( fovy, aspectRatio, nearPlane, farPlane );
	}

	HERETIC3D Matrix4x4<> Graphics::GetLookAtMatrix( const Vector3<> & eyePos, const Vector3<> & centerPos, const Vector3<> & upPos )
	{
		return m_Pimpl->GetLookAtMatrix( eyePos, centerPos, upPos );
	}

	HERETIC3D Matrix4x4<> Graphics::GetOrthographicMatrix( const float & left, const float & right, const float & bottom, const float & top, const float & nearPlane, const float & farPlane )
	{
		return m_Pimpl->GetOrthographicMatrix( left, right, bottom, top, nearPlane, farPlane );
	}

}