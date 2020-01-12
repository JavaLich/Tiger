workspace "Tiger"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "Tiger"
		location "Tiger"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs{
			"%{prj.name}/vendor/spdlog/include",
			"%{prj.name}/src"
		}

		filter "system:windows"
			cppdialect "c++17"
			staticruntime "On"
			systemversion "latest"

			defines{
				"TG_PLATFORM_WINDOWS",
				"TG_BUILD_DLL"
			}

			postbuildcommands{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
			}
		
		filter "configurations:Debug"
			defines "TG_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "TG_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
			defines "TG_DEBUG"
			optimize "On"
		
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
		"Tiger/vendor/spdlog/include",
		"Tiger/src"
	}

	links "Tiger"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"TG_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "TG_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "TG_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "TG_DEBUG"
		optimize "On"