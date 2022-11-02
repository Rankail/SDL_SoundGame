#include "rtspch.h"

#include "TextureLib.h"

#include "Texture.h"

std::unordered_map<std::string, std::shared_ptr<Texture>> TextureLib::m_Textures = std::unordered_map<std::string, std::shared_ptr<Texture>>();

bool TextureLib::AddTexture(const std::string& path, const std::string& name)
{
	auto tex = LoadTexture(path);
	if (tex == nullptr) return false;

	if (name != "")
	{
		return AddTexture(tex, name);
	}

	auto lastSlash = name.find_last_of("/\\");
	lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
	auto lastDot = name.rfind('.');
	auto count = lastDot == std::string::npos ? path.size() - lastSlash : lastDot - lastSlash;
	return AddTexture(tex, path.substr(lastSlash, count));
}

bool TextureLib::AddTexture(std::shared_ptr<Texture> texture, const std::string& name)
{
	m_Textures[name] = texture;
	return true;
}

std::shared_ptr<Texture> TextureLib::LoadTexture(const std::string& path)
{
	return std::make_shared<Texture>(path);
}

std::shared_ptr<Texture> TextureLib::GetTexture(const std::string& name)
{
	auto it = m_Textures.find(name);
	if (it == m_Textures.end())
	{
		LOG_WARN("Failed to find Texture '{}'", name);
		return nullptr;
	}

	return it->second;
}

bool TextureLib::RemoveTexture(const std::string& name)
{
	auto it = m_Textures.find(name);
	if (it == m_Textures.end())
	{
		LOG_WARN("Failed to find and remove Texture '{}'", name);
		return false;
	}

	m_Textures.erase(it);
	return true;
}
