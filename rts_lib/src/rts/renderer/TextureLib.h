#pragma once

#include <SDL.h>
#include <string>

class Texture;

class TextureLib
{
public:
	TextureLib() = delete;
	virtual ~TextureLib() = delete;
	TextureLib(const TextureLib& other) = delete;

	static bool AddTexture(const std::string& path, const std::string& name = "");
	static bool AddTexture(std::shared_ptr<Texture> texture, const std::string& name);

	static std::shared_ptr<Texture> LoadTexture(const std::string& path);

	static std::shared_ptr<Texture> GetTexture(const std::string& name);

	static bool RemoveTexture(const std::string& name);

private:
	static std::unordered_map<std::string, std::shared_ptr<Texture>> m_Textures;
};