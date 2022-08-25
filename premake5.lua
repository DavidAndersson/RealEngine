workspace "RealEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RealEngine" 
	location "RealEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/Vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"RE_PLATFORM_WINDOWS",
			"RE_BUILD_DLL"
		}


		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RE_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RE_Dist"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"RealEngine/Vendor/spdlog/include",
		"RealEngine/src"
	}

	links{
		"RealEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"RE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "RE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RE_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RE_Dist"
		symbols "On"