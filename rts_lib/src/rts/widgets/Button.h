#pragma once

#include "rts/widgets/Text.h"
#include "rts/events/MouseEvent.h"
#include "rts/renderer/FontLib.h"

#include "rts/widgets/AbstractButton.h"

class Button : public AbstractButton
{
protected:
	virtual void SizePosUpdateBefore() override;
	virtual void SizePosUpdateAfter() override;

public:
	Button();
	virtual ~Button();
	
	virtual void SetProperties(const ButtonProperties& properties) override;

	void SetBackgroundColor(Color color);
	void SetActiveBackgroundColor(Color color);

	virtual void Render() override;

private:
	const ButtonType m_Type = ButtonType::BASIC;

	Color m_BgColor = Colors::NONE;
	Color m_BgActive = Colors::NONE;
};