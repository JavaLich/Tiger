#pragma once

#include "Tiger/Core.h"
#include "Tiger/Layer.h"

namespace Tiger {

	class GUILayer : public Layer
	{
	public:
		GUILayer();
		virtual ~GUILayer();

		virtual void onUpdate();
		virtual void onAttach();
		virtual void onDetach();
		virtual void onEvent(Event& event);
		virtual void onDebugGUIRender();

		void startRender();
		void endRender();
	};

}

