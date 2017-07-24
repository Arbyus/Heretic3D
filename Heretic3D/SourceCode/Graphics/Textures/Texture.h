//#pragma once
//
//#include <functional>
//#include <memory>
//
//namespace Heretic3D
//{
//
//	class Texture_interface;
//
//	class Texture
//	{
//	public:
//
//		Texture( std::shared_ptr<Texture_interface> );
//
//		static std::function<std::shared_ptr<Heretic3D::Texture>( const std::string& imagePath )> CreateTexture;
//
//		void LoadTexture( );
//
//
//	private:
//
//		std::shared_ptr<Texture_interface> m_Pimpl;
//	};
//
//}