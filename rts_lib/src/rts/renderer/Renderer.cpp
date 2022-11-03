#include "rtspch.h"
#include "Renderer.h"

#include "rts/core/Application.h"
#include "rts/core/Exceptions.h"
#include "rts/renderer/Texture.h"
#include "rts/renderer/Text.h"

struct RendererData
{
	SDL_Renderer* renderer = nullptr;
	Color clearColor = Colors::BLACK;
};

static RendererData s_Data;

void Renderer::Init()
{
	s_Data.renderer = SDL_CreateRenderer(Application::GetInstance()->GetWindow()->GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED);
	if (s_Data.renderer == NULL)
	{
		throw InitException("Failed to create Renderer", SDL_GetError());
	}
}

void Renderer::Shutdown()
{
	SDL_DestroyRenderer(s_Data.renderer);
}

void Renderer::Clear()
{
	SetColor(s_Data.clearColor);
	SDL_RenderClear(s_Data.renderer);
}

void Renderer::Present()
{
	SDL_RenderPresent(s_Data.renderer);
}

void Renderer::SetClearColor(Color color)
{
	s_Data.clearColor = color;
}

void Renderer::SetColor(Color color)
{
	SDL_SetRenderDrawColor(s_Data.renderer, color.r, color.g, color.b, color.a);
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(s_Data.renderer, r, g, b, a);
}

void Renderer::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h)
{
	SDL_RenderDrawRect(s_Data.renderer, new SDL_Rect{x, y, w, h});
}

void Renderer::FillRect(int32_t x, int32_t y, int32_t w, int32_t h)
{
	SDL_RenderFillRect(s_Data.renderer, new SDL_Rect{x, y, w, h});
}

void Renderer::RenderTexture(std::shared_ptr<Texture> tex, int32_t x, int32_t y)
{
	SDL_Rect dstRect = { x, y, tex->GetWidth(), tex->GetHeight() };
	SDL_RenderCopy(s_Data.renderer, tex->GetTexture(), NULL, &dstRect);
}

void Renderer::RenderTexture(std::shared_ptr<Texture> tex, int32_t x, int32_t y, int32_t w, int32_t h)
{
	SDL_Rect dstRect = { x, y, w, h };
	SDL_RenderCopy(s_Data.renderer, tex->GetTexture(), NULL, &dstRect);
}

void Renderer::RenderText(std::shared_ptr<Text> text)
{
	auto tex = text->GetTexture();
	SDL_Rect dstRect = { text->GetTopLeftX(), text->GetTopLeftY(), text->GetWidth(), text->GetHeight()};
	SDL_RenderCopy(s_Data.renderer, tex->GetTexture(), NULL, &dstRect);
}

SDL_Texture* Renderer::CreateTextureFromSurface(SDL_Surface* surface)
{
	SDL_Texture* tex = SDL_CreateTextureFromSurface(s_Data.renderer, surface);
	if (tex == NULL)
	{
		LOG_WARN("Failed to create Texture from Surface");
		SDL_FreeSurface(surface);
		return nullptr;
	}
	return tex;
}
