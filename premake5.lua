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

project "KRYT"
	location "KRYT"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include;"
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
		"KRYT/vendor/spdlog/include;",
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