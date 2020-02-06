#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Tiger {

	class Layer
	{
	public:
		Layer(std::string debugName = "Layer") : debugName(debugName) {}
		virtual ~Layer() = default;

		virtual void onUpdate() = 0;
		virtual void onAttach() = 0;
		virtual void onDetach() = 0;
		virtual void onEvent(Event& event) = 0;
		virtual void onDebugGUIRender() = 0;
	protected:
		std::string debugName;
	};

}

