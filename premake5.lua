
workspace "KRYT"
	architecture"x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "KRYT/vendor/GLFW/include"

include "KRYT/vendor/GLFW"

project "KRYT"
	location "KRYT"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "KRpch.h"
	pchsource "KRYT/src/KRpch.cpp"
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KR_PLATFORM_WINDOWS",
			"KR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KR_DEFAULT"
		symbols "On"

	filter "configurations:Release"
		defines "KR_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "KR_DIST"
		symbols "On"

	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"KRYT/vendor/spdlog/include",
		"KRYT/src"
	}

	links
	{
		"KRYT"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"KR_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "KR_DEFAULT"
		symbols "On"

	filter "configurations:Release"
		defines "KR_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "KR_DIST"
		symbols "On"