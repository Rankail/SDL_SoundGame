#pragma once

#include "rts/widgets/Button.h"

#include <vector>

class ButtonGroupV : public Drawable
{
private:
	void CalculateHeight();

protected:
	virtual void SizePosUpdateAfter() override;

public:
	ButtonGroupV();
	virtual ~ButtonGroupV();

	void AddButton(const std::string& name, std::shared_ptr<Button> button);
	void AddButton(std::shared_ptr<Button> button);

	std::shared_ptr<Button> GetButton(const std::string& name);

	void SetGap(int gap);

	ButtonState GetButtonStatus(const std::string& name);
	bool IsButtonHovered(const std::string& name);

	void UpdateLayout();

	virtual void OnEvent(Event& e);
	virtual void Update(float dt) override;
	virtual void Render() override;

private:
	std::unordered_map<std::string, std::shared_ptr<Button>> m_Names;
	std::vector<std::shared_ptr<Button>> m_Buttons;
	int m_Gap = 0;
};