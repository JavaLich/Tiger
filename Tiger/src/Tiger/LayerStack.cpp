#include "LayerStack.h"

namespace Tiger {

	LayerStack::LayerStack()
	{

	}

	LayerStack::~LayerStack()
	{	
		
	}

	void LayerStack::push(Layer* layer)
	{
		if (overlayIndex == -1) {
			stack.emplace(overlayBottom(), layer);
			overlayIndex++;
		}
		else stack.emplace_back(layer);
		layer->onAttach();
	}

	void LayerStack::pushOverlay(Layer* layer)
	{
		stack.emplace_back(layer);
		if (overlayIndex == -1) overlayIndex = stack.size() - 1;
		layer->onAttach();
	}

	void LayerStack::pop(Layer* layer)
	{
		auto it = std::find(begin(), end(), layer);
		if(overlayIndex!=-1) auto it = std::find(begin(), overlayBottom(), layer);
		if (it != end()) {
			layer->onDetach();
			stack.erase(it);
			overlayIndex--;
		}
	}

	void LayerStack::popOverlay(Layer* layer)
	{
		if (overlayIndex == -1)return;
		auto it = std::find(overlayBottom(), end(), layer);
		if (it != end()) {
			layer->onDetach();
			stack.erase(it);
		}
	}

	void LayerStack::shutdown()
	{
		for (Layer* layer : stack) {
			layer->onDetach();
			delete layer;
		}
		TG_INFO("LayerStack shutdown");
	}

	std::vector<Layer*>::iterator LayerStack::begin()
	{
		return stack.begin();
	}

	std::vector<Layer*>::iterator LayerStack::end()
	{
		return stack.end();
	}

	std::vector<Layer*>::iterator LayerStack::overlayBottom()
	{
		return stack.begin()+overlayIndex;
	}

}