project "Project"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs
    {
        "../EasyS/src",
        "../EasyS/vendor/spdlog/include"
    }

    links
    {
        "EasyS"
    }

    defines
    {
        "EZ_PLATFORM_WINDOWS",
    }

    filter {"configurations:Debug"}
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"

    filter {"configurations:Release"}
        buildoptions "/MT"
        runtime "Release"
        optimize "on"