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
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigViewportsNoAutoMerge = true;
		//io.ConfigViewportsNoTaskBarIcon = true;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
		Application& app = Application::get();
		ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(app.getWindow().getNativeWindow()), true);
		ImGui_ImplOpenGL3_Init("#version 410");
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
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}

	}

}