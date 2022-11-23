#include "rtspch.h"

#include "LayerManager.h"
#include "Application.h"

std::unordered_map<std::string, std::shared_ptr<Layer>> LayerManager::m_Storage = std::unordered_map<std::string, std::shared_ptr<Layer>>();
std::list<std::shared_ptr<Layer>> LayerManager::m_Stack = std::list<std::shared_ptr<Layer>>();
std::queue<std::pair<LayerOp, std::shared_ptr<Layer>>> LayerManager::m_LayerOpQueue = std::queue<std::pair<LayerOp, std::shared_ptr<Layer>>>();

void LayerManager::PushLayerP(const std::string& name)
{
	auto it = m_Storage.find(name);
	if (it == m_Storage.end())
	{
		LOG_WARN("Failed to find and push Layer '{}'", name);
		return;
	}
	m_Stack.push_back(it->second);
	it->second->OnPush();
}

void LayerManager::PushLayerP(const std::shared_ptr<Layer> layer)
{
	m_Stack.push_back(layer);
	layer->OnPush();
}

void LayerManager::PopLayerP()
{
	m_Stack.back()->OnPop();
	m_Stack.pop_back();
}

void LayerManager::PopLayerP(std::shared_ptr<Layer> layer)
{
	auto it = std::find(m_Stack.begin(), m_Stack.end(), layer);
	(*it)->OnPop();
	m_Stack.erase(it);
}

void LayerManager::AddLayer(const std::string& name, std::shared_ptr<Layer> layer)
{
	m_Storage[name] = layer;
	layer->OnCreate();
	auto window = Application::GetInstance()->GetWindow();
	layer->OnResize(window->GetWindowWidth(), window->GetWindowHeight());
}

void LayerManager::PushLayer(const std::string& name)
{
	auto it = m_Storage.find(name);
	if (it == m_Storage.end())
	{
		LOG_WARN("Failed to find and push Layer '{}'", name);
		return;
	}
	m_LayerOpQueue.emplace(LayerOp::Push, it->second);
}

void LayerManager::PushLayer(std::shared_ptr<Layer> layer)
{
	m_LayerOpQueue.emplace(LayerOp::Push, layer);
}

void LayerManager::PopLayer()
{
	m_LayerOpQueue.emplace(LayerOp::Pop, nullptr);
}

void LayerManager::PopLayer(std::shared_ptr<Layer> layer)
{
	m_LayerOpQueue.emplace(LayerOp::Pop, layer);
}

void LayerManager::SwitchTo(const std::string& name)
{
	auto it = m_Storage.find(name);
	if (it == m_Storage.end())
	{
		LOG_WARN("Failed to find and switch to Layer '{}'", name);
		return;
	}
	LOG_TRACE("Switching to '{}'", name);
	SwitchTo(it->second);
}

void LayerManager::SwitchTo(std::shared_ptr<Layer> layer)
{
	Clear();
	PushLayer(layer);
}

void LayerManager::Clear()
{
	m_LayerOpQueue.emplace(LayerOp::Clear, nullptr);
}

std::shared_ptr<Layer> LayerManager::GetLayer(const std::string& name)
{
	auto it = m_Storage.find(name);
	if (it == m_Storage.end())
	{
		LOG_WARN("Could not find Layer '{}'", name);
		return nullptr;
	}
	return it->second;
}

void LayerManager::DeleteLayer(const std::string& name)
{
	auto it = m_Storage.find(name);
	if (it == m_Storage.end())
	{
		LOG_WARN("Could not find and delete Layer '{}'", name);
		return;
	}
	it->second->OnDelete();
	m_Storage.erase(it);
}

void LayerManager::ProcessLayerOpQueue()
{
	while (!m_LayerOpQueue.empty())
	{
		auto [op, layer] = m_LayerOpQueue.front();
		m_LayerOpQueue.pop();
		if (op == LayerOp::Push)
		{
			m_Stack.push_back(layer);
			layer->OnPush();
			continue;
		}

		if (op == LayerOp::Clear)
		{
			for (auto it = m_Stack.rbegin(); it != m_Stack.rend(); ++it)
			{
				(*it)->OnPop();
			}
			m_Stack.clear();
			continue;
		}

		if (layer == nullptr)
		{
			m_Stack.back()->OnPop();
			m_Stack.pop_back();
			continue;
		}
		
		layer->OnPop();
		m_Stack.remove(layer);
	}
}
