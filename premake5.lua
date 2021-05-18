workspace "Pumpkin"
	architecture "x64"

	configurations {
		
		"Debug",
		"Release",
		"Dist"

	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pumpkin"
	location "Pumpkin"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {

			"PK_PLATFORM_WINDOWS",
			"PK_BUILD_DLL"
		}

		postbuildcommands {
		
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
	files {
		
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"Pumpkin/vendor/spdlog/include;",
		"Pumpkin/src"
	}

	links {
		
		"Pumpkin"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {

			"PK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		optimize "On"