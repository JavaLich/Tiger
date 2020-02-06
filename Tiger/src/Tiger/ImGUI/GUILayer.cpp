#include "GUILayer.h"

/*
-------------------------------------------------------
----------------------TEMPORARY------------------------
-------------------------------------------------------
*/
#include "glad/glad.h"
#include "GLFW/glfw3.h"
/*
-------------------------------------------------------
----------------------TEMPORARY------------------------
-------------------------------------------------------
*/
#include "Tiger/Application.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

namespace Tiger {
	GUILayer::GUILayer() : Layer("GUI Layer")
	{
		
	}

	GUILayer::~GUILayer()
	{
	}

	void GUILayer::onUpdate()
	{
	}

	void GUILayer::onAttach()
	{
		/*
		-------------------------------------------------------
		----------------------TEMPORARY------------------------
		-------------------------------------------------------
		*/
		TG_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Glad failed to initalize");
		/*
		-------------------------------------------------------
		----------------------TEMPORARY------------------------
		-------------------------------------------------------
		*/

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::get();
		ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(app.getWindow().getNativeWindow()), true);
		ImGui_ImplOpenGL3_Init("#version 410");
		ImGui::StyleColorsDark();
	}

	void GUILayer::onDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		TG_INFO("GUILayer shutdown");
	}

	void GUILayer::onEvent(Event& event)
	{
	}

	void GUILayer::onDebugGUIRender()
	{
		ImGui::ShowDemoWindow();
	}

	void GUILayer::startRender()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void GUILayer::endRender()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

}