#include "rtspch.h"
#include "ButtonGroupV.h"

void ButtonGroupV::CalculateHeight()
{
	int totalHeight = 0;
	for (auto& button : m_Buttons) {
		totalHeight += button->GetHeight();
	}
	totalHeight += m_Gap * (m_Buttons.size() - 1);
	m_ObjHeight = totalHeight;
}

void ButtonGroupV::SizePosUpdateAfter()
{
	int off = 0;
	for (auto& button : m_Buttons) {
		button->SetPos(m_OTLX, m_OTLY + off);
		if (button->GetButtonType() != ButtonType::TEXTURE)
			button->SetWidth(m_ObjWidth);
		off += button->GetHeight() + m_Gap;
	}
}

ButtonGroupV::ButtonGroupV()
{
}

ButtonGroupV::~ButtonGroupV()
{
}

void ButtonGroupV::AddButton(const std::string& name, std::shared_ptr<AbstractButton> button)
{
	auto it = m_Names.find(name);
	if (it != m_Names.end() && it->second != button) {
		LOG_WARN("Button with name '{}' already existed an cant be accessed anymore", name);
	}
	m_Names[name] = button;
	AddButton(button);
}

void ButtonGroupV::AddButton(std::shared_ptr<AbstractButton> button)
{
	if (std::find(m_Buttons.begin(), m_Buttons.end(), button) != m_Buttons.end()) {
		LOG_WARN("Button was already added to Buttongroup");
	}
	m_Buttons.push_back(button);
	m_ObjWidth = std::max(m_ObjWidth, button->GetWidth());
	CalculateHeight();
	SizePosUpdate();
}

std::shared_ptr<AbstractButton> ButtonGroupV::GetButton(const std::string& name)
{
	auto it = m_Names.find(name);
	if (it == m_Names.end()) {
		LOG_WARN("Could not find button '{}'", name);
		return nullptr;
	}
	return it->second;
}

void ButtonGroupV::SetGap(int gap)
{
	m_Gap = gap;
	CalculateHeight();
	SizePosUpdate();
}

ButtonState ButtonGroupV::GetButtonStatus(const std::string& name)
{
	auto it = m_Names.find(name);
	if (it == m_Names.end()) {
		LOG_WARN("Tried to get state of non-existent button '{}'", name);
		return ButtonState::IDLE;
	}
	return it->second->GetStatus();
}

bool ButtonGroupV::IsButtonHovered(const std::string& name)
{
	auto it = m_Names.find(name);
	if (it == m_Names.end()) {
		LOG_WARN("Tried to get state of non-existent button '{}'", name);
		return false;
	}
	return it->second->IsHovered();
}

void ButtonGroupV::UpdateLayout()
{
	CalculateHeight();
	int max = 0;
	for (auto& button : m_Buttons) {
		max = std::max(max, button->GetWidth());
	}
	m_ObjWidth = max;
	SizePosUpdate();

}

void ButtonGroupV::OnEvent(Event& e)
{
	if ((e.GetCategoryFlags() & EventCategoryMouse) != 0) {
		for (auto& button : m_Buttons) {
			button->OnEvent(e);
		}
	}
}

void ButtonGroupV::Update(float dt)
{
	for (auto& button : m_Buttons) {
		button->Update(dt);
	}
}

void ButtonGroupV::Render()
{
	for (auto& button : m_Buttons) {
		button->Render();
	}
}
