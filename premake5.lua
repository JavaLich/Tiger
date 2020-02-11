workspace "Tiger"
	architecture "x64"
	staticruntime "on"
	cppdialect "C++17"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	include "Tiger/vendor/GLFW"
	include "Tiger/vendor/imgui"
	include "Tiger/vendor/glad"

	project "Tiger"
		location "Tiger"
		kind "StaticLib"
		language "C++"

		pchheader "tgpch.h"
		pchsource "%{prj.name}/src/tgpch.cpp"

		forceincludes "tgpch.h"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"%{prj.name}/vendor/imgui",
			"%{prj.name}/vendor/spdlog/include",
			"%{prj.name}/vendor/GLFW/include",
			"%{prj.name}/vendor/glad/include",
			"%{prj.name}/vendor/glm",
			"%{prj.name}/src"
		}

		links "GLFW"
		links "imgui"
		links "Glad"

		filter "system:windows"
			systemversion "latest"

		defines{
			"TG_PLATFORM_WINDOWS",
			"TG_STATIC",
			"_CRT_NONSTDC_NO_DEPRECATE",
			"_CRT_SECURE_NO_DEPRECATE"
		}
		
		filter "configurations:Debug"
			defines "TG_DEBUG"
			symbols "on"
		
		filter "configurations:Release"
			defines "TG_RELEASE"
			optimize "on"
		
		filter "configurations:Dist"
			defines "TG_DIST"
			optimize "on"
		
	project "Game"
		location "Game"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"Tiger/vendor",
			"Tiger/vendor/spdlog/include",
			"%{prj.name}/vendor/glm",
			"Tiger/src"
		}

		links "Tiger"

		filter "system:windows"
			systemversion "latest"

			defines{
				"TG_PLATFORM_WINDOWS",
				"TG_STATIC"
			}
			
		filter "configurations:Debug"
			defines "TG_DEBUG"
			symbols "on"
			
		filter "configurations:Release"
			defines "TG_RELEASE"
			optimize "on"
			
		filter "configurations:Dist"
			defines "TG_DEBUG"
			optimize "on"