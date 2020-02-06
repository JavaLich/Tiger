#pragma once

#include "Core.h"
#include "Layer.h"

namespace Tiger {

	class LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void push(Layer* layer);
		void pushOverlay(Layer* layer);
		void pop(Layer* layer);
		void popOverlay(Layer *layer);
		void shutdown();
		
		std::vector<Layer*>::iterator overlayBottom();

		std::vector<Layer*>::iterator begin();
		std::vector<Layer*>::iterator end();
		std::vector<Layer*>::reverse_iterator rbegin() { return stack.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return stack.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return stack.begin(); }
		std::vector<Layer*>::const_iterator end()	const { return stack.end(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return stack.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return stack.rend(); }
	private:
		size_t overlayIndex = -1;
		std::vector<Layer*> stack;
	};

}