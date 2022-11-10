#include "rtspch.h"

#include "Texture.h"
#include "rts/renderer/Renderer.h"

Texture::Texture()
{ }

Texture::Texture(const std::string& path)
{
	LoadTexture(path);
}

Texture::Texture(SDL_Surface* surface)
{
	auto tex = Renderer::CreateTextureFromSurface(surface);
	m_Texture = tex;
	SDL_QueryTexture(tex, NULL, NULL, &m_Width, &m_Height);
}

Texture::~Texture()
{
	SDL_DestroyTexture(m_Texture);
}

SDL_Texture* Texture::LoadTexture(const std::string& path)
{
	SDL_Texture* tex = NULL;
	SDL_Surface* tempSurf = IMG_Load(path.c_str());
	if (tempSurf == NULL) {
		LOG_WARN("Failed to load Texture from '{}'", path);
		SDL_FreeSurface(tempSurf);
		return nullptr;
	}
	tex = Renderer::CreateTextureFromSurface(tempSurf);
	if (tex == nullptr) return nullptr;
	
	m_Texture = tex;
	SDL_QueryTexture(tex, NULL, NULL, &m_Width, &m_Height);

	return tex;
}

void Texture::SetTexture(SDL_Surface* surf)
{
	auto tex = Renderer::CreateTextureFromSurface(surf);
	m_Texture = tex;
	SDL_QueryTexture(tex, NULL, NULL, &m_Width, &m_Height);
}

void Texture::Render(int32_t x, int32_t y)
{
	if (!m_Texture) return;
	Renderer::RenderTexture(m_Texture, x, y, m_Width, m_Height);
}

void Texture::Render(int32_t x, int32_t y, int32_t w, int32_t h)
{
	if (!m_Texture) return;
	Renderer::RenderTexture(m_Texture, x, y, w, h);
}
