#pragma once

#include "rts/widgets/AbstractButton.h"

class TextureButton : public AbstractButton
{
private:
	using AbstractButton::SetSize;
	using AbstractButton::SetWidth;
	using AbstractButton::SetHeight;

protected:
	virtual void SizePosUpdateBefore() override;
	virtual void SizePosUpdateAfter() override;

public:
	TextureButton();
	virtual ~TextureButton();

	virtual void SetProperties(const ButtonProperties& properties) override;

	void SetTexture(std::shared_ptr<Texture> texture);
	void SetTexture(const std::string& file);
	void SetTextureActive(std::shared_ptr<Texture> texture);
	void SetTextureActive(const std::string& file);

	/*virtual void SetSize(int32_t w, int32_t h) override { LOG_WARN("Funtion should not be called"); }
	virtual void SetWidth(int32_t w) override { LOG_WARN("Funtion should not be called"); }
	virtual void SetHeight(int32_t h) override { LOG_WARN("Funtion should not be called"); }*/

	virtual int32_t GetWidth() const { return m_Texture->GetWidth(); }
	virtual int32_t GetHeight() const { return m_Texture->GetHeight(); }

	virtual void Render() override;

private:
	const ButtonType m_Type = ButtonType::TEXTURE;

	std::shared_ptr<Texture> m_Texture;
	std::shared_ptr<Texture> m_TextureActive;
};