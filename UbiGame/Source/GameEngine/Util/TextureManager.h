#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player,
			Player1,
			Player2,
			Player3,
			Background,
			Loading,
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture) {
		case eTexture::Player: return "gears-blue.png";
		case eTexture::Player2: return "gears-red.png";
		case eTexture::Player3: return "gears-yellow.png";
		case eTexture::Background: return "background.png";
		case eTexture::Loading: return "mp3logo.jpg";
		}
		return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	static sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		return sf::Vector2f(-1.f, -1.f);
	}
}

