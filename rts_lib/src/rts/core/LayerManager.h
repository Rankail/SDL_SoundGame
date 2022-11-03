#pragma once

#include "Layer.h"
#include <queue>

enum class LayerOp
{
	Push, Pop, Clear
};

class LayerManager
{
private:
	static void PushLayerP(const std::string& name);
	static void PushLayerP(const std::shared_ptr<Layer> layer);
	static void PopLayerP();
	static void PopLayerP(std::shared_ptr<Layer> layer);

public:
	LayerManager() = delete;
	virtual ~LayerManager() = delete;
	LayerManager(const LayerManager& other) = delete;

	static void AddLayer(const std::string& name, std::shared_ptr<Layer> layer);
	
	static void PushLayer(const std::string& name);
	static void PushLayer(std::shared_ptr<Layer> layer);

	static void PopLayer();
	static void PopLayer(std::shared_ptr<Layer> layer);

	static void SwitchTo(const std::string& name);
	static void SwitchTo(std::shared_ptr<Layer> layer);

	static void Clear();
	
	static std::shared_ptr<Layer> GetLayer(const std::string& name);
	
	static void DeleteLayer(const std::string& name);

	static void ProcessLayerOpQueue();

	static bool Empty() { return m_Stack.empty(); }

	static std::list<std::shared_ptr<Layer>>::iterator begin() { return m_Stack.begin(); }
	static std::list<std::shared_ptr<Layer>>::iterator end() { return m_Stack.end(); }
	static std::list<std::shared_ptr<Layer>>::reverse_iterator rbegin() { return m_Stack.rbegin(); }
	static std::list<std::shared_ptr<Layer>>::reverse_iterator rend() { return m_Stack.rend(); }

private:
	static std::unordered_map<std::string, std::shared_ptr<Layer>> m_Storage;
	static std::list<std::shared_ptr<Layer>> m_Stack;
	static std::queue<std::pair<LayerOp, std::shared_ptr<Layer>>> m_LayerOpQueue;
};